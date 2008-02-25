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

namespace Lesson208
{
    public class Lesson208Scene : PhysXScene
    {
        const float forceStrength = 40000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor box1, box2;

        Vector3 forceDirection = Vector3.Zero;
        bool forceMode = true;

        public Lesson208Scene() : base()
        {
            groundPlane = CreateGroundPlane();

            box1 = CreateBox(new Vector3(0, 5, 0), new Vector3(1, 2, 1), 10);
            box1.RaiseBodyFlag(NxaBodyFlag.Kinematic);
            box2 = CreateBox(new Vector3(0, 3, 0), new Vector3(0.5f, 2, 0.5f), 10);
            box2.SetLinearDamping(0.5f);

            actors.Add(groundPlane);
            actors.Add(box1);
            actors.Add(box2);

            NxaPrismaticJoint joint = CreatePrismaticJoint(box1, box2, new Vector3(0, 7, 0), Vector3.UnitY);
            
            selectedActor = box2;

            Console.WriteLine("Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down\n");
            Console.WriteLine("Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
            Console.WriteLine("Miscellaneous:\n --------------\n r = Select Next Actor\n f = Toggle Force Mode\n");
        }

        private NxaPrismaticJoint CreatePrismaticJoint(NxaActor a0, NxaActor a1, Vector3 globalAnchor, Vector3 globalAxis)
        {
            NxaPrismaticJointDescription prismaticDesc = new NxaPrismaticJointDescription();
            prismaticDesc.Actor[0] = a0;
            prismaticDesc.Actor[1] = a1;
            prismaticDesc.SetGlobalAnchor(globalAnchor);
            prismaticDesc.SetGlobalAxis(globalAxis);

            NxaPrismaticJoint joint = (NxaPrismaticJoint)scene.CreateJoint(prismaticDesc);

            joint.SetLimitPoint(globalAnchor);
            joint.AddLimitPlane(-globalAxis, globalAnchor + 1.5f * globalAxis);
            joint.AddLimitPlane(globalAxis, globalAnchor - 1.5f * globalAxis);

            return joint;
        }

        private NxaActor CreateBox(Vector3 pos, Vector3 boxDim, float density)
        {
            NxaActorDescription actorDesc = new NxaActorDescription();
            NxaBodyDescription bodyDesc = new NxaBodyDescription();

            NxaBoxShapeDescription boxDesc = new NxaBoxShapeDescription();
            boxDesc.Dimensions = boxDim;
            boxDesc.LocalPose = Matrix.CreateTranslation(new Vector3(0, boxDim.Y, 0));
            actorDesc.AddShape(boxDesc);

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
