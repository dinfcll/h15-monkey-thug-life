#pragma once
#include "..\..\GestionAnimation\AnimationPlayer.h"

class Moto
{
public:
	Moto(void);
	Moto(int X, int Y, Ressource Ressources);
	~Moto(void);
	AnimationPlayer* ConducteurAP;
	AnimationPlayer* TireurAP;
	Animation* AnimationConducteur;
	Animation* AnimationTireur;
	int PosX;
	int PosY;
	void Update();
	void Draw(SDL_Surface* SurfaceDessin);
};

