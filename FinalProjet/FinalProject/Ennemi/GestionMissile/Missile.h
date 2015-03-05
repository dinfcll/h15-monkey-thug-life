#pragma once
#include "..\..\GestionAnimation\AnimationPlayer.h"

class Missile
{
public:
	Missile(void);
	Missile(int X,int Y, Ressource Ressources);
	~Missile(void);
	AnimationPlayer* MissileAP;
	Animation* MissileAnimation;
	int PosX;
	int PosY;
	void Update();
	void Draw(SDL_Surface* SurfaceDessin);
};

