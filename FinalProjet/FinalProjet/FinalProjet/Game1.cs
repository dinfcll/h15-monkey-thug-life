using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using LeapLibrary;
using Leap;

namespace FinalProjet
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        LeapComponet leap;

        SpriteFont font;
        Voie Voie;
        Nuage[] Nuages; float EcartNuage = 150;
        List<Camion> TabCamion;
        bool TousCamionsEnJeu;
        bool Debut = true;
        bool Win = false;
        Monkey SingeDeLaMort;
        Color loseColor;


        bool Intro = true;
        float TimerIntro;
        
        //Anim Fin
        AnimationPlayer AnimFinAP = new AnimationPlayer();
        Animation BananeAnim;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";

            leap = new LeapComponet(this);
            this.Components.Add(leap);
        }


        protected override void Initialize()
        {
            Nuages = new Nuage[7];
            loseColor = Color.Red;
            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            Ressource.Load(Content);
            font = Content.Load<SpriteFont>("SpriteFont1");
            Voie = new Voie(new Vector2(0, 250), 15);
            SingeDeLaMort = new Monkey(new Vector2(Voie.Position.X + 100, Voie.Position.Y + 100));
            TabCamion = new List<Camion>();

            for (int i = 0; i < Nuages.Length; i++)
            {
                Nuages[i] = new Nuage(new Vector2(EcartNuage * i, StaticInfo.r.Next(0, 400)));
                switch (StaticInfo.r.Next(2))
                {
                    case 0: Nuages[i].SetTexture(Ressource.Nuage1); break;
                    case 1: Nuages[i].SetTexture(Ressource.Nuage2); break;
                }
            }

            Nuages[0].Position.Y = 50;
            BananeAnim = new Animation(Ressource.BananeAnim, Ressource.BananeAnim.Width / 8, 0.15f, 1, true); 
        }

        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            if (Intro)
            {
                TimerIntro++;
                if (TimerIntro > 200) Intro = false;
            }
            else
            {
                if (Debut)
                {
                    //UPDATE CONTROLLER
                    leap.Update(gameTime);

                    //UPDATE ENVIRONNEMENT
                    Voie.Update(leap);

                    //UPDATE JOUEUR
                    SingeDeLaMort.Update(leap);

                    //UPDATE NUAGE
                    for (int i = 0; i < Nuages.Length; i++)
                    {
                        Nuages[i].Update(leap);
                    }

                    //UPDATE CAMION
                    for (int i = 0; i < TabCamion.Count; i++)
                    {
                        TabCamion[i].Update(ref SingeDeLaMort);
                        if (TabCamion[i].Delete)
                        {
                            TabCamion.RemoveAt(i);
                            i--;
                        }
                    }
                }
                else
                {
                    StaticInfo.AnimFinScale += 0.05f;

                    if (Win)
                    {
                        if (SingeDeLaMort.ListBananes.Count > 0) SingeDeLaMort.ListBananes.RemoveAt(SingeDeLaMort.ListBananes.Count - 1);

                        if (StaticInfo.AnimFinScale < 10)
                            BananeAnim.Resize = StaticInfo.AnimFinScale;

                        AnimFinAP.PlayAnimation(BananeAnim);
                    }
                    else
                    {
                        StaticInfo.AnimFinScale += 0.25f;
                        //loseColor.A+= 3;
                        loseColor.R = 255;
                        loseColor.G += 3;
                        loseColor.B += 3;
                    }
                }

                //NB MAX CAMION
                if (TabCamion.Count < StaticInfo.NbCamionMax && TousCamionsEnJeu == false)
                {
                    StaticInfo.cptTimerApparitionCamion += StaticInfo.SpeedApparitionCamion;
                    if (StaticInfo.cptTimerApparitionCamion > 1)
                    {
                        TabCamion.Add(new Camion());
                        StaticInfo.cptTimerApparitionCamion = 0;
                    }
                }
                else
                    TousCamionsEnJeu = true;

                if ((TabCamion.Count == 0 && TousCamionsEnJeu) || SingeDeLaMort.Life.CurrentLife <= 0)
                {
                    if (SingeDeLaMort.Life.CurrentLife <= 0) Win = false;
                    else Win = true;

                    Debut = false;
                }
            }
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {

            GraphicsDevice.Clear(Color.Green);
            spriteBatch.Begin();

            if (Intro)
            {
                spriteBatch.Draw(Ressource.Intro, new Rectangle(0, 0, 840, 480), Color.White);
            }
            else
            {
                //DESSIN ENVIRONNEMENT
                Voie.Draw(spriteBatch);

                //DESSIN JOUEUR
                SingeDeLaMort.Draw(gameTime, spriteBatch);

                //DESSIN NUAGES
                for (int i = 0; i < Nuages.Length; i++)
                {
                    Nuages[i].Draw(spriteBatch);
                }

                //DESSSIN CAMION
                for (int i = 0; i < TabCamion.Count; i++)
                {
                    TabCamion[i].Draw(gameTime, spriteBatch);
                }

                if (!Debut)
                {
                    AnimFinAP.Draw(gameTime, spriteBatch, new Vector2(graphics.PreferredBackBufferWidth / 2, graphics.PreferredBackBufferHeight / 2), SpriteEffects.None);
                    if (StaticInfo.AnimFinScale > 9)
                    {
                        if (Win)
                            spriteBatch.DrawString(Ressource.Ecriture, "YOU WIN !!!", new Vector2(250, 250), Color.Orange);
                    }

                    if (!Win)
                    {
                        spriteBatch.DrawString(Ressource.Ecriture, "YOU LOOSE !!!", new Vector2(250, 250), loseColor);
                    }

                }


            }

            spriteBatch.End();
            base.Draw(gameTime);
        }
    }
}
