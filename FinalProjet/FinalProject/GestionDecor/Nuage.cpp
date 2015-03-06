#include "Nuage.h"

void Randomy (int Max, int Min, int &Valeur)
{
	Valeur = rand() % (abs(Min)+abs(Max)) -Min; 
}

Nuage::Nuage(void)
{
}

Nuage::Nuage(int Positionx, int Positiony, float Speed, Ressource Ressources)
{
	this->Positionx = Positionx;
	this->Positiony = Positiony;
	this->Speed = Speed;
	Speedinitial = Speed;
	TabNuageTexture = new SDL_Surface[4];
	TabNuageTexture[0] = *Ressources.TextureNuage1;
	TabNuageTexture[1] = *Ressources.TextureNuage2;

	RecDestination = new SDL_Rect();
	RecDestination->x = this->Positionx;
	RecDestination->y  = this->Positiony;
	RecDestination->w = TabNuageTexture[0].w;
	RecDestination->h = TabNuageTexture[0].h;

	RecDestination2 = new SDL_Rect();
	RecDestination2->x = this->Positionx + 300;
	RecDestination2->y  = this->Positiony;
	RecDestination2->w = TabNuageTexture[0].w;
	RecDestination2->h = TabNuageTexture[0].h;

	RecDestination3 = new SDL_Rect();
	RecDestination3->x = this->Positionx + 600;
	RecDestination3->y  = this->Positiony;
	RecDestination3->w = TabNuageTexture[0].w;
	RecDestination3->h = TabNuageTexture[0].h;

	Randomy(400,0,RecDestination->y);
	Randomy(400,0,RecDestination2->y);
	Randomy(400,0,RecDestination3->y);

}


Nuage::~Nuage(void)
{
}




void Nuage::Update(LeapListener *leaplistener)
{
	float Ajoutvitesse = -leaplistener->RRoll/55.0f;
	if(Ajoutvitesse > 0)
		Ajoutvitesse = 0;
	Speed = Speedinitial + Ajoutvitesse;
	Positionx -= Speed;
	RecDestination->x = Positionx;

	RecDestination2->x = Positionx + 300;
	RecDestination3->x = Positionx + 600;
	if(RecDestination->x < -1000)
	{
		Positionx = 1000;
		Randomy(400,0,RecDestination->y);
		Randomy(400,0,RecDestination2->y);
		Randomy(400,0,RecDestination3->y);
	}

	
	
}

void Nuage::Draw(SDL_Surface* &SurfaceDessin)
{
	SDL_BlitSurface(&TabNuageTexture[0], NULL, SurfaceDessin, RecDestination);
	SDL_BlitSurface(&TabNuageTexture[1], NULL, SurfaceDessin, RecDestination2);
	SDL_BlitSurface(&TabNuageTexture[0], NULL, SurfaceDessin, RecDestination3);
}