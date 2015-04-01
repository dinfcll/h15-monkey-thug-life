using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    public class Arbre:Drawable
    {
        float Vitesse;
        public float PositionMin = -100;
        public float PositionMax = 900;

        public Arbre(Vector2 Position)
        {
            this.Position = Position;
        }

        public void SetTexture(Texture2D Texture)
        {
            this.Texture = Texture;
        }

        public void Update(LeapLibrary.LeapComponet leap)
        {
            float AjoutVitesse = 0;
            if (leap.FirstHand != null) AjoutVitesse = leap.FirstHand.PalmNormal.Roll * 5;
           
            Vitesse = StaticInfo.InitialSpeed_Arbre - AjoutVitesse;
            if (Vitesse < StaticInfo.InitialSpeed_Arbre)
                Vitesse = StaticInfo.InitialSpeed_Arbre;
           

            Position.X -= Vitesse;

            if (Position.X <= PositionMin)
                Position.X = PositionMax;
        }

        public override void Draw(Microsoft.Xna.Framework.Graphics.SpriteBatch SpriteBatch)
        {
            base.Draw(SpriteBatch);
        }
    }
}
