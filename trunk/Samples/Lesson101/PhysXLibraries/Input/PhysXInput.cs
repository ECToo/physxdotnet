using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using XnaPhysX.Input;

namespace XnaPhysX.Input
{
    public class PhysXInput
    {
        private GameInput input;

        private Keys moveForwardK = Keys.W;
        private Keys moveLeftK = Keys.A;
        private Keys moveRightK = Keys.D;
        private Keys moveBackK = Keys.S;
        private Keys moveUpK = Keys.Q;
        private Keys moveDownK = Keys.Z;
        private Keys pitchForwardK = Keys.Up;
        private Keys pitchBackwardK = Keys.Down;
        private Keys yawLeftK = Keys.Left;
        private Keys yawRightK = Keys.Right;
        private Keys rollLeftK = Keys.E;
        private Keys rollRightK = Keys.R;

        public GameInput Input
        {
            get { return input; }
        }

        
        public PhysXInput()
        {
            input = new GameInput();
        }

        public void Update(GameTime gameTime)
        {
            input.Update(gameTime);
        }

        public float ForwardSpeed()
        {
            float speed = input.Pads.GetNewState(PlayerIndex.One).ThumbSticks.Left.Y;

            if(input.Keyboard.NewState.IsKeyDown(moveForwardK))
                speed++;
            if(input.Keyboard.NewState.IsKeyDown(moveBackK))
                speed--;
            
            return speed;
        }

        public float StrafeSpeed()
        {
            float speed = input.Pads.GetNewState(PlayerIndex.One).ThumbSticks.Left.X;

            if (input.Keyboard.NewState.IsKeyDown(moveLeftK))
                speed--;
            if (input.Keyboard.NewState.IsKeyDown(moveRightK))
                speed++;

            return speed;
        }

        public float UpDownSpeed()
        {
            float speed = 0;

            if (input.Pads.GetNewState(PlayerIndex.One).Buttons.RightShoulder == ButtonState.Pressed)
                speed++;
            if (input.Pads.GetNewState(PlayerIndex.One).Buttons.LeftShoulder == ButtonState.Pressed)
                speed--;

            if (input.Keyboard.NewState.IsKeyDown(moveUpK))
                speed++;
            if (input.Keyboard.NewState.IsKeyDown(moveDownK))
                speed--;

            return speed;            
        }

        public float PitchSpeed()
        {
            float pitch = input.Pads.GetNewState(PlayerIndex.One).ThumbSticks.Right.Y;

            if (input.Keyboard.NewState.IsKeyDown(pitchForwardK))
                pitch--;
            if (input.Keyboard.NewState.IsKeyDown(pitchBackwardK))
                pitch++;

            return pitch;
        }

        public float YawSpeed()
        {
            float yaw = input.Pads.GetNewState(PlayerIndex.One).ThumbSticks.Right.X;

            if (input.Keyboard.NewState.IsKeyDown(yawLeftK))
                yaw--;
            if (input.Keyboard.NewState.IsKeyDown(yawRightK))
                yaw++;

            return yaw;
        }

        public float RollSpeed()
        {
            float roll = 0;

            if (input.Keyboard.NewState.IsKeyDown(rollLeftK))
                roll--;
            if (input.Keyboard.NewState.IsKeyDown(rollRightK))
                roll++;

            roll -= input.Pads.GetNewState(PlayerIndex.One).Triggers.Left;
            roll += input.Pads.GetNewState(PlayerIndex.One).Triggers.Right;

            return roll;
        }

        private bool ButtonClicked(Buttons b)
        {
            return input.Pads.GetOldState(PlayerIndex.One).IsButtonUp(b) &&
                    input.Pads.GetNewState(PlayerIndex.One).IsButtonDown(b);
        }

        private bool KeyClicked(Keys k)
        {
            return input.Keyboard.OldState.IsKeyUp(k) && input.Keyboard.NewState.IsKeyDown(k);
        }
    }
}
