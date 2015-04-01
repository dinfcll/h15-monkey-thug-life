using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace FinalProjet
{
    public class Monkey:LivingEntity
    {
        Animation PersoA, FWheelA, BWheelA, YeuxA;
        AnimationPlayer FWheelAP, BWheelAP, PlayerAP, YeuxAP;
        Vector2 Position;

        Vector2 DecalageRoueAvant, DecalageRoueArriere, DecalageYeux;
        public List<ProjectileBanane> ListBananes;

        float Scale = 0.70f;
        float SpeedAnim = 0.05f;
        public Rectangle RecCollision;

        public Monkey(Vector2 Position)
            :base(new Rectangle(0, 0, Ressource.SimpleMonkeyMoto.Width, Ressource.SimpleMonkeyMoto.Height),100)
        {
            PersoA = new Animation(Ressource.SimpleMonkeyMoto, Ressource.SimpleMonkeyMoto.Width, 0.1f, Scale, true);
            FWheelA = new Animation(Ressource.FWheel, Ressource.FWheel.Width / 8, SpeedAnim, Scale, true);
            BWheelA = new Animation(Ressource.BWheel, Ressource.BWheel.Width / 8, SpeedAnim, Scale, true);
            YeuxA = new Animation(Ressource.EyeAnim, Ressource.EyeAnim.Width / 4, SpeedAnim, Scale, true);

            this.Position = Position;

            DecalageRoueAvant = new Vector2(30, 10);
            DecalageRoueArriere = new Vector2(-32, 17);
            DecalageYeux = new Vector2(-20, -60);
            ListBananes = new List<ProjectileBanane>();
            RecCollision = new Rectangle(0, 0, Ressource.SimpleMonkeyMoto.Width, Ressource.SimpleMonkeyMoto.Height);
            PlayerAP = new AnimationPlayer();

            SetOffsetWithLife(new Vector2(+30, +20));
            StaticInfo.PlayerLife = Life.CurrentLife;
        }

        public void Update(LeapLibrary.LeapComponet leap)
        {
            if (leap.FirstHand != null)
            {
                Position.X = (leap.FirstHand.PalmPosition.x / 120.0f) * 900;
                Position.Y = (leap.FirstHand.PalmPosition.z / 130.0f) * 900;

                for (int i = 0; i < leap.Gestures.Count; i++)
                {
                    Leap.Gesture gesture = leap.Gestures[i];

                    switch (gesture.Type)
                    {
                        case Leap.Gesture.GestureType.TYPECIRCLE:
                            StaticInfo.cptTimerProjectile += StaticInfo.SpeedTimerProjectile;
                            if (StaticInfo.cptTimerProjectile > 1.0f)
                            {
                                StaticInfo.cptTimerProjectile = 0;
                                ListBananes.Add(new ProjectileBanane(Position, StaticInfo.MonkeySpeedBanane));
                            }
                            break;
                    }
                }

            }

            
            Position.X += Convert.ToInt32(Keyboard.GetState().IsKeyDown(Keys.D)) * 15;
            Position.X -= Convert.ToInt32(Keyboard.GetState().IsKeyDown(Keys.A)) * 15;
            Position.Y += Convert.ToInt32(Keyboard.GetState().IsKeyDown(Keys.S)) * 15;
            Position.Y -= Convert.ToInt32(Keyboard.GetState().IsKeyDown(Keys.W)) * 15;

            if (Position.X < StaticInfo.LimiteInf.X)
                Position.X = StaticInfo.LimiteInf.X;
            if (Position.Y < StaticInfo.LimiteInf.Y)
                Position.Y = StaticInfo.LimiteInf.Y;
            if (Position.X > StaticInfo.LimiteSup.X)
                Position.X = StaticInfo.LimiteSup.X;
            if (Position.Y > StaticInfo.LimiteSup.Y)
                Position.Y = StaticInfo.LimiteSup.Y;

            //if(leap.FirstHand.pal->RPalmStrength > 0.75f)
            //if (leap.FirstHand.Finger(1).IsValid )

            for (int i = 0; i < ListBananes.Count; i++)
            {
                ListBananes[i].Update();
                if (ListBananes[i].Delete)
                {
                    ListBananes.RemoveAt(i);
                    i--;
                }
            }

            RecCollision.X = ((int)Position.X - RecCollision.Width/2);
            RecCollision.Y = ((int)Position.Y - RecCollision.Height);

            FWheelAP.PlayAnimation(FWheelA);
            BWheelAP.PlayAnimation(BWheelA);
            PlayerAP.PlayAnimation(PersoA);
            YeuxAP.PlayAnimation(YeuxA);

            base.Udpate(RecCollision);
        }


        public void Draw(GameTime gametime, SpriteBatch spritebatch)
        {
            FWheelAP.Draw(gametime, spritebatch, new Vector2(Position.X + DecalageRoueAvant.X, Position.Y + DecalageRoueAvant.Y), SpriteEffects.None);
            BWheelAP.Draw(gametime, spritebatch, new Vector2(Position.X + DecalageRoueArriere.X, Position.Y + DecalageRoueArriere.Y), SpriteEffects.None);
            PlayerAP.Draw(gametime, spritebatch, new Vector2(Position.X, Position.Y), SpriteEffects.None);
            YeuxAP.Draw(gametime, spritebatch, new Vector2(Position.X + DecalageYeux.X, Position.Y + DecalageYeux.Y), SpriteEffects.None);

            for (int i = 0; i < ListBananes.Count; i++)
            {
                ListBananes[i].Draw(gametime, spritebatch);
            }

            base.Draw(spritebatch);
            if (StaticInfo.DebugTextureActif) spritebatch.Draw(Ressource.TestingTexture, RecCollision, Color.Orange);
        }
    }
}


