using System;
using System.Collections.Generic;
using System.Text;
using PhysXCPP;
using Microsoft.Xna.Framework;
using XNAPhysX.Graphics.DebugRenderer;
using XnaPhysX.Input;

namespace XNAPhysX.Physics
{
    public class PhysXScene
    {
        protected List<NxaActor> actors = new List<NxaActor>();

        static PhysXEngine engine;

        protected NxaScene scene;

        static PhysXScene()
        {
            engine = new PhysXEngine();
        }

        public PhysXScene()
        {
            NxaSceneDescription description = new NxaSceneDescription();
            description.SimulationType = NxaSimulationType.Hardware;
            description.Gravity = new Vector3(0, -9.81f, 0);
            description.EnableRemoteDebugger = false;

            scene = engine.CreateScene(description);
        }

        public PhysXScene(NxaSceneDescription description)
        {
            scene = engine.CreateScene(description);
        }

        public NxaActor CreateActor(NxaActorDescription description)
        {
            NxaActor actor = scene.CreateActor(description);
            actors.Add(actor);
            return actor;
        }

        public virtual void HandleInput(GameTime gameTime, GameInput input)
        {

        }

        public void Update(GameTime gameTime)
        {
            scene.UpdateScene((float)gameTime.ElapsedGameTime.TotalSeconds);
            scene.FetchResults(true);
        }

        public void Draw(DebugCamera camera, GameTime gameTime)
        {
            Matrix vp = camera.ViewProjection;

            foreach (NxaActor actor in actors)
            {
                DebugRenderer.DrawActor(vp, actor);
            }
        }
    }
}
