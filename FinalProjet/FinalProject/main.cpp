#include <iostream>
#include <string.h>
#include "LeapMotion\LeapListener.h"
#include "include\Leap.h"
#include "Fonctionnalite\BaseFunc.h"
#include "Fonctionnalite\BaseFunc.h"
#include "GestionRoute\Voie.h"
#include "Perso\Monkey.h"
#include "GestionDecor\Nuage.h"
#include "GestionDecor\Arbre.h"
#include "Ennemi\GestionCamion\Camion.h"
#include "Ennemi\GestionMoto\Moto.h"
#include "Ennemi\GestionMissile\Missile.h"

using namespace Leap;
using namespace std;

//Screen dimension constants
#ifdef _WIN32
#undef main
#endif

SDL_Window* window = NULL;
SDL_Surface* SurfaceDessin = NULL;
SDL_Surface* TextureCharge = NULL;
Ressource Ressources = Ressource();
float VitessePerso = 0.5f;
float CptVitesse = 0;
float VitesseTransparence = 0.5f;
float CptTransparence = 0;


Voie* Testvoie = new Voie(-100,200,15, 4, Ressources);
Arbre* Testarbre = new Arbre(30,60,2,Ressources,1);
Arbre* Testarbre2 = new Arbre(1000,60,2,Ressources,1);
Arbre* Testarbrebas = new Arbre(300,60,2,Ressources,2);
Arbre* Testarbrebas2 = new Arbre(1300,60,2,Ressources,2);

Monkey* MonkeyJoueur = new Monkey(0,100,Ressources);
Nuage* Testnuage = new Nuage(50,20,1,Ressources);
Nuage* Testnuage2 = new Nuage(1000,20,1,Ressources);

Camion* CamionEnnemi = new Camion(50,155,Ressources);
Moto* MotoEnnemi2 = new Moto(400,150,Ressources);
Missile* MissileTest = new Missile(450,190,Ressources);

int main(int argc, char* args[])
{
	Uint32 ColorBg[4] = {0x00,0x85,0x00,0XFF};
	bool quit = false;
    SDL_Event e;
	Controller controller;

	//Set up Listener and link listener to controller
	LeapListener listener;
	controller.addListener(listener);

	
	//Start up SDL and create window
	if( !BaseFunc::init(window,SurfaceDessin,800,480))
        printf( "Failed to initialize!\n" );
    else
    {
		while(!quit)
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//[User requests quit]
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
			}

			//Fill the surface
			SDL_FillRect( SurfaceDessin, NULL, SDL_MapRGB( SurfaceDessin->format,ColorBg[0],ColorBg[1], ColorBg[2] ) );

			/*********** PERSO AND OTHER STUFF HERE ***************/
			//[UPDATE]
			CptVitesse += VitessePerso;
			CptTransparence += VitesseTransparence;
			if(CptVitesse >= 1) 
			{
				CptVitesse = 0;
				MonkeyJoueur->PosX++;
				MissileTest->PosX--;
			}

			Testvoie->Update();
			Testarbre->Update();
			Testarbre2->Update();
			Testarbrebas->Update();
			Testarbrebas2->Update();
			MonkeyJoueur->Update();
			Testnuage->Update();
			Testnuage2->Update();
			CamionEnnemi->Update();
			MissileTest->Update();
			MotoEnnemi2->Update();

			//[DRAW]
			Testvoie->Draw(SurfaceDessin);
			Testarbre->Draw(SurfaceDessin);
			Testarbre2->Draw(SurfaceDessin);
			Testarbrebas->Draw(SurfaceDessin);
			Testarbrebas2->Draw(SurfaceDessin);
			CamionEnnemi->Draw(SurfaceDessin);
			MonkeyJoueur->Draw(SurfaceDessin);
			Testnuage->Draw(SurfaceDessin);
			Testnuage2->Draw(SurfaceDessin);
			MissileTest->Draw(SurfaceDessin);
			MotoEnnemi2->Draw(SurfaceDessin);
		
			//aplha mode
			/*if(CptOpacity > 255)
				CptOpacity = 0;
			SDL_SetSurfaceAlphaMod(Ressources.Perso,CptOpacity);*/
			
			//[DRAW] 
			//SDL_BlitSurface(Ressources.Perso, &Source, screenSurface, &Destination);
			/*****************************************************/


			/****** CONTROLLER AND LISTENER PART ********/
		/*	std::cout << std::string(2, ' ') << "LEFT " <<  "pitch: " << listener.RPitch<< " degrees, "
			<< "roll: " << listener.RRoll << " degrees, "
			<< "yaw: " << listener.RYaw << " degrees" << std::endl;*/

			//[Background color change]
			ColorBg[0] = (Uint32)abs(listener.RRoll/175 * 255);
			if(ColorBg[0] >= 255) ColorBg[0] = 0;
			/*******************************************/

			//Refresh
			BaseFunc::Draw(window,SurfaceDessin);
		}
		
	}

	BaseFunc::close(window,SurfaceDessin);
	controller.removeListener(listener);
	return 0;
}

