using System;
using System.Collections.Generic;
using System.Text;
using XNAPhysX.Physics;
using Microsoft.Xna.Framework;
using PhysXCPP;
using XnaPhysX.Input;
using Microsoft.Xna.Framework.Input;

namespace Lesson101
{
    public class Lesson101Scene : PhysXScene
    {
        const float forceStrength = 20000;
        const float deltaTime = 1f / 60f;

        NxaActor groundPlane;
        NxaActor box;

        NxaActor selectedActor;

        public Lesson101Scene() : base()
        {
            groundPlane = CreateGroundPlane();
            box = CreateBox();

            actors.Add(groundPlane);
            actors.Add(box);

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
                box.AddForce(Vector3.UnitZ * forceStrength * f);
            if (input.Keyboard.NewState.IsKeyDown(Keys.K))
                box.AddForce(-Vector3.UnitZ * forceStrength * f);
            if (input.Keyboard.NewState.IsKeyDown(Keys.J))
                box.AddForce(Vector3.UnitX * forceStrength * f);
            if (input.Keyboard.NewState.IsKeyDown(Keys.L))
                box.AddForce(-Vector3.UnitX * forceStrength * f);
            if (input.Keyboard.NewState.IsKeyDown(Keys.U))
                box.AddForce(Vector3.UnitY * forceStrength * f);
            if (input.Keyboard.NewState.IsKeyDown(Keys.M))
                box.AddForce(-Vector3.UnitY * forceStrength * f);

            if (input.Keyboard.NewState.IsKeyDown(Keys.T))
            {
                box.SetGlobalPosition(new Vector3(0, 5, 0));
                scene.FlushCaches();
            }
        }
    }
}
