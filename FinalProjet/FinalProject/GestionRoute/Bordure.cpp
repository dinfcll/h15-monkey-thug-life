#include "Bordure.h"


Bordure::Bordure(void)
{
	Positionx = 0;
	Positiony = 0;
	RecDestination = new SDL_Rect();
	RecDestination->x = 0;
	RecDestination->y  = 0;
	RecDestination->w = 0;
	RecDestination->h = 0;
}

Bordure::Bordure(int Positionx, int Positiony, int LargeurLimite, int HauteurLimite, float Speed, Ressource Ressources)
{
	this->Positionx = Positionx;
	this->Positiony = Positiony;
	this->Positiony += HauteurLimite/4 * 1.8f;
	this->Texturebordure = Ressources.Texturebordure;
	this->LargeurLimite = LargeurLimite;
	this->Speed = Speed;
	Speedinitial = Speed;
	RecDestination = new SDL_Rect();
	RecDestination->x = this->Positionx;
	RecDestination->y  = this->Positiony;
	RecDestination->w = Texturebordure->w;
	RecDestination->h = Texturebordure->h;
}

Bordure::~Bordure(void)
{
}

void Bordure::Update(LeapListener *leaplistener)
{
	float Ajoutvitesse = -leaplistener->RRoll/55.0f;

	Speed = Speedinitial + Ajoutvitesse;
	Positionx -= Speed;
	RecDestination->x = Positionx;
	if(RecDestination->x < -100)
	{
		Positionx = 800;
	}
}

void Bordure::Draw(SDL_Surface* &ScreenSurface)
{
	SDL_BlitSurface(Texturebordure, NULL, ScreenSurface, RecDestination);
}