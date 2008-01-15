using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using PhysXCPP;

namespace XNAPhysX.Graphics.Shapes
{
    public class RPlane
    {
        const int size = 10;
        private NxaPlaneShapeDescription plane;

        private Effect effect;
        private VertexBuffer vb;
        private IndexBuffer ib;
        private VertexDeclaration vd;

        public RPlane(NxaPlaneShapeDescription plane, Game game)
            : base(game)
        {
            this.plane = plane;

            if (game != null)
            {
                IGraphicsDeviceService graphicsService = (IGraphicsDeviceService)game.Services.GetService(typeof(IGraphicsDeviceService));
                vd = new VertexDeclaration(graphicsService.GraphicsDevice, VertexPositionNormalTextureColour.VertexElements);
            }

            SetupVertices();
            SetupIndices();

            effect = RT360Game.ContentManager.Load<Effect>("Effects/ShapeShader");
        }

        private void SetupVertices()
        {
            VertexPositionNormalTextureColour[] vertices = new VertexPositionNormalTextureColour[4];

            vertices[0] = new VertexPositionNormalTextureColour(new Vector3(-size, 0, size), Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[1] = new VertexPositionNormalTextureColour(new Vector3(-size, 0, -size), Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[2] = new VertexPositionNormalTextureColour(new Vector3(size, 0, -size), Vector3.Up, Vector2.Zero, Vector4.Zero);
            vertices[3] = new VertexPositionNormalTextureColour(new Vector3(size, 0, size), Vector3.Up, Vector2.Zero, Vector4.Zero);

            IGraphicsDeviceService graphicsService = (IGraphicsDeviceService)game.Services.GetService(typeof(IGraphicsDeviceService));
            GraphicsDevice device = graphicsService.GraphicsDevice;

            vb = new VertexBuffer(device, typeof(VertexPositionNormalTextureColour), vertices.Length, BufferUsage.WriteOnly);
            vb.SetData<VertexPositionNormalTextureColour>(vertices);
        }

        private void SetupIndices()
        {
            int[] indices = new int[6];

            indices[0] = 0;
            indices[1] = 1;
            indices[2] = 2;
            indices[3] = 2;
            indices[4] = 3;
            indices[5] = 0;

            IGraphicsDeviceService graphicsService = (IGraphicsDeviceService)game.Services.GetService(typeof(IGraphicsDeviceService));
            GraphicsDevice device = graphicsService.GraphicsDevice;

            ib = new IndexBuffer(device, typeof(int), indices.Length, BufferUsage.WriteOnly);
            ib.SetData<int>(indices);
        }

        public override void Draw(List<RTLight> lights, Matrix viewProjection, GameTime gameTime)
        {
            IGraphicsDeviceService graphicsService = (IGraphicsDeviceService)game.Services.GetService(typeof(IGraphicsDeviceService));
            GraphicsDevice device = graphicsService.GraphicsDevice;

            device.RenderState.CullMode = CullMode.None;
            device.Indices = ib;
            device.Vertices[0].SetSource(vb, 0, VertexPositionNormalTextureColour.SizeInBytes);
            device.VertexDeclaration = vd;

            Matrix world = Matrix.Identity;
            Matrix wvp = world * viewProjection;
            
            Vector4 planeColour;
            plane.Material.GetColourAt(0, 0, out planeColour);

            effect.Parameters["colour"].SetValue(planeColour);
            effect.Parameters["lightColour"].SetValue(lights[0].Colour);
            effect.Parameters["lightPos1"].SetValue(lights[0].GetPosition());
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