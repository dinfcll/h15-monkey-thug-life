#pragma once
#include "..\Fonctionnalite\BaseFunc.h"
#include "..\Fonctionnalite\Ressource.h"
#include "../LeapMotion/LeapListener.h"
#include "../include/Leap.h"

class Arbre
{
public:
	Arbre(void);
	~Arbre(void);
	Arbre(int Positionx, int Positiony,float Speed, Ressource Ressources, int Mode);
	SDL_Surface* TabArbreTexture; 
	int Positionx, Positiony;
	SDL_Rect* RecDestination;
	SDL_Rect* RecDestination2;
	SDL_Rect* RecDestination3;
	SDL_Rect* RecDestination4;
	SDL_Rect* RecDestination5;
	SDL_Rect* RecDestination6;
	float Speed;
	int Mode;
	
	void Update(LeapListener *leaplistener);
	void Draw(SDL_Surface* &SurfaceDessin);
private:
	float Speedinitial;
};

