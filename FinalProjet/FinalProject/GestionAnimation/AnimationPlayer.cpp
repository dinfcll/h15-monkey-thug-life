#include "AnimationPlayer.h"


AnimationPlayer::AnimationPlayer(void)
{
	PosX = 0;
	PosY = 0;
}


AnimationPlayer::~AnimationPlayer(void)
{
}

void AnimationPlayer::PlayAnimation(Animation newAnimation)
{
	if (CurrentAnimation.Texture == newAnimation.Texture)
        return;

	CurrentAnimation = newAnimation;
    FrameIndex = 0;
    Timer = 0;
}

void AnimationPlayer::Draw(SDL_Surface* &screenSurface)
{
	if (CurrentAnimation.Texture == NULL)
    {
        //throw new NotSupportedException("Yo,is no animation selected");
    }
    else
    {
        Timer += 0.060f;
		while (Timer >= CurrentAnimation.FrameTime)
        {
            Timer -= CurrentAnimation.FrameTime;
			if (CurrentAnimation.isLooping)
			{
                try
                {
                    FrameIndex = (FrameIndex + 1) % CurrentAnimation.FrameCount;
                }
				catch(exception e)
                {
                    FrameIndex = 0;
                }
			}
            else 
			{
				int min = 0;
				if(FrameIndex + 1 < CurrentAnimation.FrameCount - 1) min = FrameIndex + 1;
				else min = CurrentAnimation.FrameCount - 1;
				FrameIndex = min;
			}
        }

			SDL_Rect* RecSource =  new SDL_Rect();
			SDL_Rect* RecDestination = new SDL_Rect();
			RecSource->x = FrameIndex * CurrentAnimation.FrameWidth;
			RecSource->y = 0;
			RecSource->w = CurrentAnimation.FrameHeight;
			RecSource->h = CurrentAnimation.FrameWidth;

			RecDestination->x = PosX; 
			RecDestination->y = PosY; 
			RecDestination->h = CurrentAnimation.FrameHeight; 
			RecDestination->w = CurrentAnimation.FrameWidth;

			SDL_BlitSurface(CurrentAnimation.Texture, RecSource, screenSurface, RecDestination);
		}
}
