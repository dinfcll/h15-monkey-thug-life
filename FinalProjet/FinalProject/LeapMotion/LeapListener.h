#pragma once
#include "..\include\Leap.h"
#include <string.h>
#include <iostream>
using namespace Leap;
using namespace std;

class LeapListener : public Listener
{
public:
	LeapListener(void);
	~LeapListener(void);

	virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);
    virtual void onDeviceChange(const Controller&);
    virtual void onServiceConnect(const Controller&);
    virtual void onServiceDisconnect(const Controller&);

	float LYaw,LPitch,LRoll;
	float RYaw,RPitch,RRoll;
	float LPalmPositionx,RPalmPositionx,LPalmPositiony,RPalmPositiony;
	float LPalmStrength, RPalmStrength;
	
	 
private:	
	string fingerNames[5]; 
	string boneNames[4];
	string stateNames[4];
};
