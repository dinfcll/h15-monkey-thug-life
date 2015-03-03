#include "Ressource.h"


void CheckupLoadSuccess(bool Success)
{
	if(!Success) throw "Error Ressource loading";
}

//LOAD MEDIA
Ressource::Ressource()
{
	try
	{
		CheckupLoadSuccess(BaseFunc::LoadSurface("SimpleMonkeyNoTireNoE.png",Perso));
		CheckupLoadSuccess(BaseFunc::LoadSurface("FWheelA.png",RoueAvant));
		CheckupLoadSuccess(BaseFunc::LoadSurface("BWheelA.png",RoueArriere));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Voie.png",Texturevoie));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Bordure.png",Texturebordure));
		CheckupLoadSuccess(BaseFunc::LoadSurface("EyeA.png",YeuxPerso));
		CheckupLoadSuccess(BaseFunc::LoadSurface("EyeAN.png",YeuxPersoRien));
	}
	catch (const char* msg) 
	{
		cout << msg << endl;
	}
}

Ressource::~Ressource()
{
	
}


