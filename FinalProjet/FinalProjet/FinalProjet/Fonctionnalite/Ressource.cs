using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    public static class Ressource
    {
        public static Texture2D Arbre1, Arbre2, Arbre3, Arbre4, Nuage1, Nuage2;
        public static Texture2D BananeAnim;
        public static Texture2D BazookaNormal, MissileAnim, Moto;
        public static Texture2D Bordure, VoieSimple;
        public static Texture2D Camion_PorteOuverteD0, Camion_PorteOuverteD1, Camion_PorteOuverteD2, Camion_PorteOuverteD3, Camion_PorteFerme;
        public static Texture2D EyeAnim, FWheel, BWheel, SimpleMonkeyMoto;
        public static Texture2D LifeBarFrame, LifeBarContent;
        public static Texture2D TestingTexture;
        public static SpriteFont Ecriture;
        public static Texture2D Intro;

        public static void Load(ContentManager Content)
        {
            LifeBarFrame = Content.Load<Texture2D>("LifeFrame");
            LifeBarContent = Content.Load<Texture2D>("LifeContent");
            Arbre1 = Content.Load<Texture2D>("Arbre1");
            Arbre2 = Content.Load<Texture2D>("Arbre2");
            Arbre3 = Content.Load<Texture2D>("Arbre3");
            Arbre4 = Content.Load<Texture2D>("Arbre4");
            Nuage1 = Content.Load<Texture2D>("Nuage1");
            Nuage2 = Content.Load<Texture2D>("Nuage2");
            BananeAnim= Content.Load<Texture2D>("BananeAnim");
            BazookaNormal= Content.Load<Texture2D>("BazookaNormalOwnBazooka");
            MissileAnim= Content.Load<Texture2D>("MissileAnim");
            Moto = Content.Load<Texture2D>("MotoNormal");
            Bordure = Content.Load<Texture2D>("Bordure");
            VoieSimple = Content.Load<Texture2D>("VoieSimple");
            Camion_PorteOuverteD0 = Content.Load<Texture2D>("Camion_PorteOuverteD0");
            Camion_PorteOuverteD1 = Content.Load<Texture2D>("Camion_PorteOuverteD1");
            Camion_PorteOuverteD2 = Content.Load<Texture2D>("Camion_PorteOuverteD2"); 
            Camion_PorteOuverteD3 = Content.Load<Texture2D>("Camion_PorteOuverteD3");
            Camion_PorteFerme = Content.Load<Texture2D>("Camion_PorteFerme");
            EyeAnim = Content.Load<Texture2D>("EyeA"); 
            FWheel= Content.Load<Texture2D>("FWheelA");
            BWheel = Content.Load<Texture2D>("BWheelA");
            SimpleMonkeyMoto = Content.Load<Texture2D>("Moto1");
            TestingTexture = Content.Load<Texture2D>("Texture");
            Ecriture = Content.Load<SpriteFont>("SpriteFont1");
            Intro = Content.Load<Texture2D>("Intro_Image");
        }
    }
}
