#pragma once
#include "..\Fonctionnalite\BaseFunc.h"

class Animation
{
public:
	Animation(void);
	Animation(SDL_Surface* Texture, int FrameWidth,int FrameHeight, float FrameTime, bool IsLooping);
	~Animation(void);

	SDL_Surface* Texture;
	int FrameWidth;
	int FrameHeight;
	float FrameTime;
	int FrameCount;
	bool isLooping;
	float Resize;

};

