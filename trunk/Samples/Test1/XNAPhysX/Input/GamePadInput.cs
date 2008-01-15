using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace XnaPhysX.Input
{
    public class GamePadInput
    {
        private Dictionary<PlayerIndex, GamePadState> oldStates;
        private Dictionary<PlayerIndex, GamePadState> newStates;

        public GamePadInput()
        {
            oldStates = new Dictionary<PlayerIndex, GamePadState>();
            oldStates.Add(PlayerIndex.One, GamePad.GetState(PlayerIndex.One));
            oldStates.Add(PlayerIndex.Two, GamePad.GetState(PlayerIndex.Two));
            oldStates.Add(PlayerIndex.Three, GamePad.GetState(PlayerIndex.Three));
            oldStates.Add(PlayerIndex.Four, GamePad.GetState(PlayerIndex.Four));

            newStates = new Dictionary<PlayerIndex, GamePadState>();
            newStates.Add(PlayerIndex.One, GamePad.GetState(PlayerIndex.One));
            newStates.Add(PlayerIndex.Two, GamePad.GetState(PlayerIndex.Two));
            newStates.Add(PlayerIndex.Three, GamePad.GetState(PlayerIndex.Three));
            newStates.Add(PlayerIndex.Four, GamePad.GetState(PlayerIndex.Four));
        }

        public void Update(GameTime gameTime)
        {
            oldStates[PlayerIndex.One] = newStates[PlayerIndex.One];
            oldStates[PlayerIndex.Two] = newStates[PlayerIndex.Two];
            oldStates[PlayerIndex.Three] = newStates[PlayerIndex.Three];
            oldStates[PlayerIndex.Four] = newStates[PlayerIndex.Four];

            newStates[PlayerIndex.One] = GamePad.GetState(PlayerIndex.One);
            newStates[PlayerIndex.Two] = GamePad.GetState(PlayerIndex.Two);
            newStates[PlayerIndex.Three] = GamePad.GetState(PlayerIndex.Three);
            newStates[PlayerIndex.Four] = GamePad.GetState(PlayerIndex.Four);
        }

        public GamePadState GetNewState(PlayerIndex index)
        {
            return newStates[index];
        }

        public GamePadState GetOldState(PlayerIndex index)
        {
            return oldStates[index];
        }
    }
}
