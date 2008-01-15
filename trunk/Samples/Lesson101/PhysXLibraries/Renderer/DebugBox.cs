using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using PhysXCPP;

namespace XNAPhysX.Graphics.Shapes
{
    public class DebugBox
    {
        const int size = 1;

        static GraphicsDevice device;
        static ContentManager content;

        static Vector4 unselectedColour = Color.Blue.ToVector4();
        static Vector4 selectedColour = Color.Cyan.ToVector4();

        static private Effect effect;
        static private VertexBuffer vb;
        static private IndexBuffer ib;
        static private VertexDeclaration vd;

        public static void LoadResources(GraphicsDevice d, ContentManager c)
        {
            device = d;
            content = c;

            vd = new VertexDeclaration(device, VertexPositionNormalTextureColour.VertexElements);

            SetupVertices();
            SetupIndices();

            effect = content.Load<Effect>("Effects/BoxShader");
        }

        private static void SetupVertices()
        {
            VertexPositionNormalTextureColour[] vertices = new VertexPositionNormalTextureColour[24];

            //BACK FACE
            vertices[0] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, -0.5f, -0.5f), new Vector3(0, 0, -1), new Vector2(1, 1), Color.White.ToVector4());
            vertices[1] = new VertexPositionNormalTextureColour(new Vector3(0.5f, -0.5f, -0.5f), new Vector3(0, 0, -1), new Vector2(0, 1), Color.White.ToVector4());
            vertices[2] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, 0.5f, -0.5f), new Vector3(0, 0, -1), new Vector2(1, 0), Color.White.ToVector4());
            vertices[3] = new VertexPositionNormalTextureColour(new Vector3(0.5f, 0.5f, -0.5f), new Vector3(0, 0, -1), new Vector2(0, 0), Color.White.ToVector4());

            //TOP FACE
            vertices[4] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, 0.5f, -0.5f), new Vector3(0, 1, 0), new Vector2(0, 0), Color.White.ToVector4());
            vertices[5] = new VertexPositionNormalTextureColour(new Vector3(0.5f, 0.5f, -0.5f), new Vector3(0, 1, 0), new Vector2(1, 0), Color.White.ToVector4());
            vertices[6] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, 0.5f, 0.5f), new Vector3(0, 1, 0), new Vector2(0, 1), Color.White.ToVector4());
            vertices[7] = new VertexPositionNormalTextureColour(new Vector3(0.5f, 0.5f, 0.5f), new Vector3(0, 1, 0), new Vector2(1, 1), Color.White.ToVector4());

            //FRONT FACE
            vertices[8] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, 0.5f, 0.5f), new Vector3(0, 0, 1), new Vector2(0, 0), Color.White.ToVector4());
            vertices[9] = new VertexPositionNormalTextureColour(new Vector3(0.5f, 0.5f, 0.5f), new Vector3(0, 0, 1), new Vector2(1, 0), Color.White.ToVector4());
            vertices[10] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, -0.5f, 0.5f), new Vector3(0, 0, 1), new Vector2(0, 1), Color.White.ToVector4());
            vertices[11] = new VertexPositionNormalTextureColour(new Vector3(0.5f, -0.5f, 0.5f), new Vector3(0, 0, 1), new Vector2(1, 1), Color.White.ToVector4());

            //BOTTOM FACE
            vertices[12] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, -0.5f, 0.5f), new Vector3(0, -1, 0), new Vector2(1, 1), Color.White.ToVector4());
            vertices[13] = new VertexPositionNormalTextureColour(new Vector3(0.5f, -0.5f, 0.5f), new Vector3(0, -1, 0), new Vector2(0, 1), Color.White.ToVector4());
            vertices[14] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, -0.5f, -0.5f), new Vector3(0, -1, 0), new Vector2(1, 0), Color.White.ToVector4());
            vertices[15] = new VertexPositionNormalTextureColour(new Vector3(0.5f, -0.5f, -0.5f), new Vector3(0, -1, 0), new Vector2(0, 0), Color.White.ToVector4());

            //LEFT FACE
            vertices[16] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, -0.5f, 0.5f), new Vector3(-1, 0, 0), new Vector2(1, 1), Color.White.ToVector4());
            vertices[17] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, -0.5f, -0.5f), new Vector3(-1, 0, 0), new Vector2(0, 1), Color.White.ToVector4());
            vertices[18] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, 0.5f, 0.5f), new Vector3(-1, 0, 0), new Vector2(1, 0), Color.White.ToVector4());
            vertices[19] = new VertexPositionNormalTextureColour(new Vector3(-0.5f, 0.5f, -0.5f), new Vector3(-1, 0, 0), new Vector2(0, 0), Color.White.ToVector4());

            //RIGHT FACE
            vertices[20] = new VertexPositionNormalTextureColour(new Vector3(0.5f, -0.5f, -0.5f), new Vector3(1, 0, 0), new Vector2(1, 1), Color.White.ToVector4());
            vertices[21] = new VertexPositionNormalTextureColour(new Vector3(0.5f, -0.5f, 0.5f), new Vector3(1, 0, 0), new Vector2(0, 1), Color.White.ToVector4());
            vertices[22] = new VertexPositionNormalTextureColour(new Vector3(0.5f, 0.5f, -0.5f), new Vector3(1, 0, 0), new Vector2(1, 0), Color.White.ToVector4());
            vertices[23] = new VertexPositionNormalTextureColour(new Vector3(0.5f, 0.5f, 0.5f), new Vector3(1, 0, 0), new Vector2(0, 0), Color.White.ToVector4());

            vb = new VertexBuffer(device, typeof(VertexPositionNormalTextureColour), vertices.Length, BufferUsage.WriteOnly);
            vb.SetData<VertexPositionNormalTextureColour>(vertices);
        }

        private static void SetupIndices()
        {
            int[] indices = new int[36];

            for (int s = 0; s < 6; s++)
            {
                indices[s * 6 + 0] = 0 + (s * 4);
                indices[s * 6 + 1] = 1 + (s * 4);
                indices[s * 6 + 2] = 2 + (s * 4);
                indices[s * 6 + 3] = 1 + (s * 4);
                indices[s * 6 + 4] = 2 + (s * 4);
                indices[s * 6 + 5] = 3 + (s * 4);
            }

            ib = new IndexBuffer(device, typeof(int), indices.Length, BufferUsage.WriteOnly);
            ib.SetData<int>(indices);
        }

        public static void Draw(NxaBoxShape box, Matrix viewProjection, bool isSelected)
        {
            device.RenderState.CullMode = CullMode.None;
            device.Indices = ib;
            device.Vertices[0].SetSource(vb, 0, VertexPositionNormalTextureColour.SizeInBytes);
            device.VertexDeclaration = vd;

            Vector3 extents = box.GetDimensions();

            Matrix world =  box.GetGlobalOrientation() * Matrix.CreateScale(extents * 2) * Matrix.CreateTranslation(box.GetGlobalPosition());
            Matrix wvp = world * viewProjection;
            
            if(isSelected)
                effect.Parameters["colour"].SetValue(selectedColour);
            else
                effect.Parameters["colour"].SetValue(unselectedColour);

            effect.Parameters["lightColour"].SetValue(Color.White.ToVector4());
            effect.Parameters["lightPos1"].SetValue(new Vector3(100, 100, 0));
            effect.Parameters["World"].SetValue(world);
            effect.Parameters["WorldViewProjection"].SetValue(wvp);

            effect.Begin();
            effect.CurrentTechnique.Passes[0].Begin();
            device.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, 24, 0, 12);
            effect.CurrentTechnique.Passes[0].End();
            effect.End();
        }
    }
}