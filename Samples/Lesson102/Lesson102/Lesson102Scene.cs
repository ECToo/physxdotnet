using System;
using System.Collections.Generic;
using System.Text;
using XNAPhysX.Physics;
using Microsoft.Xna.Framework;
using PhysXCPP;
using XnaPhysX.Input;
using Microsoft.Xna.Framework.Input;
using XNAPhysX.Graphics.DebugRenderer;
using XNAPhysX;
using Microsoft.Xna.Framework.Graphics;

namespace Lesson102
{
    public class Lesson102Scene : PhysXScene
    {
        const float forceStrength = 40000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor box;
        NxaActor sphere;

        Vector3 forceDirection = Vector3.Zero;
        bool forceMode = true;

        public Lesson102Scene() : base()
        {
            groundPlane = CreateGroundPlane();
            box = CreateBox(new Vector3(5, 1, 0));
            sphere = CreateSphere(new Vector3(0, 1, 0));

            actors.Add(groundPlane);
            actors.Add(box);
            actors.Add(sphere);

            selectedActor = box;

            Console.WriteLine("Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down\n");
            Console.WriteLine("Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
            Console.WriteLine("Miscellaneous:\n --------------\n r = Select Next Actor\n f = Toggle Force Mode\n t = Move Focus Actor to (0,5,0)\n");
        }

        private NxaActor CreateSphere(Vector3 pos)
        {
            NxaActorDescription actorDesc = new NxaActorDescription();
            NxaBodyDescription bodyDesc = new NxaBodyDescription();

            NxaSphereShapeDescription sphereDesc = new NxaSphereShapeDescription();
            sphereDesc.Radius = 1;
            actorDesc.AddShape(sphereDesc);

            actorDesc.Body = bodyDesc;
            actorDesc.Density = 10;
            actorDesc.GlobalPose = Matrix.CreateTranslation(pos);

            return scene.CreateActor(actorDesc);
        }

        private NxaActor CreateBox(Vector3 pos)
        {
            float boxStartHeight = 3.5f;

            NxaActorDescription actorDesc = new NxaActorDescription();
            NxaBodyDescription bodyDesc = new NxaBodyDescription();

            NxaBoxShapeDescription boxDesc = new NxaBoxShapeDescription();
            boxDesc.Dimensions = new Vector3(0.5f, 1f, 0.5f);
            actorDesc.AddShape(boxDesc);

            actorDesc.Body = bodyDesc;
            actorDesc.Density = 10;
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
                    selectedActor.AddForce(forceDirection * forceStrength * f);
                else
                    selectedActor.AddTorque(forceDirection * forceStrength * f);
            }

            if (input.Keyboard.NewState.IsKeyDown(Keys.T))
            {
                selectedActor.SetGlobalPosition(new Vector3(0, 5, 0));
                scene.FlushCaches();
            }
        }

        public override void Draw(DebugCamera camera, GameTime gameTime)
        {
            base.Draw(camera, gameTime);

            if (forceDirection != Vector3.Zero)
            {
                Vector3 pos = selectedActor.GetGlobalPosition();

                Color c = Color.Yellow;
                if (!forceMode)
                    c = Color.Cyan;

                DebugRenderer.DrawLine(camera.ViewProjection, pos, pos + (forceDirection * forceLineLength), c);
            }
        }
    }
}
