#pragma once
#include "Animation.h"

class AnimationPlayer
{
public:
	AnimationPlayer(void);
	~AnimationPlayer(void);

	void PlayAnimation(Animation newAnimation);
	void Draw(SDL_Surface* &screenSurface);
		
	Animation CurrentAnimation;
	int FrameIndex;
	float Timer;
	int PosX;
	int PosY;
};

