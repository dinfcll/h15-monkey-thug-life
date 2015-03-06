#pragma once
#include "../GestionAnimation/AnimationPlayer.h"

class Monkey
{
public:
	Monkey(void);
	~Monkey(void);
	Monkey (int X, int Y, Ressource Ressources);
	Animation* PersoA;
	Animation* FWheelA;
	Animation* BWheelA;
	Animation* YeuxAN;
	Animation* YeuxA;
	AnimationPlayer* FWheelAP;
	AnimationPlayer* BWheelAP;
	AnimationPlayer* PlayerAP;
	AnimationPlayer* YeuxAP;

	//Classe projectile a creer
	AnimationPlayer* ProjectileBananeAP;
	Animation* BananeAnimation;
	int PosX;
	int PosY;
	int DecalageRoueAvantX;
	int DecalageRoueAvantY;
	int DecalageRoueArriereX;
	int DecalageRoueArriereY;
	int DecalageYeuxX;
	int DecalageYeuxY;
	void Update();
	void Draw(SDL_Surface* SurfaceDessin);
};

