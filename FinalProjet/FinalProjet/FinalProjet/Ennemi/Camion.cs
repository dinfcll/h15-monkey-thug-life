using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    class Camion:LivingEntity
    {
        Animation CamionPOD0;
        Animation CamionPOD1;
        Animation CamionPOD2;
        Animation CamionPOD3;
        Animation CamionPF;
        AnimationPlayer CamionAP;
        Vector2 Position;
        int CptDegat;
        public bool Delete;
        float SpeedAnim = 0.05f;
        float Scale = 1.60f;
        float DecalageX;
        Rectangle RecCollision;
        int MotoMax = 3;
        List<Moto> Motos;

        float cptTimerMotos;
        bool ArriveADestination = false;
        float RandomY;

        public Camion()
            :base(new Rectangle(0, 0, Ressource.Camion_PorteOuverteD0.Width / 4, Ressource.Camion_PorteOuverteD0.Height),40)
        {
            CamionPOD0 = new Animation(Ressource.Camion_PorteOuverteD0, Ressource.Camion_PorteOuverteD0.Width / 4, SpeedAnim, Scale, true);
            CamionPOD1 = new Animation(Ressource.Camion_PorteOuverteD1, Ressource.Camion_PorteOuverteD1.Width / 4, SpeedAnim, Scale, true);
            CamionPOD2 = new Animation(Ressource.Camion_PorteOuverteD2, Ressource.Camion_PorteOuverteD2.Width / 4, SpeedAnim, Scale, true);
            CamionPOD3 = new Animation(Ressource.Camion_PorteOuverteD3, Ressource.Camion_PorteOuverteD3.Width / 4, SpeedAnim, Scale, true);
            CamionPF = new Animation(Ressource.Camion_PorteFerme, Ressource.Camion_PorteOuverteD0.Width / 4, SpeedAnim, Scale, true);
            CamionAP = new AnimationPlayer();
            CptDegat = 0;

            Position.X = StaticInfo.LimiteSup.X + StaticInfo.r.Next(100, 200);
            Position.Y = StaticInfo.LimiteInf.Y + StaticInfo.r.Next(50, 160);
            DecalageX = StaticInfo.r.Next(0, 50);
            RecCollision = new Rectangle(0, 0, Ressource.Camion_PorteOuverteD0.Width / 4, Ressource.Camion_PorteOuverteD0.Height);
            Motos = new List<Moto>();
            SetOffsetWithLife(new Vector2(0, -30));
        }

        public void Update(ref Monkey SingeJoueur)
        {
            if(!ArriveADestination)
                Position.X -= StaticInfo.SpeedCamion;

            if (Position.X < StaticInfo.LimiteXCamion + DecalageX && ArriveADestination == false)
            {
                Position.X = StaticInfo.LimiteXCamion + DecalageX;
                ArriveADestination = true;
            }

            RandomY+= 0.15f;
            Position.Y += (float)Math.Sin(RandomY) * 2;


            for (int i = 0; i < SingeJoueur.ListBananes.Count; i++)
            {
                if (SingeJoueur.ListBananes[i].RecCollision.Intersects(RecCollision))
                {
                    SingeJoueur.ListBananes[i].Delete = true;
                    CptDegat++;
                    ApplyDamage(1);
                    if (Life.CurrentLife < 0) Delete = true;
                }
            }

            switch (CptDegat)
            {
                case 0: CamionAP.PlayAnimation(CamionPOD0); break;
                case 5: CamionAP.PlayAnimation(CamionPOD1); break;
                case 10: CamionAP.PlayAnimation(CamionPOD2); break;
                case 15: CamionAP.PlayAnimation(CamionPOD3); break;
                case 20: Delete = true; break;
            }


            RecCollision.X = ((int)(Position.X - RecCollision.Width/2));
            RecCollision.Y = ((int)(Position.Y - RecCollision.Height));

            if (ArriveADestination && Motos.Count < MotoMax)
            {
                cptTimerMotos += StaticInfo.SpeedApparitionMoto;
                if (cptTimerMotos > 1)
                {
                    cptTimerMotos = 0;
                    Motos.Add(new Moto(Position));
                    Motos[Motos.Count - 1].SetDecalage();
                }
            }

            for (int i = 0; i < Motos.Count; i++)
            {
                Motos[i].Update(ref SingeJoueur);
                if (Motos[i].Delete)
                {
                    Motos.RemoveAt(i);
                    i--;
                }
            }
            base.Udpate(RecCollision);
        }

        public void Draw(GameTime gametime, SpriteBatch spritebatch)
        {
            for (int i = 0; i < Motos.Count; i++)
            {
                Motos[i].Draw(gametime, spritebatch);
            }
            CamionAP.Draw(gametime, spritebatch, Position, SpriteEffects.None);
         
            base.Draw(spritebatch);
            if (StaticInfo.DebugTextureActif)
            spritebatch.Draw(Ressource.TestingTexture, RecCollision, Color.Blue);
        }
    }
}
