#if!XBOX360
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace XNAPhysX.Input
{
    public enum MouseButtons : int { Left = 0, Right = 1, Middle = 2 }

    public class MouseInput
    {
        private MouseState oldState;
        private MouseState newState;

        public MouseInput()
        {
            oldState = Mouse.GetState();
        }

        public void Update(GameTime gameTime)
        {
            oldState = newState;
            newState = Mouse.GetState();
        }

        public MouseState NewState
        {
            get { return newState; }
        }

        public MouseState OldState
        {
            get { return oldState; }
        }
    }
}
#endif