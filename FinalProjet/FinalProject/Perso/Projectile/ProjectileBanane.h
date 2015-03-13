#pragma once
#include "../../GestionAnimation/AnimationPlayer.h"


class ProjectileBanane
{
public:
	ProjectileBanane(void);
	~ProjectileBanane(void);
	ProjectileBanane(int X, int Y, Ressource Ressources);
	void Update();
	void Draw(SDL_Surface* SurfaceDessin);
	AnimationPlayer* ProjectileBananeAP;
	Animation* BananeAnimation;
	int PosX;
	int PosY;
	bool Delete;
	float Speed;
	
};

