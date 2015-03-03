#pragma once
#include "..\Fonctionnalite\BaseFunc.h"
#include "..\Fonctionnalite\Ressource.h"

class Bordure
{
public:
	Bordure(void);
	~Bordure(void);

	Bordure(int Positionx, int Positiony, int LargeurLimite,int HauteurLimite, float Speed, Ressource Ressources);
	SDL_Surface* Texturebordure; 
	int Positionx, Positiony;
	SDL_Rect* RecDestination;
	int LargeurLimite;
	float Speed;

	void Update();
	void Draw(SDL_Surface* &ScreenSurface);
};

