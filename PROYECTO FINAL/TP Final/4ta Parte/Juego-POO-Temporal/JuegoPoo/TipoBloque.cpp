#include "TipoBloque.h"
#include <string>
using namespace std;

/// metodos del objeto TipoBloque

void TipoBloque::Modificardatos(int Dureza, int Puntos,string NomBloq){ 
	this ->Dureza = Dureza;   /// modifico los datos al cambiar el puntero con los datos apuntados (?)
	this ->Puntos = Puntos;
	this ->NomBloque =NomBloq;
};
int TipoBloque::Verpuntos(){return Puntos;}; 
int TipoBloque::Verdureza(){return Dureza;};
string TipoBloque::NomBloq(){return NomBloque;};
