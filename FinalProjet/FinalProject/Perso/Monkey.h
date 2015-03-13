#pragma once
#include "../GestionAnimation/AnimationPlayer.h"
#include "../LeapMotion/LeapListener.h"
#include "Projectile/ProjectileBanane.h"
#include "../include/Leap.h"
#include <list>
using namespace std;

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
	list<ProjectileBanane>* ListBanane;  
	Ressource RessourceProjet;
	float cptSpeedProjectile;
	float SpeedProjectile;
	//Classe projectile a creer
	
	int PosX;
	int PosY;
	int DecalageRoueAvantX;
	int DecalageRoueAvantY;
	int DecalageRoueArriereX;
	int DecalageRoueArriereY;
	int DecalageYeuxX;
	int DecalageYeuxY;
	void Update(LeapListener *leaplistener);
	void Draw(SDL_Surface* SurfaceDessin);
};

