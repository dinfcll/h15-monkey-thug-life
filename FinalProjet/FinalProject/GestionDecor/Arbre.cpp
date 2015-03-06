#include "Arbre.h"


Arbre::Arbre(void)
{
}


Arbre::~Arbre(void)
{
}

Arbre::Arbre(int Positionx, int Positiony, float Speed, Ressource Ressources, int Mode)
{
	this->Positionx = Positionx;
	this->Positiony = Positiony;
	this->Speed = Speed;
	Speedinitial = Speed;
	this->Mode = Mode;
	TabArbreTexture = new SDL_Surface[4];
	TabArbreTexture[0] = *Ressources.TextureArbre1;
	TabArbreTexture[1] = *Ressources.TextureArbre2;
	TabArbreTexture[2] = *Ressources.TextureArbre3;
	TabArbreTexture[3] = *Ressources.TextureArbre4;

	RecDestination = new SDL_Rect();
	RecDestination->x = this->Positionx;
	RecDestination->y  = this->Positiony;
	RecDestination->w = TabArbreTexture[0].w;
	RecDestination->h = TabArbreTexture[0].h;

	RecDestination2 = new SDL_Rect();
	RecDestination2->x = this->Positionx + 300;
	RecDestination2->y  = this->Positiony;
	RecDestination2->w = TabArbreTexture[0].w;
	RecDestination2->h = TabArbreTexture[0].h;

	RecDestination3 = new SDL_Rect();
	RecDestination3->x = this->Positionx + 600;
	RecDestination3->y  = this->Positiony ;
	RecDestination3->w = TabArbreTexture[0].w;
	RecDestination3->h = TabArbreTexture[0].h;

	RecDestination4 = new SDL_Rect();
	RecDestination4->x = this->Positionx;
	RecDestination4->y  = this->Positiony +250;
	RecDestination4->w = TabArbreTexture[2].w;
	RecDestination4->h = TabArbreTexture[2].h;

	RecDestination5 = new SDL_Rect();
	RecDestination5->x = this->Positionx + 300;
	RecDestination5->y  = this->Positiony +250 ;
	RecDestination5->w = TabArbreTexture[2].w;
	RecDestination5->h = TabArbreTexture[2].h;

	RecDestination6 = new SDL_Rect();
	RecDestination6->x = this->Positionx + 600;
	RecDestination6->y  = this->Positiony +250;
	RecDestination6->w = TabArbreTexture[2].w;
	RecDestination6->h = TabArbreTexture[2].h;


}

void Arbre::Update(LeapListener *leaplistener)
{
	float Ajoutvitesse = -leaplistener->RRoll/55.0f;

	Speed = Speedinitial + Ajoutvitesse;
	
	Positionx -= Speed;
	
	RecDestination->x = Positionx;
	RecDestination2->x = Positionx + 300;
	RecDestination3->x = Positionx + 600;
	
	RecDestination4->x = Positionx;
	RecDestination5->x = Positionx + 300;
	RecDestination6->x = Positionx + 600;

	if(RecDestination->x < -1000)
	{
		Positionx = 1000;
	}



}

void Arbre::Draw(SDL_Surface* &SurfaceDessin)
{
	if(Mode == 1)
	{
		SDL_BlitSurface(&TabArbreTexture[0], NULL, SurfaceDessin, RecDestination);
		SDL_BlitSurface(&TabArbreTexture[1], NULL, SurfaceDessin, RecDestination2);
		SDL_BlitSurface(&TabArbreTexture[0], NULL, SurfaceDessin, RecDestination3);
	}

	if (Mode == 2)
	{
		SDL_BlitSurface(&TabArbreTexture[2], NULL, SurfaceDessin, RecDestination4);
		SDL_BlitSurface(&TabArbreTexture[3], NULL, SurfaceDessin, RecDestination5);
		SDL_BlitSurface(&TabArbreTexture[2], NULL, SurfaceDessin, RecDestination6);
	}
	
	
}