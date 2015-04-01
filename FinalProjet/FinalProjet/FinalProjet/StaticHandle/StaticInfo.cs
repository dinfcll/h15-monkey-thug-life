using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;

namespace FinalProjet
{
    public static class StaticInfo
    {
        public static float InitialSpeed_Bordure = 8;
        public static float InitialSpeed_Arbre = 7;
        public static float InitialSpeed_Nuage = 5;

        public static Vector2 LimiteSup = new Vector2(750, 390);
        public static Vector2 LimiteInf = new Vector2(50, 255);
        public static Random r = new Random();

        public static int NbCamionMax = 3;
        public static float cptTimerApparitionCamion;
        public static float SpeedCamion = 3;
        public static float SpeedApparitionCamion = 0.02f;
        public static int LimiteXCamion = 600;

        public static float SpeedApparitionMoto = 0.10f;
        public static float SpeedMoto = 1;

        public static float MonkeySpeedBanane = 10;
        public static float cptTimerProjectile = 0;
        public static float SpeedTimerProjectile = 0.20f;


        public static float SpeedMissile = 4f;
        public static float SpeedTimerMissile = 0.005f;
        public static float DamageMissile = 3;

        public static float PlayerLife;
        public static float AnimFinScale;

        public static bool DebugTextureActif = false;
    }
}
