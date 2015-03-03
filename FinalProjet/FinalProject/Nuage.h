#pragma once
#include "Fonctionnalite\BaseFunc.h"
#include "Fonctionnalite\Ressource.h"
class Nuage
{
public:
	Nuage(void);
	~Nuage(void);
	Nuage(int Positionx, int Positiony,float Speed, Ressource Ressources);
	SDL_Surface* TabNuageTexture; 
	int Positionx, Positiony;
	SDL_Rect* RecDestination;
	SDL_Rect* RecDestination2;
	SDL_Rect* RecDestination3;
	float Speed;

	void Update();
	void Draw(SDL_Surface* &SurfaceDessin);
};

