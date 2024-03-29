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

            DebugLine.LoadResources(device, manager);
            DebugBox.LoadResources(device, manager);
            DebugSphere.LoadResources(device, manager);
            DebugPlane.LoadResources(device, manager);
        }

        public static void DrawActor(Matrix vp, NxaActor actor, bool isSelected)
        {
            NxaShape[] shapes = actor.GetShapes();

            foreach (NxaShape shape in shapes)
            {
                if (shape.IsSphere())
                {
                    DebugSphere.Draw(shape as NxaSphereShape, vp, isSelected);
                }
                else if (shape.IsBox())
                {
                    DebugBox.Draw(shape as NxaBoxShape, vp, isSelected);
                }
                else if (shape.IsPlane())
                {
                    DebugPlane.Draw(shape as NxaPlaneShape, vp, isSelected);
                }
                else if (shape.IsCapsule())
                {
                    //Not implemented, use the Ageia Visual Debugger!
                }
            }
        }

        public static void DrawLine(Matrix vp, Vector3 s, Vector3 d, Color c)
        {
            DebugLine.Draw(s, d, c, vp);
        }
    }
}
