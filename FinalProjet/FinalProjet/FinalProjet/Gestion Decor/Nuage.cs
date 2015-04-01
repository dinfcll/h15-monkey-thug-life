using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FinalProjet
{
    public class Nuage:Drawable
    {
        float Vitesse;
        public float PositionMin = -100f;
        public float PositionMax = 900f;

        public Nuage(Vector2 Position)
        {
            this.Position = Position;
        }

        public void Update(LeapLibrary.LeapComponet leap)
        {
            float AjoutVitesse = 0;

            if (leap.FirstHand != null) AjoutVitesse = leap.FirstHand.PalmNormal.Roll * 3;
          
           Vitesse = StaticInfo.InitialSpeed_Nuage - AjoutVitesse;
           if (Vitesse < StaticInfo.InitialSpeed_Nuage)
               Vitesse = StaticInfo.InitialSpeed_Nuage;

            Position.X -= Vitesse;

            if (Position.X <= PositionMin)
                Position.X = PositionMax;
        }

        public void SetTexture(Texture2D Texture)
        {
            this.Texture = Texture;
        }

        public override void  Draw(SpriteBatch SpriteBatch)
        {
 	        base.Draw(SpriteBatch);
        }
    }
}
