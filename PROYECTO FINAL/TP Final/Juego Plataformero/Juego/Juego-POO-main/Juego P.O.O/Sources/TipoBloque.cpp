#include "TipoBloque.h"
#include <string>
using namespace std;



void TipoBloque::modificardatos(int Dureza, int Puntos,string NomBloq){
	this ->Dureza =Dureza;
	this ->Puntos =Puntos;
	this ->NomBloq =NomBloq;
};
int TipoBloque::Verpuntos(){return Puntos;};
int TipoBloque::Verdureza(){return Dureza;};
string TipoBloque::NomBloq(){return NomBloq;};
