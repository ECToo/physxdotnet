using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using XNAPhysX.Graphics.DebugRenderer;

namespace XNAPhysX.Physics
{
    public class PhysXScene
    {
        List<NxaActor> actors = new List<NxaActor>();

        static PhysXEngine engine;

        NxaScene scene;

        static PhysXScene()
        {
            engine = new PhysXEngine();
        }

        public PhysXScene(NxaSceneDescription description)
        {
            scene = engine.CreateScene(description);
        }

        public NxaActor CreateSphere(Vector3 position, float radius)
        {
            NxaActorDescription actorDescription = new NxaActorDescription();
            actorDescription.GlobalPose = Matrix.CreateTranslation(position);
            actorDescription.Density = 1f;

            NxaSphereShapeDescription sphereDescription = new NxaSphereShapeDescription();
            sphereDescription.Radius = radius;

            actorDescription.AddShape(sphereDescription);

            actorDescription.Body = new NxaBodyDescription();

            NxaActor actor = scene.CreateActor(actorDescription);
            actors.Add(actor);

            return actor;
        }

        public NxaActor CreatePlane()
        {
            NxaActorDescription actorDescription = new NxaActorDescription();
            actorDescription.AddShape(new NxaPlaneShapeDescription());

            NxaActor actor = scene.CreateActor(actorDescription);
            actors.Add(actor);

            return actor;
        }

        public void Update(GameTime gameTime)
        {
            scene.UpdateScene((float)gameTime.ElapsedGameTime.TotalSeconds);
            scene.FetchResults(true);
        }

        public void Draw(RTCamera camera, GameTime gameTime)
        {
            Matrix vp = camera.ViewProjection;

            foreach (NxaActor actor in actors)
            {
                DebugRenderer.DrawActor(vp, actor);
            }
        }
    }
}
