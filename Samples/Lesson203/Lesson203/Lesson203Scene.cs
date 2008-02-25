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

namespace Lesson203
{
    public class Lesson203Scene : PhysXScene
    {
        const float forceStrength = 75000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor box1, box2;

        NxaRevoluteJoint revJoint;
        
        Vector3 forceDirection = Vector3.Zero;
        bool forceMode = true;

        public Lesson203Scene() : base()
        {
            groundPlane = CreateGroundPlane();
            
            box1 = CreateBox(new Vector3(0, 5, 0), new Vector3(0.5f, 2, 1), 10);
            box1.RaiseBodyFlag(NxaBodyFlag.Kinematic);
            box2 = CreateBox(new Vector3(0, 1, 0), new Vector3(0.5f, 2, 1), 10);

            Vector3 globalAnchor = new Vector3(0.5f, 5, -1);
            Vector3 globalAxis = new Vector3(0, 0, -1);

            revJoint = CreateRevoluteJoint(box1, box2, globalAnchor, globalAxis);

            actors.Add(groundPlane);
            actors.Add(box1);
            actors.Add(box2);

            selectedActor = box2;

            Console.WriteLine("Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down\n");
            Console.WriteLine("Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
            Console.WriteLine("Miscellaneous:\n --------------\n r = Select Next Actor\n f = Toggle Force Mode");
        }

        private NxaRevoluteJoint CreateRevoluteJoint(NxaActor box1, NxaActor box2, Vector3 globalAnchor, Vector3 globalAxis)
        {
            NxaRevoluteJointDescription revDesc = new NxaRevoluteJointDescription();
            revDesc.Actor[0] = box1;
            revDesc.Actor[1] = box2;
            revDesc.SetGlobalAnchor(globalAnchor);
            revDesc.SetGlobalAxis(globalAxis);


            NxaRevoluteJoint joint = (NxaRevoluteJoint)scene.CreateJoint(revDesc);

            joint.SetLimitPoint(globalAnchor + new Vector3(0, -4, 0));
            joint.AddLimitPlane(new Vector3(-0.707f, -0.707f, 0), globalAnchor);
            joint.AddLimitPlane(Vector3.UnitX, globalAnchor);

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
