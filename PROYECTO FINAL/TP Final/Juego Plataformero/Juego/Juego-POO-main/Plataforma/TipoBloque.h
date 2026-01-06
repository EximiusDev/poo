#ifndef TipoBloque_h
#define TipoBloque_h
#include <string>
using namespace std;

class TipoBloque {
private:
	int Dureza;
	int Puntos;
	string NomBloque;
public:
	void modificardatos(int Dureza, int Puntos,string NomBloq);
	int Verpuntos();
	int Verdureza();
	string NomBloq();
};

#endif

