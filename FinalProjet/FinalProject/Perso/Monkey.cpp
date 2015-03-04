#include "Monkey.h"


Monkey::Monkey(void)
{
}


Monkey::~Monkey(void)
{
}

Monkey::Monkey(int X, int Y, Ressource Ressources)
{
	PersoA = new Animation(Ressources.Perso,139,139,0.1f,true);
	FWheelA = new Animation(Ressources.RoueAvant,75,75,0.5f,true);
	BWheelA = new Animation(Ressources.RoueArriere,75,75,0.5f,true);
	YeuxA = new Animation(Ressources.YeuxPerso,25,25,15,true);
	YeuxAN = new Animation(Ressources.YeuxPersoRien,25,25,15,true);
	FWheelAP = new AnimationPlayer();
	BWheelAP = new AnimationPlayer();
	PlayerAP = new AnimationPlayer();
	YeuxAP = new AnimationPlayer();
	PosX = X;
	PosY = Y;
	DecalageRoueAvantX = 76;
	DecalageRoueAvantY = 57;
	DecalageRoueArriereX = -15;
	DecalageRoueArriereY = 65;
	DecalageYeuxX = 26;
	DecalageYeuxY = 23;
}

void Monkey::Update()
{
	PlayerAP->PosX = PosX;
	PlayerAP->PosY = PosY;
	FWheelAP->PosX = PosX + DecalageRoueAvantX;
	FWheelAP->PosY = PosY + DecalageRoueAvantY;
	BWheelAP->PosX = PosX + DecalageRoueArriereX;
	BWheelAP->PosY = PosY + DecalageRoueArriereY;
	YeuxAP->PosX = PosX + DecalageYeuxX;
	YeuxAP->PosY = PosY + DecalageYeuxY;
	FWheelAP->PlayAnimation(*FWheelA);
	BWheelAP->PlayAnimation(*BWheelA);
	PlayerAP->PlayAnimation(*PersoA);
	YeuxAP->PlayAnimation(*YeuxA);
}

void Monkey::Draw(SDL_Surface* SurfaceDessin)
{
	FWheelAP->Draw(SurfaceDessin);
	BWheelAP->Draw(SurfaceDessin);
	PlayerAP->Draw(SurfaceDessin);
	YeuxAP->Draw(SurfaceDessin);
}






