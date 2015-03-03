#include <iostream>
#include <string.h>
#include "LeapListener.h"
#include "include\Leap.h"
#include "BaseFunc.h"
#include "Ressource.h"
using namespace Leap;
using namespace std;

//Screen dimension constants
#ifdef _WIN32
#undef main
#endif

#define SCREEN_WIDTH 640;
#define SCREEN_HEIGHT 640;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* loadedTexture = NULL;
Ressource Ressources = Ressource();
float SpeedOpacity = 0.5f;
float CptOpacity = 255;

int main(int argc, char* args[])
{
	Uint32 ColorBg[4] = {0xAA,0xFF,0xFF,0XFF};
	bool quit = false;
    SDL_Event e;
	SDL_Rect RectanglePerso; RectanglePerso.x = 10; RectanglePerso.y = 50; RectanglePerso.h = 140; RectanglePerso.w = 10;

	//Set up Listener and link listener to controller
	LeapListener listener;
	Controller controller;
	controller.addListener(listener);
    
	int Width = SCREEN_WIDTH;
	int Height = SCREEN_WIDTH;
	//Start up SDL and create window
	if( !BaseFunc::init(window,screenSurface,Width,Height))
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
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format,ColorBg[0],ColorBg[1], ColorBg[2]) );

			/*********** PERSO AND OTHER STUFF HERE ***************/
			//[UPDATE]
		
			//CptOpacity += SpeedOpacity;
			RectanglePerso.x = (listener.RPalmPosition.x /120.0f) * SCREEN_WIDTH;
			RectanglePerso.y = (listener.RPalmPosition.z /130.0f) * SCREEN_HEIGHT;

			//cout << RectanglePerso.x << endl;
			if(RectanglePerso.x < 0) RectanglePerso.x = 0;
			if(RectanglePerso.x > Width - 175) RectanglePerso.x = Width - 175; 
				
			

			//aplha mode
			/*if(CptOpacity > 255)
				CptOpacity = 0;*/
			//CptOpacity = (listener.LGrabStrength * 255);
			SDL_SetSurfaceAlphaMod(Ressources.Perso,CptOpacity);

			//[DRAW] 
			SDL_BlitSurface(Ressources.Perso, NULL, screenSurface, &RectanglePerso);
			/*****************************************************/


			/****** CONTROLLER AND LISTENER PART ********/
			std::cout << std::string(2, ' ') << "RIGHT " <<  "pitch: " << listener.RPitch<< " degrees, "
			<< "roll: " << listener.RRoll << " degrees, "
			<< "yaw: " << listener.RYaw << " degrees" << std::endl;

			std::cout << std::string(2, ' ') << "RIGHT " <<  "X: " << listener.RPalmPosition << std::endl;

			//[Background color change]
			if(listener.RRoll > 0)
			{
				ColorBg[0] = (Uint32)(listener.RRoll/95 * 255);
			}
			else
				ColorBg[0] = (Uint32)abs(listener.RRoll/190 * 255);
			if(ColorBg[0] >= 255) ColorBg[0] = 0;
			/*******************************************/

			//Refresh
			BaseFunc::Draw(window,screenSurface);
		}
		
	}

	BaseFunc::close(window,screenSurface);
	controller.removeListener(listener);
	return 0;
}

