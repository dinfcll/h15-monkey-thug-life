using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;

namespace FinalProjet
{
    class Voie:Drawable
    {
        int NbBordures;
        Rectangle RecDestination;
        Bordure[] TabBordure;
        Arbre[] GrandsArbre;
        Arbre[] PetitsArbre;
      
        int EcartEntreBordure;
        int EcartEntreGrandArbres;
        int EcartEntrePetitsArbres;

        public Voie(Vector2 Position, int NbBordures)
        {
            this.Position = Position;
            Texture = Ressource.VoieSimple;
            this.NbBordures = NbBordures;

            TabBordure = new Bordure[NbBordures];
            GrandsArbre = new Arbre[5];
            PetitsArbre = new Arbre[3];
           
            EcartEntreBordure = 100;
            EcartEntreGrandArbres = 250;
            EcartEntrePetitsArbres = 350;

            RecDestination.X = (int)Position.X;
            RecDestination.Y = (int)Position.Y;
            RecDestination.Width = 800;
            RecDestination.Height = 150;

            for (int i = 0; i < NbBordures; i++)
            {
                TabBordure[i] = new Bordure(new Vector2(Position.X + (EcartEntreBordure * i), Position.Y + RecDestination.Height * 0.45f));
            }

            Random r = new Random();
            for (int i = 0; i < GrandsArbre.Length; i++)
            {
                GrandsArbre[i] = new Arbre(new Vector2(Position.X + (EcartEntreGrandArbres * i), Position.Y - RecDestination.Height));
                switch (r.Next(2))
                {
                    case 0: GrandsArbre[i].SetTexture(Ressource.Arbre1); break;
                    case 1: GrandsArbre[i].SetTexture(Ressource.Arbre2); break;
                }
            }

            for (int i = 0; i < PetitsArbre.Length; i++)
            {
                PetitsArbre[i] = new Arbre(new Vector2(Position.X + (EcartEntrePetitsArbres * i), Position.Y + RecDestination.Height * 0.70f));
                switch (r.Next(2))
                {
                    case 0: PetitsArbre[i].SetTexture(Ressource.Arbre3); break;
                    case 1: PetitsArbre[i].SetTexture(Ressource.Arbre4); break;
                }
            }

           

            GrandsArbre[1].SetTexture(Ressource.Arbre1);
            GrandsArbre[3].SetTexture(Ressource.Arbre2);
        }

        public void Update(LeapLibrary.LeapComponet leap)
        {
            for (int i = 0; i < NbBordures; i++)
            {
                TabBordure[i].Update(leap);
                if (i > 0) /* Probleme de decalage quand trop rapide */
                {
                    Bordure LastBordure = TabBordure[i - 1];
                    Bordure CurrentBordure = TabBordure[i];

                    float DistanceX = Math.Abs(LastBordure.Position.X - CurrentBordure.Position.X);
                    if ((DistanceX > EcartEntreBordure || DistanceX < EcartEntreBordure) && DistanceX < CurrentBordure.PositionMax)
                    {
                        TabBordure[i].Position.X += EcartEntreBordure - DistanceX;
                    }
                }
            }

            for (int i = 0; i < GrandsArbre.Length; i++)
            {
                GrandsArbre[i].Update(leap);
                if (i > 0)
                {
                    Arbre LastArbre = GrandsArbre[i - 1];
                    Arbre CurrentArbre = GrandsArbre[i];

                    float DistanceX = Math.Abs(LastArbre.Position.X - CurrentArbre.Position.X);
                    if ((DistanceX > EcartEntreGrandArbres || DistanceX < EcartEntreGrandArbres) && DistanceX < 700)
                    {
                        GrandsArbre[i].Position.X += EcartEntreGrandArbres - DistanceX;
                    }
                }
            }

            for (int i = 0; i < PetitsArbre.Length; i++)
            {
                PetitsArbre[i].Update(leap);
                if (i > 0)
                {
                    Arbre LastArbre = PetitsArbre[i - 1];
                    Arbre CurrentArbre = PetitsArbre[i];

                    float DistanceX = Math.Abs(LastArbre.Position.X - CurrentArbre.Position.X);
                    if ((DistanceX > EcartEntrePetitsArbres || DistanceX < EcartEntrePetitsArbres) && DistanceX < CurrentArbre.PositionMax && DistanceX < 600)
                    {
                        PetitsArbre[i].Position.X += EcartEntrePetitsArbres - DistanceX;
                    }
                }
            }
        }

        public override void Draw(Microsoft.Xna.Framework.Graphics.SpriteBatch SpriteBatch)
        {
            SpriteBatch.Draw(Texture, RecDestination, Color.White);
            for (int i = 0; i < NbBordures; i++)
            {
                TabBordure[i].Draw(SpriteBatch);
            }

            for (int i = 0; i < GrandsArbre.Length; i++)
            {
                GrandsArbre[i].Draw(SpriteBatch);
            }

            for (int i = 0; i < PetitsArbre.Length; i++)
            {
                PetitsArbre[i].Draw(SpriteBatch);
            }
        }
    }
}
