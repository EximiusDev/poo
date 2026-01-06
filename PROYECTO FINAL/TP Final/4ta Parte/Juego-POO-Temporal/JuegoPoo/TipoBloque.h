#ifndef TipoBloque_h
#define TipoBloque_h
#include <string>
using namespace std;

///Teoria:Con esto inutilizo completamente la creacion de diferentes clases
class TipoBloque {  ///defino la clase TipoBloque con sus atributos y metodos
private:
	int Dureza;
	int Puntos;
	string NomBloque;
public:
	void Modificardatos(int Dureza, int Puntos,string NomBloq);
	int Verpuntos();
	int Verdureza();
	string NomBloq();
};

#endif

