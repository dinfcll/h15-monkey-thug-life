using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace FinalProjet
{
    public class Drawable
    {
        public Vector2 Position;
        public Texture2D Texture;

        public virtual void Draw(SpriteBatch SpriteBatch)
        {
            SpriteBatch.Draw(Texture, Position, Color.White);
        }
    }
}
