using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace XnaPhysX.Input
{
    public class GameInput
    {
        GamePadInput pads;
        KBInput keyboard;
#if!XBOX360        
        MouseInput mouse;
#endif

        public GameInput()
        {
            pads = new GamePadInput();
            keyboard = new KBInput();
            
#if!XBOX360
            mouse = new MouseInput();
#endif
        }

        public void Update(GameTime gameTime)
        {
            pads.Update(gameTime);
            keyboard.Update(gameTime);
#if!XBOX360
            mouse.Update(gameTime);
#endif
        }

        public GamePadInput Pads
        {
            get { return pads; }
        }

        public KBInput Keyboard
        {
            get { return keyboard; }
        }

#if!XBOX360
        public MouseInput Mouse
        {
            get { return mouse; }
        }
#endif
    }
}
