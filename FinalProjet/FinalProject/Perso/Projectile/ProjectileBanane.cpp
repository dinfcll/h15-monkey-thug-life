#include "ProjectileBanane.h"


ProjectileBanane::ProjectileBanane()
{

}


ProjectileBanane::~ProjectileBanane()
{

}

ProjectileBanane::ProjectileBanane(int X, int Y, Ressource Ressources)
{
	ProjectileBananeAP = new AnimationPlayer();
	BananeAnimation = new Animation(Ressources.Banane,25,15,1,true);

	//decalage Perso
	PosX = X + 60;
	PosY = Y + 25;
	Delete = false;
	Speed = 2;
}

void ProjectileBanane::Update()
{
	PosX += Speed;
	ProjectileBananeAP->PosX = PosX;
	ProjectileBananeAP->PosY = PosY;
	ProjectileBananeAP->PlayAnimation(*BananeAnimation);

	if(PosX > 800)
	{
		Delete = true;
	}
}



void ProjectileBanane::Draw(SDL_Surface* SurfaceDessin)
{
	ProjectileBananeAP->Draw(SurfaceDessin);
}
