using System;
using System.Collections.Generic;
using System.Text;

using XNAPhysX.Physics;
using XNAPhysX.Input;
using XNAPhysX.Graphics.DebugRenderer;
using XNAPhysX;

using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

using System.Diagnostics;

namespace Lesson207
{
    public class Lesson207Scene : PhysXScene
    {
        const float forceStrength = 35000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor sphere1, sphere2;

        Vector3 forceDirection = Vector3.Zero;
        bool forceMode = true;

        public Lesson207Scene() : base()
        {
            groundPlane = CreateGroundPlane();

            sphere1 = CreateSphere(new Vector3(0, 5, 0), 1f, 10);
            sphere1.RaiseBodyFlag(NxaBodyFlag.Kinematic);
            sphere2 = CreateSphere(new Vector3(0, 3, 0), 1f, 10);
            sphere2.SetLinearDamping(0.5f);

            actors.Add(groundPlane);
            actors.Add(sphere1);
            actors.Add(sphere2);

            NxaSphericalJoint joint = CreateSphericalJoint(sphere1, sphere2, new Vector3(0, 5, 0), Vector3.UnitY);
            
            selectedActor = sphere2;

            Console.WriteLine("Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down\n");
            Console.WriteLine("Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
            Console.WriteLine("Miscellaneous:\n --------------\n r = Select Next Actor\n f = Toggle Force Mode\n");
        }

        private NxaSphericalJoint CreateSphericalJoint(NxaActor a0, NxaActor a1, Vector3 globalAnchor, Vector3 globalAxis)
        {
            NxaSphericalJointDescription sphericalDesc = new NxaSphericalJointDescription();
            sphericalDesc.Actor[0] = a0;
            sphericalDesc.Actor[1] = a1;
            sphericalDesc.SetGlobalAnchor(globalAnchor);
            sphericalDesc.SetGlobalAxis(globalAxis);

            sphericalDesc.Flags |= NxaSphericalJointFlag.SwingLimitEnabled;
            sphericalDesc.SwingLimit.Value = (float)(0.3 * Math.PI);

            sphericalDesc.Flags |= NxaSphericalJointFlag.TwistLimitEnabled;
            sphericalDesc.TwistLimit.Low.Value = (float)(-0.05 * Math.PI);
            sphericalDesc.TwistLimit.High.Value = (float)(0.05 * Math.PI);

            return (NxaSphericalJoint)scene.CreateJoint(sphericalDesc);
        }

        private NxaActor CreateSphere(Vector3 pos, float radius, float density)
        {
            NxaActorDescription actorDesc = new NxaActorDescription();
            NxaBodyDescription bodyDesc = new NxaBodyDescription();

            NxaSphereShapeDescription sphereDesc = new NxaSphereShapeDescription();
            sphereDesc.Radius = radius;
            sphereDesc.LocalPose = Matrix.CreateTranslation(new Vector3(0, radius, 0));
            actorDesc.AddShape(sphereDesc);

            actorDesc.Body = bodyDesc;
            actorDesc.Density = density;
            actorDesc.GlobalPose = Matrix.CreateTranslation(pos);

            return scene.CreateActor(actorDesc);
        }

        private NxaActor CreateGroundPlane()
        {
            NxaPlaneShapeDescription planeDesc = new NxaPlaneShapeDescription();
            NxaActorDescription actorDesc = new NxaActorDescription();
            actorDesc.AddShape(planeDesc);
            return scene.CreateActor(actorDesc);
        }

        private void NextSelectedActor()
        {
            int index = actors.IndexOf(selectedActor);
            index++;
            selectedActor = actors[index % actors.Count];

            while (!IsSelectable(selectedActor))
            {
                index++;
                selectedActor = actors[index % actors.Count];
            }
        }

        private bool IsSelectable(NxaActor actor)
        {
            return actor != groundPlane;
        }

        public override void HandleInput(GameTime gameTime, GameInput input)
        {
            float f = (float)gameTime.ElapsedGameTime.TotalSeconds;

            if (input.Keyboard.NewState.IsKeyDown(Keys.R) && input.Keyboard.OldState.IsKeyUp(Keys.R))
                NextSelectedActor();

            if (input.Keyboard.NewState.IsKeyDown(Keys.F) && input.Keyboard.OldState.IsKeyUp(Keys.F))
                forceMode = !forceMode;

            if (input.Keyboard.NewState.IsKeyDown(Keys.I))
                forceDirection = Vector3.UnitZ;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.K))
                forceDirection = -Vector3.UnitZ;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.J))
                forceDirection = Vector3.UnitX;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.L))
                forceDirection = -Vector3.UnitX;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.U))
                forceDirection = Vector3.UnitY;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.M))
                forceDirection = -Vector3.UnitY;
            else
                forceDirection = Vector3.Zero;


            if (forceDirection != Vector3.Zero)
            {
                if (forceMode)
                    selectedActor.AddForce(forceDirection * forceStrength * f, NxaForceMode.Force, true);
                else
                    selectedActor.AddTorque(forceDirection * forceStrength * f, NxaForceMode.Force, true);
            }
        }

        public override void Draw(DebugCamera camera, GameTime gameTime)
        {
            base.Draw(camera, gameTime);

            if (forceDirection != Vector3.Zero)
            {
                Vector3 pos = selectedActor.GetCenterOfMassGlobalPosition();

                Color c = Color.Yellow;
                if (!forceMode)
                    c = Color.Cyan;

                DebugRenderer.DrawLine(camera.ViewProjection, pos, pos + (forceDirection * forceLineLength), c);
            }
        }
    }
}
