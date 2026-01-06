#include <iostream>
#include <fstream>
using namespace std;

/*Ejercicio 3
Escriba un programa que genere un archivo binario con una lista de 100 enteros
ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba
otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,
ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar
vectores auxiliares.
*/
int Tamanio_Archi(fstream &Archi){
	int tamanio = Archi.tellg();
	return tamanio;
}
int Posicion_Archi(fstream &Archi, int pos){
	
//	return Archi.seekg(pos*(sizeof (int)));
	return pos*(sizeof (int));
}
void Mover_Pos(fstream &Archi, int pos){
	Archi.seekp(pos*(sizeof (int)));
}
void Escribe_Archi(fstream &Archi, int num){
	Archi.write(reinterpret_cast<char*>(&num),sizeof(int));
}


int main() {
	fstream Archi("Datos.bin",ios::binary|ios::in|ios::out|ios::ate);
	int tam = Tamanio_Archi(Archi);
	
	return 0;
}

