using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;

namespace FinalProjet
{
    class Bordure:Drawable
    {
        float Vitesse;
        public float PositionMax = 800;
        public float PositionMin = -100;

        public Bordure(Vector2 Position)
        {
            this.Position = Position;
            Texture = Ressource.Bordure;
        }

        public void Update(LeapLibrary.LeapComponet leap)
        {
            //float AjoutVitesse = leap.FirstHand.PalmNormal.Roll / 55.0f;
            float AjoutVitesse = 0;

            if (leap.FirstHand != null) AjoutVitesse = leap.FirstHand.PalmNormal.Roll * 5;
           
            Vitesse = StaticInfo.InitialSpeed_Bordure - AjoutVitesse;
            if (Vitesse < StaticInfo.InitialSpeed_Bordure)
                Vitesse = StaticInfo.InitialSpeed_Bordure;

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
