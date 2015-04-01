using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    public class LivingEntity
    {
        public LifeBar Life;

        public LivingEntity(Rectangle RecSource,float MaxLife)
        {
            Life = new LifeBar(RecSource, MaxLife);
        }

        public virtual void Udpate(Rectangle RecSource)
        {
            Life.Update(RecSource);
        }

        public void SetOffsetWithLife(Vector2 Offset)
        {
            Life.SetOffset(Offset);
        }

        public virtual void ApplyDamage(float Damage)
        {
            Life.ApplyDamage(Damage);
        }

        public virtual void Draw(SpriteBatch spritebatch)
        {
            Life.Draw(spritebatch);
        }
    }
}
