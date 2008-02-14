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
using XNAPhysX.Physics;
using XNAPhysX.Input;
using XNAPhysX.Graphics.DebugRenderer;
using Lesson201;

namespace XNAPhysX
{
    public class PhysXGame : Microsoft.Xna.Framework.Game
    {
        private static ContentManager manager;
        public static Random rng = new Random();

        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        Lesson201Scene scene;

        PhysXInput input;
        DebugCamera camera;

        const int displayWidth = 512;
        const int displayHeight = 512;

        const float cameraSpeed = 10;

        public PhysXGame()
        {
            Window.Title = "Lesson 201: Joints";

            manager = Content;
            graphics = new GraphicsDeviceManager(this);
            graphics.PreferredBackBufferWidth = displayWidth;
            graphics.PreferredBackBufferHeight = displayHeight;

            Content.RootDirectory = "Content";

            scene = new Lesson201Scene();
        }

        protected override void Initialize()
        {
            input = new PhysXInput();
            camera = new DebugCamera((float)displayWidth / (float)displayHeight, new Vector3(0, 5, -15), MathHelper.ToRadians(60f));
            camera.LookAtPoint = new Vector3(0, 5, -14);

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

            input.Update(gameTime);
            scene.HandleInput(gameTime, input.Input);
            scene.Update(gameTime);
            
            float f = (float)gameTime.ElapsedGameTime.TotalSeconds;

            camera.MoveForward(input.ForwardSpeed() * f * cameraSpeed);
            camera.Strafe(input.StrafeSpeed() * f * cameraSpeed);
            camera.UpDown(input.UpDownSpeed() * f * cameraSpeed);

            camera.Pitch(input.PitchSpeed() * f);
            camera.Yaw(input.YawSpeed() * f);

            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            //frames++;
            //millis += (float)gameTime.ElapsedGameTime.TotalMilliseconds;

            //if (millis >= 1000)
            //{
            //    Console.WriteLine(frames);
            //    frames = 0;
            //    millis = 0;
            //}

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
