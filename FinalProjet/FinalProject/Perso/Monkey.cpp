#include "Monkey.h"


Monkey::Monkey(void)
{
}


Monkey::~Monkey(void)
{
}

Monkey::Monkey(int X, int Y, Ressource Ressources)
{
	PersoA = new Animation(Ressources.Perso,83,70,0.1f,true);
	FWheelA = new Animation(Ressources.RoueAvant,45,45,0.5f,true);
	BWheelA = new Animation(Ressources.RoueArriere,45,45,0.5f,true);
	YeuxA = new Animation(Ressources.YeuxPerso,15,6,15,true);
	YeuxAN = new Animation(Ressources.YeuxPersoRien,25,25,15,true);
	FWheelAP = new AnimationPlayer();
	BWheelAP = new AnimationPlayer();
	PlayerAP = new AnimationPlayer();
	YeuxAP = new AnimationPlayer();
	PosX = X;
	PosY = Y;
	DecalageRoueAvantX = 45;
	DecalageRoueAvantY = 35;
	DecalageRoueArriereX = -9;
	DecalageRoueArriereY = 40;
	DecalageYeuxX = 16;
	DecalageYeuxY = 13;  
	RessourceProjet = Ressources;
	ListBanane = new list<ProjectileBanane>();

	cptSpeedProjectile = 0;
	SpeedProjectile = 0.025f;
}

void Monkey::Update(LeapListener *leaplistener)
{
	PosX = (leaplistener->RPalmPositionx /120.0f) * 900;
	PosY = (leaplistener->RPalmPositiony /130.0f) * 600;
	

	if(PosX < 0)
		PosX = 0;
	if(PosY < 145)
		PosY = 145;
	if(PosX > 710)
		PosX = 710;
	if(PosY > 270) 
		PosY = 270;

	if(leaplistener->RPalmStrength > 0.75f)
	{
		cptSpeedProjectile += SpeedProjectile;
		if(cptSpeedProjectile > 1.0f)
		{
			cptSpeedProjectile = 0;
			ListBanane->push_back(*new ProjectileBanane(PosX, PosY,RessourceProjet));
		}
	}

	int index = 0;
	for(auto i = ListBanane->begin(); i != ListBanane->end();)
	{
		//if(i->Delete)
		//	i = ListBanane->erase(i);
		//else
		//{
		i->Update();
		if(i->Delete)
			i = ListBanane->erase(i);
		else 
			++i;
		/*}*/
	}

	
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

	for (list<ProjectileBanane>::iterator banane = ListBanane->begin(); banane != ListBanane->end(); banane++)
	{
		banane->Draw(SurfaceDessin);
	}
}






