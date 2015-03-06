#pragma once
#include "..\Fonctionnalite\BaseFunc.h"
#include "..\Fonctionnalite\Ressource.h"
#include "../LeapMotion/LeapListener.h"
#include "../include/Leap.h"

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


	void Update(LeapListener *leaplistener);
	void Draw(SDL_Surface* &SurfaceDessin);

private:
	float Speedinitial;
};

