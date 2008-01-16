using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using PhysXCPP;

namespace XNAPhysX.Graphics.Shapes
{
    public class DebugLine
    {
        static GraphicsDevice device;
        static ContentManager content;

        static private Effect effect;
        static private VertexBuffer vb;
        static private IndexBuffer ib;
        static private VertexDeclaration vd;

        public static void LoadResources(GraphicsDevice d, ContentManager c)
        {
            device = d;
            content = c;

            vd = new VertexDeclaration(device, VertexPositionNormalTextureColour.VertexElements);

            effect = content.Load<Effect>("Effects/PlaneShader");
        }

        public static void Draw(Vector3 source, Vector3 dest, Color colour, Matrix viewProjection)
        {
            device.RenderState.CullMode = CullMode.None;
            device.VertexDeclaration = vd;

            Matrix wvp = viewProjection;

            effect.Parameters["colour"].SetValue(colour.ToVector4());
            effect.Parameters["World"].SetValue(Matrix.Identity);
            effect.Parameters["WorldViewProjection"].SetValue(wvp);

            VertexPositionNormalTextureColour[] vertices = new VertexPositionNormalTextureColour[2];
            vertices[0] = new VertexPositionNormalTextureColour(source, Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[1] = new VertexPositionNormalTextureColour(dest, Vector3.Up, Vector2.Zero, Vector4.Zero);

            effect.Begin();
            effect.CurrentTechnique.Passes[0].Begin();
            device.DrawUserPrimitives(PrimitiveType.LineList, vertices, 0, 1); 
            effect.CurrentTechnique.Passes[0].End();
            effect.End();
        }
    }
}