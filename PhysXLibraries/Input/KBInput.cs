using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace XnaPhysX.Input
{
    public class KBInput
    {
        private KeyboardState oldState;
        private KeyboardState newState;

        public KBInput()
        {
            oldState = Keyboard.GetState();
        }

        public void Update(GameTime gameTime)
        {
            oldState = newState;
            newState = Keyboard.GetState();
        }

        public KeyboardState NewState
        {
            get { return newState; }
        }

        public KeyboardState OldState
        {
            get { return oldState; }
        }
    }
}
