#pragma once
#include "..\SDL\include\SDL.h"
#include "..\SDL\Image\SDL_image.h"
#include "Ressource.h"
#include <iostream>
using namespace std;

class BaseFunc
{
public:
	static bool init(SDL_Window* &window, SDL_Surface* &screenSurface, int Width, int Height);
	static void close(SDL_Window* &window,SDL_Surface* &screenSurface);
	static bool LoadSurface(string path, SDL_Surface* &textureContainer);
	static void Draw(SDL_Window* window, SDL_Surface* screenSurface);
	static void LoadContent();
};

