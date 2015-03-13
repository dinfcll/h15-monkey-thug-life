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
		CheckupLoadSuccess(BaseFunc::LoadSurface("Moto10P60.png",Perso));
		CheckupLoadSuccess(BaseFunc::LoadSurface("FWheelA0P60.png",RoueAvant));
		CheckupLoadSuccess(BaseFunc::LoadSurface("BWheelA0P60.png",RoueArriere));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Voie.png",Texturevoie));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Bordure.png",Texturebordure));
		CheckupLoadSuccess(BaseFunc::LoadSurface("EyeA0P60.png",YeuxPerso));
		CheckupLoadSuccess(BaseFunc::LoadSurface("EyeAN0P60.png",YeuxPersoRien));
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
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD01P25.png",CamionPODO));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD11P25.png",CamionPOD1));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD21P25.png",CamionPOD2));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteOuverteD31P25.png",CamionPOD3));
		CheckupLoadSuccess(BaseFunc::LoadSurface("Camion_PorteFerme1P25.png",CamionPF));
		CheckupLoadSuccess(BaseFunc::LoadSurface("MotoNormal1P25.png",MotoNormal));
		CheckupLoadSuccess(BaseFunc::LoadSurface("BazookaNormalOwnBazooka1P25.png",BazookaNormal));
		CheckupLoadSuccess(BaseFunc::LoadSurface("MissileAnim.png",Missile));
		CheckupLoadSuccess(BaseFunc::LoadSurface("BananeAnim.png",Banane));
	}
	catch (const char* msg) 
	{
		cout << msg << endl;
	}
}

Ressource::~Ressource()
{
	
}


