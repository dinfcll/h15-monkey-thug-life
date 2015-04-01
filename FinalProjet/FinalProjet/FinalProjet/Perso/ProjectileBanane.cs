using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    public class ProjectileBanane
    {
        AnimationPlayer ProjectileBananeAP;
        Animation BananeAnim;
        Vector2 Position;
        Vector2 AjustementCanon;
        public bool Delete;
        float Speed;
        public Rectangle RecCollision;

        public ProjectileBanane(Vector2 Position, float SpeedProjectile)
        {
            this.Position = Position;
            ProjectileBananeAP = new AnimationPlayer();
            /*Alignement avec canon */
            AjustementCanon = new Vector2(30,-40);
            BananeAnim = new Animation(Ressource.BananeAnim, Ressource.BananeAnim.Width / 8, 0.15f, 1.10f, true);
            Speed = SpeedProjectile;
            RecCollision = new Rectangle(0, 0, Ressource.BananeAnim.Width / 16, Ressource.BananeAnim.Height/2);
        }

        public void Update()
        {
            Position.X += Speed;
            ProjectileBananeAP.PlayAnimation(BananeAnim);

            if (Position.X > 800)
            {
                Delete = true;
            }

            RecCollision.X = (int)(Position.X + AjustementCanon.X - RecCollision.Width/2);
            RecCollision.Y = (int)(Position.Y + AjustementCanon.Y - RecCollision.Height);
        }

        public void Draw(GameTime gametime,SpriteBatch spritebatch)
        {
            ProjectileBananeAP.Draw(gametime, spritebatch, Position + AjustementCanon, SpriteEffects.None);

            if (StaticInfo.DebugTextureActif)
            spritebatch.Draw(Ressource.TestingTexture, RecCollision, Color.Red);
        }

    }
}
