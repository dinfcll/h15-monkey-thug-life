#pragma once
#include "..\Fonctionnalite\BaseFunc.h"
#include "Bordure.h"
#include "..\Fonctionnalite\Ressource.h"
#include "../LeapMotion/LeapListener.h"
#include "../include/Leap.h"

class Voie
{
public:
	Voie(void);
	~Voie(void);
	Voie(int Positionx, int Positiony, int NbBordures,  float Speed, Ressource Ressources);
	SDL_Surface* TextureVoie; 
	int Positionx, Positiony;
	SDL_Rect* RecDestination;
	int MaximumLargeur;
	int MaximumHauteur;
	int EcartEntreBordure;
	int longueurbordure;
	Bordure* TabBordure;
	int NbBordures;
	
	void Update(LeapListener *leaplistener);
	void Draw(SDL_Surface* &ScreenSurface);

};

