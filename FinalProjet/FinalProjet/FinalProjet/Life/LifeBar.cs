using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace FinalProjet
{
    public class LifeBar
    {
        float MaxLife;
        public float CurrentLife;
        float Ratio;
        Rectangle RecSource,RecLife;
        Vector2 Offset;

        public LifeBar(Rectangle RecSource, float MaxLife)
        {
            RecSource.Height = Ressource.LifeBarFrame.Height/2;
            RecSource.Width = Ressource.LifeBarFrame.Width / 2;
            this.MaxLife = MaxLife;
            CurrentLife = MaxLife;
            this.RecSource = RecSource;
            RecLife = RecSource;
            Ratio = CurrentLife / MaxLife;
        }

        public void ApplyDamage(float Damage)
        {
            CurrentLife -= Damage;
            Ratio = CurrentLife / MaxLife;
            RecLife.Width = (int)(RecSource.Width * Ratio);
        }

        public void SetOffset(Vector2 Offset)
        {
            this.Offset = Offset;
        }

        public void Update(Rectangle RecSource)
        {
            this.RecSource.X = (int)(RecSource.X + Offset.X);
            this.RecSource.Y = (int)(RecSource.Y + Offset.Y);
            RecLife.X = this.RecSource.X;
            RecLife.Y = this.RecSource.Y;
        }

        public void Draw(SpriteBatch spritebatch)
        {
            if (RecLife.X > 0 && RecLife.Y > 150)
            {
                if (Ratio > 0.25f)
                    spritebatch.Draw(Ressource.LifeBarContent, RecLife, Color.GreenYellow);
                else
                    spritebatch.Draw(Ressource.LifeBarContent, RecLife, Color.OrangeRed);
                spritebatch.Draw(Ressource.LifeBarFrame, RecSource, Color.Black);
            } 
        }
    }
}
