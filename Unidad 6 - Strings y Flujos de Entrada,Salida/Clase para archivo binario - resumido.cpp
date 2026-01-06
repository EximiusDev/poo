#include <iostream>
#include <fstream>
using namespace std;

class ArchivoBinario{
	fstream Archi;
	string m_nombre;
	int tamanio_Archi; /// tamanio en binario
public:
	ArchivoBinario(string nombre):Archi("nombre.bin",ios::binary|ios::in|ios::out|ios::ate){
		tamanio_Archi = Archi.tellg();  /// tamanio en binario
	}
	int Cantidad(){
		Archi.seekg(0,ios::end); ///NO SE QUE HACE (final del archivo?)
		return Archi.tellg()/sizeof(float); // divido por el tipo de dato el tamnio para saber la cantidad de elementos
	}
	float Leer_Elemento(int i){ /// i es el indice del archivoint pos_inicial = Archi.tellg(); // guarda la posicion en la que estaba el archivo
		Archi.seekg(i*sizeof(float)); /// indice del elemento por el tamanio
		float valor;
		Archi.read(reinterpret_cast<char*>(&valor), sizeof(float));
		return valor;
	}
	void Modificar_Elemento(int i, float nuevo){
		Archi.seekg(i*sizeof(float)); /// indice del elemento por el tamanio
		Archi.write(reinterpret_cast<char*>(&nuevo), sizeof(float));
	}
	void Agregar_Elemento(float dato){
		Archi.seekg(0,ios::end); /// va al final de archivo
		Archi.write(reinterpret_cast<char*>(&dato), sizeof(float));
	}
};

int main() {
	
	return 0;
}

