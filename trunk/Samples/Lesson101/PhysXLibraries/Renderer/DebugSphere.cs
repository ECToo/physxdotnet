using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using PhysXCPP;

namespace XNAPhysX.Graphics.Shapes
{
    public class DebugSphere
    {
        static int divisions = 20;

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
           
            SetupVertices();
            SetupIndices();

            effect = content.Load<Effect>("Effects/SphereShader");
        }

        private static void SetupVertices()
        {
            VertexPositionNormalTextureColour[] vertices = new VertexPositionNormalTextureColour[(divisions + 1) * (divisions)];

            float theta = MathHelper.Pi / divisions;
            float phi = MathHelper.TwoPi / divisions;
            int vertNum = 0;
            float radius = 1;

            for (float t = -MathHelper.PiOver2; t <= MathHelper.PiOver2 + (theta/2); t += theta)
            {
                for (float p = 0; p < MathHelper.TwoPi - (phi/2); p += phi)
                {
                    float cosTheta = (float)Math.Cos(t);

                    float xCoord = (float)(cosTheta * Math.Cos(p)) * radius;
                    float yCoord = (float)(Math.Sin(t)) * radius;
                    float zCoord = (float)(cosTheta * Math.Sin(p)) * radius;

                    Vector3 normal = new Vector3(xCoord, yCoord, zCoord);
                    normal.Normalize();

                    vertices[vertNum++] = new VertexPositionNormalTextureColour(new Vector3(xCoord, yCoord, zCoord), normal, 
                                                new Vector2(xCoord/2 + 0.5f, yCoord/2 + 0.5f), Color.CornflowerBlue.ToVector4());
                }
            }

            vb = new VertexBuffer(device, typeof(VertexPositionNormalTextureColour), vertices.Length, BufferUsage.WriteOnly);
            vb.SetData<VertexPositionNormalTextureColour>(vertices);
        }

        private static void SetupIndices()
        {
            int[] indices = new int[divisions * divisions * 6];

            int index = 0;

            for (int y = 0; y < divisions; y++)
            {
                for (int x = 0; x < divisions - 1; x++)
                {
                    indices[index++] = (divisions * y) + x;
                    indices[index++] = (divisions * (y + 1)) + x;
                    indices[index++] = (divisions * (y + 1)) + x + 1;

                    indices[index++] = (divisions * (y + 1)) + x + 1;
                    indices[index++] = (divisions * y) + x + 1;
                    indices[index++] = (divisions * y) + x;
                }

                indices[index++] = (divisions * y) + divisions - 1;
                indices[index++] = (divisions * (y + 1)) + divisions - 1;
                indices[index++] = (divisions * (y + 1));

                indices[index++] = (divisions * (y + 1));
                indices[index++] = (divisions * (y));
                indices[index++] = (divisions * y) + divisions - 1;
            }

            ib = new IndexBuffer(device, typeof(int), indices.Length, BufferUsage.WriteOnly);
            ib.SetData<int>(indices);
        }

        public static void Draw(NxaSphereShape sphere, Matrix viewProjection, bool isSelected)
        {
            device.RenderState.CullMode = CullMode.CullClockwiseFace;
            device.Indices = ib;
            device.Vertices[0].SetSource(vb, 0, VertexPositionNormalTextureColour.SizeInBytes);
            device.VertexDeclaration = vd;

            Matrix world = sphere.GetGlobalPose();
            Matrix wvp = world * viewProjection;
            
            effect.Parameters["World"].SetValue(world);
            effect.Parameters["WorldViewProjection"].SetValue(wvp);
            effect.Parameters["colour"].SetValue(Color.Red.ToVector4());
            effect.Parameters["lightColour"].SetValue(Color.White.ToVector4());
            effect.Parameters["lightPos1"].SetValue(new Vector3(0, 100, 0));

            effect.Begin();
            effect.CurrentTechnique.Passes[0].Begin();
            device.DrawIndexedPrimitives(PrimitiveType.TriangleList, 0, 0, (divisions + 1) * (divisions), 0, (divisions * divisions * 2));
            effect.CurrentTechnique.Passes[0].End();
            effect.End();
        }
    }

    public struct VertexPositionNormalTextureColour
    {
        public Vector3 position;
        public Vector3 normal;
        public Vector2 textureCoordinate;
        public Vector4 colour;

        public VertexPositionNormalTextureColour(Vector3 position, Vector3 normal, Vector2 textureCoordinate, Vector4 colour)
        {
            this.position = position;
            this.normal = normal;
            this.textureCoordinate = textureCoordinate;
            this.colour = colour;
        }

        public static readonly VertexElement[] VertexElements = new VertexElement[]
		{
            new VertexElement(0, 0, VertexElementFormat.Vector3, VertexElementMethod.Default, VertexElementUsage.Position, 0),
            new VertexElement(0, 12, VertexElementFormat.Vector3, VertexElementMethod.Default, VertexElementUsage.TextureCoordinate, 1),
            new VertexElement(0, 24, VertexElementFormat.Vector2, VertexElementMethod.Default, VertexElementUsage.TextureCoordinate, 0),
            new VertexElement(0, 32, VertexElementFormat.Vector4, VertexElementMethod.Default, VertexElementUsage.Color, 0)
         };

        public static int SizeInBytes
        {
            get { return 48; }
        }
    }
}