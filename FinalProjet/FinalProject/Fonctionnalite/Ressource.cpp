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
		CheckupLoadSuccess(BaseFunc::LoadSurface("Arbre1.png",TextureArbre1));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Arbre2.png",TextureArbre2));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Arbre3.png",TextureArbre3));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Arbre4.png",TextureArbre4));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Nuage1.png",TextureNuage1));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Nuage2.png",TextureNuage2));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Arbre3.png",TextureArbre3));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Arbre4.png",TextureArbre4));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Nuage1.png",TextureNuage1));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Nuage2.png",TextureNuage2));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD0.png",CamionPODO));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD1.png",CamionPOD1));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD2.png",CamionPOD2));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD3.png",CamionPOD3));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteFerme.png",CamionPF));
	}
	catch (const char* msg) 
	{
		cout << msg << endl;
	}
}

Ressource::~Ressource()
{
	
}


