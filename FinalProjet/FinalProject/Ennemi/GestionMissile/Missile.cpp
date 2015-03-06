#include "Missile.h"


Missile::Missile(void)
{
}


Missile::~Missile(void)
{
}

Missile::Missile(int X,int Y, Ressource Ressources)
{
	MissileAP = new AnimationPlayer();
	MissileAnimation = new Animation(Ressources.Missile,25,15,0.25f,true);
	PosX = X;
	PosY = Y;
}

void Missile::Update()
{
	MissileAP->PosX = PosX;
	MissileAP->PosY = PosY;
	MissileAP->PlayAnimation(*MissileAnimation);
}

void Missile::Draw(SDL_Surface* SurfaceDessin)
{
	MissileAP->Draw(SurfaceDessin);
}