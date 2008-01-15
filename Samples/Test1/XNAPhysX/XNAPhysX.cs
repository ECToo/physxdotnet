using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Net;
using Microsoft.Xna.Framework.Storage;
using PhysXCPP;
using XNAPhysX.Physics;
using XnaPhysX.Input;
using XNAPhysX.Graphics.DebugRenderer;

namespace XNAPhysX
{
    public class XNAPhysX : Microsoft.Xna.Framework.Game
    {
        private static ContentManager manager;
        public static Random rng = new Random();

        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        PhysXScene scene;

        PhysXInput input;
        RTCamera camera;

        NxaActor sphere;
        NxaActor plane;

        const float everyMillis = 1000;
        float since = 0;

        int frames = 0;
        float millis = 0;

        public XNAPhysX()
        {
            manager = Content;
            graphics = new GraphicsDeviceManager(this);
            graphics.PreferredBackBufferWidth = 1280;
            graphics.PreferredBackBufferHeight = 720;

            Content.RootDirectory = "Content";

            NxaSceneDescription description = new NxaSceneDescription();
            description.SimulationType = NxaSimulationType.Hardware;
            description.Gravity = new Vector3(0, -9.81f, 0);
            description.EnableRemoteDebugger = false;

            scene = new PhysXScene(description);
            plane = scene.CreatePlane();
        }

        protected override void Initialize()
        {
            input = new PhysXInput();
            camera = new RTCamera(1280f/720f, new Vector3(0, 15, -15), MathHelper.PiOver4);
            camera.LookAtPoint = Vector3.Zero;
            base.Initialize();
        }

        protected override void LoadContent()
        {
            DebugRenderer.Setup(GraphicsDevice, ContentManager);
            spriteBatch = new SpriteBatch(GraphicsDevice);
        }

        protected override void UnloadContent()
        {

        }

        protected override void Update(GameTime gameTime)
        {
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            since += (float)gameTime.ElapsedGameTime.TotalMilliseconds;

            if (since > everyMillis)
            {
                scene.CreateSphere(new Vector3((float)rng.NextDouble(), 15, (float)rng.NextDouble()), 1);
                since = 0;
            }

            input.Update(gameTime);
            scene.Update(gameTime);

            float f = (float)gameTime.ElapsedGameTime.TotalSeconds;

            camera.MoveForward(input.ForwardSpeed() );
            camera.Strafe(input.StrafeSpeed());
            camera.Pitch(input.PitchSpeed() * f);
            camera.Yaw(input.YawSpeed() * f);

            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            frames++;
            millis += (float)gameTime.ElapsedGameTime.TotalMilliseconds;

            if (millis >= 1000)
            {
                Console.WriteLine(frames);
                frames = 0;
                millis = 0;
            }

            graphics.GraphicsDevice.Clear(Color.CornflowerBlue);

            scene.Draw(camera, gameTime);

            base.Draw(gameTime);
        }

        public static ContentManager ContentManager
        {
            get { return manager; }
        }
    }
}
