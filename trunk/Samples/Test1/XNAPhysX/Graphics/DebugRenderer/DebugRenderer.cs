using System;
using System.Collections.Generic;
using System.Text;
using XNAPhysX.Graphics.Shapes;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework;

namespace XNAPhysX.Graphics.DebugRenderer
{
    public class DebugRenderer
    {
        static GraphicsDevice device;
        static ContentManager manager;

        public static void Setup(GraphicsDevice graphicsDevice, ContentManager contentManager)
        {
            device = graphicsDevice;
            manager = contentManager;

            DebugSphere.LoadResources(device, manager);
            DebugPlane.LoadResources(device, manager);
        }

        public static void DrawActor(Matrix vp, NxaActor actor)
        {
            NxaShape[] shapes = actor.GetShapes();

            foreach (NxaShape shape in shapes)
            {
                if (shape.IsSphere())
                {
                    DebugSphere.Draw(shape as NxaSphereShape, vp);
                }
                else if (shape.IsBox())
                {

                }
                else if (shape.IsPlane())
                {
                    DebugPlane.Draw(shape as NxaPlaneShape, vp);
                }
            }
        }
    }
}
