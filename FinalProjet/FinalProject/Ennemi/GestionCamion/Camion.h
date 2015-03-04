#pragma once
#include "..\..\GestionAnimation\AnimationPlayer.h"

class Camion
{
public:
	Camion(void);
	~Camion(void);
	Camion (int X, int Y, Ressource Ressources);
	Animation* CamionPOD0;
	Animation* CamionPOD1;
	Animation* CamionPOD2;
	Animation* CamionPOD3;
	Animation* CamionPF;
	AnimationPlayer* CamionAP;
	int PosX;
	int PosY;
	int TestAnimationCompteur;
	void Update();
	void Draw(SDL_Surface* SurfaceDessin);
};
