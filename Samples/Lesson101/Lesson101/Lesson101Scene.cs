using System;
using System.Collections.Generic;
using System.Text;
using XNAPhysX.Physics;
using Microsoft.Xna.Framework;
using PhysXCPP;
using XnaPhysX.Input;
using Microsoft.Xna.Framework.Input;
using XNAPhysX;
using XNAPhysX.Graphics.DebugRenderer;
using Microsoft.Xna.Framework.Graphics;

namespace Lesson101
{
    public class Lesson101Scene : PhysXScene
    {
        const float forceStrength = 20000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor box;

        Vector3 forceDirection = Vector3.Zero;

        public Lesson101Scene() : base()
        {
            groundPlane = CreateGroundPlane();
            box = CreateBox();

            actors.Add(groundPlane);
            actors.Add(box);

            selectedActor = box;

            Console.WriteLine("\n Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down");
            Console.WriteLine("\n Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
        }

        private NxaActor CreateBox()
        {
            float boxStartHeight = 3.5f;

            NxaActorDescription actorDesc = new NxaActorDescription();
            NxaBodyDescription bodyDesc = new NxaBodyDescription();

            NxaBoxShapeDescription boxDesc = new NxaBoxShapeDescription();
            boxDesc.Dimensions = new Vector3(0.5f, 0.5f, 0.5f);
            actorDesc.AddShape(boxDesc);

            actorDesc.Body = bodyDesc;
            actorDesc.Density = 10;
            actorDesc.GlobalPose = Matrix.CreateTranslation(0, boxStartHeight, 0);

            return scene.CreateActor(actorDesc);
        }

        private NxaActor CreateGroundPlane()
        {
            NxaPlaneShapeDescription planeDesc = new NxaPlaneShapeDescription();
            NxaActorDescription actorDesc = new NxaActorDescription();
            actorDesc.AddShape(planeDesc);
            return scene.CreateActor(actorDesc);
        }

        public override void HandleInput(GameTime gameTime, GameInput input)
        {
            float f = (float)gameTime.ElapsedGameTime.TotalSeconds;

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
                box.AddForce(forceDirection * forceStrength * f);

            if (input.Keyboard.NewState.IsKeyDown(Keys.T))
            {
                box.SetGlobalPosition(new Vector3(0, 5, 0));
                scene.FlushCaches();
            }
        }

        public override void Draw(DebugCamera camera, GameTime gameTime)
        {
            base.Draw(camera, gameTime);

            if(forceDirection != Vector3.Zero)
            {
                Vector3 boxPos = box.GetGlobalPosition();
                DebugRenderer.DrawLine(camera.ViewProjection, boxPos, boxPos + (forceDirection * forceLineLength), Color.Yellow);
            }
        }
    }
}
