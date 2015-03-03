#include "BaseFunc.h"

bool BaseFunc::init(SDL_Window* &window, SDL_Surface* &screenSurface, int Width, int Height)
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "FINAL PROJECT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
             //Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                screenSurface = SDL_GetWindowSurface( window );
            }
        }
    }

    return success;
}

void BaseFunc::close(SDL_Window* &window,SDL_Surface* &screenSurface)
{
    //Deallocate surface
    SDL_FreeSurface(screenSurface);
    screenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

bool BaseFunc::LoadSurface(string path, SDL_Surface* &textureContainer)
{
	bool success = false;

    //Load image at specified path
    textureContainer = IMG_Load( path.c_str() );
    if( textureContainer == NULL )
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	else
		success = true;

	return success;
}

void BaseFunc::Draw(SDL_Window* window, SDL_Surface* screenSurface)
{
	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Fill the surface
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format,0xFF,0xFF, 0xFF));
}
