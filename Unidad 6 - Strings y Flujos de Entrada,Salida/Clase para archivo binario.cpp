#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ArchivoBinario{
	fstream Archi;
	string m_nombre;
	int tamanio_Archi; /// tamanio en binario
	int pos_lectura;
	int pos_escritura;
	int cant_elementos;
	vector<float> Lectura;
public:
	ArchivoBinario(string nombre):Archi("nombre.bin",ios::binary|ios::in|ios::out|ios::ate){
		tamanio_Archi = Archi.tellg();  /// tamanio en binario
		
		pos_lectura = 0;
		pos_escritura = tamanio_Archi;
		
		cant_elementos = Archi.tellg()/sizeof(float); // divido por el tipo de dato el tamnio para saber la cantidad de elementos
		
		float aux;
		for(int i=0;i<tamanio_Archi;i++) { 
			Archi.read(reinterpret_cast<char*>(&aux),sizeof(int));
			Lectura.push_back(aux);
		}
	}
	int Cantidad(){
		int pos_inicial = Archi.tellg(); // guarda la posicion en la que estaba el archivo
		
		Archi.seekg(0,ios::end); /// va al final del archivo
		cant_elementos = Archi.tellg()/sizeof(float); // divido por el tipo de dato el tamnio para saber la cantidad de elementos
		//return tamanio_Archi/sizeof(float); // divido por el tipo de dato el tamnio para saber la cantidad de elementos
		Archi.seekg(pos_inicial);
		return cant_elementos;
	}
	float Leer_Elemento(int i){ /// i es el indice del archivo
		int pos_inicial = Archi.tellg(); // guarda la posicion en la que estaba el archivo
		int nueva_pos = i*sizeof(float); /// indice del elemento por el tamanio
		Archi.seekg(nueva_pos); 
		float valor;
		Archi.read(reinterpret_cast<char*>(&valor), sizeof(float));
		Archi.seekg(pos_inicial);
		return valor;
	}
	void Modificar_Elemento(int i, float nuevo){
		int pos_inicial = Archi.tellg();
		int nueva_pos = i*sizeof(float); /// indice del elemento por el tamanio
		Archi.seekg(nueva_pos);
		Archi.write(reinterpret_cast<char*>(&nuevo), sizeof(float));
		Archi.seekg(pos_inicial);
	}
	void Agregar_Elemento(float dato){
		int pos_inicial = Archi.tellg();
		Archi.seekg(0,ios::end); /// va al final de archivo
		Archi.write(reinterpret_cast<char*>(&dato), sizeof(float));
		Archi.seekg(pos_inicial);
	}
	vector<float> Leer_Archi(){
		vector<float> v;
		int pos_inicial = Archi.tellg();
		Archi.seekp(0);
		float aux;
		for(int i=0;i<cant_elementos;i++) { 
			Archi.read(reinterpret_cast<char*>(&aux),sizeof(float));
			v.push_back(aux);
		}
		Lectura = v;
		Archi.seekg(pos_inicial);
		return v;
	}
};

int main() {
	
	return 0;
}

