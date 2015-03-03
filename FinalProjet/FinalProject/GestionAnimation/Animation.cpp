#include "Animation.h"


Animation::Animation(void)
{


}
Animation::Animation(SDL_Surface* Texture, int FrameWidth,int FrameHeight, float FrameTime,float Resize, bool IsLooping)
{
	this->Texture = Texture;
    this->FrameWidth = FrameWidth;
	this->FrameHeight = FrameHeight;
    this->FrameTime = FrameTime;
    this->Resize = Resize;
    this->isLooping = IsLooping;
	this->FrameCount = Texture->w / this->FrameWidth;
}


Animation::~Animation(void)
{

}
