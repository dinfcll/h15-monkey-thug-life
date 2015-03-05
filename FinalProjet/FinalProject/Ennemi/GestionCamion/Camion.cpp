#include "Camion.h"


Camion::Camion(void)
{
}


Camion::~Camion(void)
{
}

Camion::Camion(int X, int Y, Ressource Ressources)
{
	CamionAP = new AnimationPlayer();
	CamionPOD0 = new Animation(Ressources.CamionPODO,200,112,0.5f,true);
	CamionPOD1 = new Animation(Ressources.CamionPOD1,200,112,0.5f,true);
	CamionPOD2 = new Animation(Ressources.CamionPOD2,200,112,0.5f,true);
	CamionPOD3 = new Animation(Ressources.CamionPOD3,200,112,0.5f,true);
	CamionPF = new Animation(Ressources.CamionPF,200,112,0.5f,true);
	this->PosX = X;
	this->PosY = Y;
	TestAnimationCompteur = 0;
}

void Camion::Update()
{
	CamionAP->PosX = PosX;
	CamionAP->PosY = PosY;

	TestAnimationCompteur++;

	if(TestAnimationCompteur < 100)
		CamionAP->PlayAnimation(*CamionPOD0);
	else if(TestAnimationCompteur < 200)
		CamionAP->PlayAnimation(*CamionPOD1);
	else if(TestAnimationCompteur < 300)
		CamionAP->PlayAnimation(*CamionPOD2);
	else if(TestAnimationCompteur < 400)
		CamionAP->PlayAnimation(*CamionPOD3);
	else if (TestAnimationCompteur < 500)
		CamionAP->PlayAnimation(*CamionPF);

	if (TestAnimationCompteur > 600) TestAnimationCompteur = 0;
}

void Camion::Draw(SDL_Surface* SurfaceDessin)
{
	CamionAP->Draw(SurfaceDessin);
}

