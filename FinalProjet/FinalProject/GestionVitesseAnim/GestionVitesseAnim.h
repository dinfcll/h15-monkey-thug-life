#pragma once
#include "..\Fonctionnalite\BaseFunc.h"
#include "..\Fonctionnalite\Ressource.h"
#include "../LeapMotion/LeapListener.h"
#include "../include/Leap.h"

class GestionVitesseAnim
{
public:
	GestionVitesseAnim(void);
	~GestionVitesseAnim(void);
	void Update(LeapListener *leaplistener);
};

