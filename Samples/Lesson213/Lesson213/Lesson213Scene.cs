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

namespace Lesson213
{
    public class Lesson213Scene : PhysXScene
    {
        const float forceStrength = 35000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor sphere1, sphere2;

        Vector3 forceDirection = Vector3.Zero;
        bool forceMode = true;

        public Lesson213Scene() : base()
        {
            groundPlane = CreateGroundPlane();

            sphere1 = CreateSphere(new Vector3(-3, 4, 0), 1, 5);
            sphere1.RaiseBodyFlag(NxaBodyFlag.FrozenRotation);
            sphere2 = CreateSphere(new Vector3(3, 4, 0), 1, 5);
            sphere2.RaiseBodyFlag(NxaBodyFlag.FrozenRotation);

            actors.Add(groundPlane);
            actors.Add(sphere1);
            actors.Add(sphere2);

            NxaDistanceJoint joint = CreateDistanceJoint(sphere1, sphere2, Vector3.UnitY, Vector3.UnitY, -Vector3.UnitX);
            
            selectedActor = sphere1;

            Console.WriteLine("Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down\n");
            Console.WriteLine("Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
            Console.WriteLine("Miscellaneous:\n --------------\n r = Select Next Actor\n f = Toggle Force Mode\n");
        }

        private NxaDistanceJoint CreateDistanceJoint(NxaActor a0, NxaActor a1, Vector3 anchor0, Vector3 anchor1, Vector3 globalAxis)
        {
            NxaDistanceJointDescription distanceDesc = new NxaDistanceJointDescription();
            distanceDesc.Actor[0] = a0;
            distanceDesc.Actor[1] = a1;
            distanceDesc.LocalAnchor[0] = anchor0;
            distanceDesc.LocalAnchor[1] = anchor1;
            distanceDesc.SetGlobalAxis(globalAxis);

            Vector3 dist = a1.GetGlobalPosition() - a0.GetGlobalPosition();
            distanceDesc.MaxDistance = dist.Length() * 1.5f;
            distanceDesc.MinDistance = dist.Length() * 1f;

            NxaSpringDescription spring = new NxaSpringDescription();
            spring.Spring = 100;
            spring.Damper = 0.5f;

            distanceDesc.Spring = spring;
            distanceDesc.Flags = (NxaDistanceJointFlag.MinDistanceEnabled | NxaDistanceJointFlag.MaxDistanceEnabled);
            distanceDesc.Flags |= NxaDistanceJointFlag.SpringEnabled;
            distanceDesc.JointFlags |= NxaJointFlag.CollisionEnabled;

            return (NxaDistanceJoint)scene.CreateJoint(distanceDesc);
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
