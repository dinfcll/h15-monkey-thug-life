#include <iostream>
#include <string.h>
#include "LeapMotion\LeapListener.h"
#include "include\Leap.h"
#include "Fonctionnalite\BaseFunc.h"
#include "Fonctionnalite\BaseFunc.h"
#include "GestionRoute\Voie.h"
#include "Perso\Monkey.h"
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


Voie* Testvoie = new Voie(-100,200,15, 2.0f, Ressources);
Monkey* MonkeyJoueur = new Monkey(0,100,Ressources);

int main(int argc, char* args[])
{
	Uint32 ColorBg[4] = {0xAA,0xFF,0xFF,0XFF};
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
			}

			Testvoie->Update();
			MonkeyJoueur->Update();
			
			
			//[DRAW]
			Testvoie->Draw(SurfaceDessin);
			MonkeyJoueur->Draw(SurfaceDessin);
		
			

			//aplha mode
			/*if(CptOpacity > 255)
				CptOpacity = 0;
			SDL_SetSurfaceAlphaMod(Ressources.Perso,CptOpacity);*/
			
			//[DRAW] 
			//SDL_BlitSurface(Ressources.Perso, &Source, screenSurface, &Destination);
			/*****************************************************/


			/****** CONTROLLER AND LISTENER PART ********/
			/*std::cout << std::string(2, ' ') << "LEFT " <<  "pitch: " << listener.RPitch<< " degrees, "
			<< "roll: " << listener.RRoll << " degrees, "
			<< "yaw: " << listener.RYaw << " degrees" << std::endl;
*/
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

