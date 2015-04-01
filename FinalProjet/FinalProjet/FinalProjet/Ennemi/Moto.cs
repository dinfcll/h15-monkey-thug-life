using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    class Moto:LivingEntity
    {
        Animation ConducteurA, TireurA;
        AnimationPlayer ConducteurAP, TireurAP;
        Vector2 Position;
        int CptDegat;
        public bool Delete;
        Rectangle RecCollision;
        float Scale = 1.5f;
        float SpeedAnimation = 0.05f;
        float DecalageX;
        Vector2 DecalageMotoTireur;

        List<Missile> Missiles;
        float CptTimerMissiles;

        float AvancementX = 200;
        float CptAvancementX = 0;
        Vector2 Decalage = Vector2.Zero;
        float RandomY = 0;

        public Moto(Vector2 Position)
            : base(new Rectangle(0, 0, Ressource.Moto.Width / 4, Ressource.Moto.Height),4)
        {
            ConducteurA = new Animation(Ressource.Moto, Ressource.Moto.Width / 4, SpeedAnimation, Scale, true);
            TireurA = new Animation(Ressource.BazookaNormal, Ressource.BazookaNormal.Width / 4, SpeedAnimation, Scale, true);
            ConducteurAP = new AnimationPlayer();
            TireurAP = new AnimationPlayer();
            DecalageX = StaticInfo.r.Next(0, 50);
            this.Position = Position;
            DecalageMotoTireur = new Vector2(0, -20);
            RecCollision = new Rectangle(0, 0, Ressource.Moto.Width/4, Ressource.Moto.Height);
            Missiles = new List<Missile>();

            SetOffsetWithLife(new Vector2(-30,0));
        }

        public void SetDecalage()
        {
            Decalage = new Vector2(-10, -10);
            Position += Decalage;
        }

        public void Update(ref Monkey SingeJoueur)
        {
            ConducteurAP.PlayAnimation(ConducteurA);
            TireurAP.PlayAnimation(TireurA);

            if (CptAvancementX < AvancementX)
            {
                Position.X -= StaticInfo.SpeedMoto;
                CptAvancementX += StaticInfo.SpeedMoto;
            }

            RandomY += 0.15f;
            Position.Y += (float)Math.Sin(RandomY) * 2;

            for (int i = 0; i < SingeJoueur.ListBananes.Count; i++)
            {
                if (SingeJoueur.ListBananes[i].RecCollision.Intersects(RecCollision))
                {
                    SingeJoueur.ListBananes[i].Delete = true;
                    CptDegat++;
                    ApplyDamage(1);
                }
            }

            CptTimerMissiles += StaticInfo.SpeedTimerMissile;
            if (CptTimerMissiles > 1)
            {
                Missiles.Add(new Missile(Position));
                CptTimerMissiles = 0;
            }

            for (int i = 0; i < Missiles.Count; i++)
            {
                Missiles[i].Update();

                for (int j = 0; j < SingeJoueur.ListBananes.Count; j++)
                {
                    if (SingeJoueur.ListBananes[j].RecCollision.Intersects(Missiles[i].RecCollision))
                    {
                        Missiles[i].Delete = true;
                        SingeJoueur.ListBananes[j].Delete = true;
                    }
                }

                if (Missiles[i].RecCollision.Intersects(SingeJoueur.RecCollision))
                {
                    SingeJoueur.ApplyDamage(StaticInfo.DamageMissile);
                    Missiles[i].Delete = true;
                }

                if (Missiles[i].Delete)
                {
                    Missiles.RemoveAt(i);
                   i--;
                }
            }

            if (CptDegat > 3) Delete = true;

            base.Udpate(RecCollision);
            RecCollision.X = (int)Position.X;
            RecCollision.Y = (int)(Position.Y - RecCollision.Height * 1.5f);
        }

        public void Draw(GameTime gametime, SpriteBatch spritebatch)
        {
            for (int i = 0; i < Missiles.Count; i++)
            {
                Missiles[i].Draw(gametime, spritebatch);
            }
            ConducteurAP.Draw(gametime, spritebatch, Position, SpriteEffects.None);
            TireurAP.Draw(gametime, spritebatch, Position + DecalageMotoTireur, SpriteEffects.None);

            base.Draw(spritebatch);
            
            if (StaticInfo.DebugTextureActif)
                spritebatch.Draw(Ressource.TestingTexture, RecCollision, Color.Yellow);
        }
    }
}
