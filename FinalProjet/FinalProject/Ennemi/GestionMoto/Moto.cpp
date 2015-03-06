#include "Moto.h"


Moto::Moto(void)
{
}

Moto::Moto(int X, int Y, Ressource Ressources)
{
	ConducteurAP = new AnimationPlayer();
	TireurAP = new AnimationPlayer();
	AnimationConducteur = new Animation(Ressources.MotoNormal,100,100,0.5f,true);
	AnimationTireur = new Animation(Ressources.BazookaNormal,94,62,0.5f,true);
	PosX = X;
	PosY = Y;
}

Moto::~Moto(void)
{
}

void Moto::Update()
{
	ConducteurAP->PosX = PosX;
	ConducteurAP->PosY = PosY;
	ConducteurAP->PlayAnimation(*AnimationConducteur);

	TireurAP->PosX = PosX - 15;
	TireurAP->PosY = PosY + 25;
	TireurAP->PlayAnimation(*AnimationTireur);
}

void Moto::Draw(SDL_Surface* SurfaceDessin)
{
	ConducteurAP->Draw(SurfaceDessin);
	TireurAP->Draw(SurfaceDessin);
}
