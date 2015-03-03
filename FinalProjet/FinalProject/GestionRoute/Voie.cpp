#include "Voie.h"

Voie::Voie(void)
{
}

Voie::Voie(int Positionx, int Positiony, int NbBordures, float Speed, Ressource Ressources)
{
	this->Positionx = Positionx;
	this->Positiony = Positiony;
	this->TextureVoie = Ressources.Texturevoie;
	this->NbBordures = NbBordures;

	RecDestination = new SDL_Rect();
	RecDestination->x = Positionx;
	RecDestination->y  = Positiony;
	RecDestination->w = TextureVoie->w;
	RecDestination->h = TextureVoie->h;

	MaximumLargeur = TextureVoie->w;
	MaximumHauteur = TextureVoie->h;
	TabBordure = new Bordure[NbBordures];
	EcartEntreBordure = 100;
	longueurbordure = Ressources.Texturebordure->w;

	for(int i = 0; i < NbBordures; i++)
	{
		TabBordure[i] = Bordure(Positionx + (i * EcartEntreBordure),Positiony, MaximumLargeur,MaximumHauteur, Speed, Ressources);
	}
}


Voie::~Voie(void)
{

}

void Voie::Update()
{
	for(int i = 0; i < NbBordures; i++)
	{
		TabBordure[i].Update();
	}
}

void Voie::Draw(SDL_Surface* &ScreenSurface)
{
	SDL_BlitSurface(TextureVoie, NULL, ScreenSurface, RecDestination);
	for(int i = 0; i < NbBordures; i++)
	{
		TabBordure[i].Draw(ScreenSurface);
	}
}
