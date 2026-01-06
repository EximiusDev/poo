#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct R// Binariamente, la única diferencia entre struct y class es que en struct los fields son públicos por defecto.
	{	// Si este struct tiene dos enteros, cada struct va a pesar 8bytes en mi archivo binario.
		int dato1;
		int dato2;
	};
class MiClase
	{
	protected:
		string nombre_archi;
	public:
		MiClase(string ruta)
		{
			nombre_archi = ruta;
		}
		R reemplaza_Bin(R r, int pos)
		{
			fstream archivoBinario(nombre_archi.c_str(),ios::in | ios::out | ios::binary);
			
			archivoBinario.seekp(sizeof(r)*pos,ios::beg);
			archivoBinario.write((char*)&r,sizeof(r));
			
			return r;
		}
	};

int main(int argc, char *argv[]) {
	
	return 0;
}

