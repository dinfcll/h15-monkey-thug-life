using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    public class Missile
    {
        AnimationPlayer MissileAP;
        Animation MissileAnimation;
        Vector2 Position;
        int PositionXMin = -200;
        public bool Delete;
        Vector2 DecalageBazooka;
        public Rectangle RecCollision;

        public Missile(Vector2 Position)
        {
            this.Position = Position;
            MissileAP = new AnimationPlayer();
            MissileAnimation = new Animation(Ressource.MissileAnim, Ressource.MissileAnim.Width/2, 0.1f, 1.5f, true);
            DecalageBazooka = new Vector2(-30, -60);
            RecCollision = new Rectangle((int)(Position.X + DecalageBazooka.X), ((int)(Position.Y + DecalageBazooka.Y)), Ressource.MissileAnim.Width / 2, Ressource.MissileAnim.Height);
        }

        public void Update()
        {
            this.Position.X -= StaticInfo.SpeedMissile;
            MissileAP.PlayAnimation(MissileAnimation);
            if (Position.X < PositionXMin)
                Delete = true;

            RecCollision.X = (int)(Position.X + DecalageBazooka.X - RecCollision.Width/2);
            RecCollision.Y = (int)(Position.Y + DecalageBazooka.Y - RecCollision.Height);
        }

        public void Draw(GameTime gametime, SpriteBatch spritebatch)
        {
            MissileAP.Draw(gametime, spritebatch, Position + DecalageBazooka, SpriteEffects.None);
            if (StaticInfo.DebugTextureActif)
                spritebatch.Draw(Ressource.TestingTexture, RecCollision, Color.Azure);
        }
    }
}
