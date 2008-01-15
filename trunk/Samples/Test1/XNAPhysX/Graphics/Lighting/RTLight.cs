using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace XNAPhysX.Graphics.Lighting
{
    public abstract class RTLight
    {
        protected Vector4 lightColour;

        public RTLight()
        {
            lightColour = Color.White.ToVector4();
        }

        public abstract Vector3 GetPosition();

        public Vector4 Colour
        {
            get { return lightColour; }
            set { lightColour = value; }
        }

        public void GetLightColour(out Vector4 colour)
        {
            colour = lightColour;
        }
    }
}