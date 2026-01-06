#include <iostream>
#include <fstream>
using namespace std;

/*Ejercicio 4
Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos
y atributos para manipular un archivo binario que contenga registros del tipo de
dato especificado por el parámetro. La clase debe poseer métodos para:
a. Abrir un archivo binario y cargar los registros en memoria.
b. Obtener el registro en una posición especificada por el usuario.
c. Modificar el registro en una posición determinada.
d. Actualizar la información del archivo con los cambios.
e. Utilice la clase desde un programa cliente para leer los registros escritos en
el archivo binario generado en el ejercicio 6.5.
*/
template<typename T> // template<class T>

class ManejadorArchivo{
	fstream ArchivoBinario;
	vector<T>v; /// vector de elementos genericos
public:
	ManejadorArchivo(string nombre, PunteroFuncion tipoDato){
		ArchivoBinario(nombre,ios::in|ios::out|ios::ate);
	}
		
};


int main() {
	
	return 0;
}

