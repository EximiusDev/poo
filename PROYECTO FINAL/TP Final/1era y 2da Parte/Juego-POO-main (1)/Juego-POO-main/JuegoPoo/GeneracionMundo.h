#ifndef GeneracionMundo_h
#define GeneracionMundo_h
#include "TipoBloque.h"
#include <vector>
#include <string>

using namespace std;

class GeneracionMundo {
private:
	
	vector<int>niveles; /// creo un vector para los niveles de altura 
	vector<vector<int>>I; ///Creo la matriz de aleatoriedad  ///Creo la matriz de aleatoriedad ///Creo la matriz de tipo int
	vector<vector<TipoBloque>>J; ///Creo la matriz de bloques
	
	int altura; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	int ancho; /// minimo 120 (por la resolucion de pantalla)
	
	int nivelcero; /// nivel donde empiza el suelo
	int altura_total; /// altura + distancia de nivelcero

public:
	GeneracionMundo(int altura_E, int ancho_E, int nivelcero_E);///Aca le doy el tamanio y los lleno con datos random
	void Modificardatos (int altura_E, int ancho_E, int nivelcero_E);
	vector<int> Ver_niveles();
	vector<vector<int>> Ver_Matriz_azar(vector<int> niveles);
	vector<vector<TipoBloque>> Ver_Matriz_Bloques(vector<vector<int>>I);
	
	/*
	TexturePer(string Nom); 
	void Pos(float x1,float y1);
	float verx();
	float very();
	Sprite Vs();
	void Tam(float tam1,float tam2);
	
	void Modificardatos(int Dureza, int Puntos,string NomBloq);
	int Verpuntos();
	int Verdureza();
	string NomBloq();
	*/
};

#endif

