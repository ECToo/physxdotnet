using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using PhysXCPP;

namespace XNAPhysX.Graphics.Shapes
{
    public class DebugPlane
    {
        const int size = 1000;

        static GraphicsDevice device;
        static ContentManager content;

        static Vector4 unselectedColour = Color.DarkGreen.ToVector4();
        static Vector4 selectedColour = Color.Green.ToVector4();

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

            effect = content.Load<Effect>("Effects/PlaneShader");
        }

        private static void SetupVertices()
        {
            VertexPositionNormalTextureColour[] vertices = new VertexPositionNormalTextureColour[4];

            vertices[0] = new VertexPositionNormalTextureColour(new Vector3(-size, 0, size), Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[1] = new VertexPositionNormalTextureColour(new Vector3(-size, 0, -size), Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[2] = new VertexPositionNormalTextureColour(new Vector3(size, 0, -size), Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[3] = new VertexPositionNormalTextureColour(new Vector3(size, 0, size), Vector3.Up, Vector2.Zero, Vector4.Zero);

            vb = new VertexBuffer(device, typeof(VertexPositionNormalTextureColour), vertices.Length, BufferUsage.WriteOnly);
            vb.SetData<VertexPositionNormalTextureColour>(vertices);
        }

        private static void SetupIndices()
        {
            int[] indices = new int[6];

            indices[0] = 0;
            indices[1] = 1;
            indices[2] = 2;
            indices[3] = 2;
            indices[4] = 3;
            indices[5] = 0;

            ib = new IndexBuffer(device, typeof(int), indices.Length, BufferUsage.WriteOnly);
            ib.SetData<int>(indices);
        }

        public static void Draw(NxaPlaneShape plane, Matrix viewProjection, bool isSelected)
        {
            device.RenderState.CullMode = CullMode.None;
            device.Indices = ib;
            device.Vertices[0].SetSource(vb, 0, VertexPositionNormalTextureColour.SizeInBytes);
            device.VertexDeclaration = vd;

            Matrix world = Matrix.CreateTranslation(plane.GetGlobalPosition()); ;
            Matrix wvp = world * viewProjection;

            if (isSelected)
                effect.Parameters["colour"].SetValue(selectedColour);
            else
                effect.Parameters["colour"].SetValue(unselectedColour);

            effect.Parameters["lightColour"].SetValue(Color.White.ToVector4());
            effect.Parameters["lightPos1"].SetValue(new Vector3(0, 100, 0));
            effect.Parameters["World"].SetValue(world);
            effect.Parameters["WorldViewProjection"].SetValue(wvp);

            effect.Begin();
            effect.CurrentTechnique.Passes[0].Begin();
            device.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, 4, 0, 2);
            effect.CurrentTechnique.Passes[0].End();
            effect.End();
        }
    }
}