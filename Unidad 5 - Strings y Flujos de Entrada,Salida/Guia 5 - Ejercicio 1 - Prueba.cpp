#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* Ejercicio 1
Escriba un programa que cargue en un vector de strings una lista de palabras
desde un archivo de texto (que contendrá una palabra por línea), muestre en
pantalla la cantidad de palabras leídas, las ordene en el vector alfabéticamente, y
reescriba el archivo original con la lista ordenada.
Ayuda: para ordenar un vector v de principio a fin puede utilizar la sentencia
“sort(v.begin(),v.end());”.
*/


int main() {
	
	vector<string>Palabras;
	string s1;
	
	ifstream Archi_lect("Palabras.txt"); /// abro en archivo de texto en lectura
	
	if (Archi_lect.is_open()){  /// si el archivo se abre (verfico por si no lo encuentro o no se abre correctamente):
		Archi_lect >> s1; ///leo el archivo y lo asigno en s
		cout<<s1<<endl;
		
		Archi_lect.ignore(); /// antes de un getline usar el ignore (sino no funciona bien)
		getline(Archi_lect, s1); /// tambien fuenciona el getline (para este caso particular hacen lo mismo)
		
		Palabras.push_back(s1); // pongo la variable en el vector
		
		cout<<Palabras[0]<<endl; /// muestro en pantalla lo leido en el archivo
		
		
		
		Archi_lect.close(); /// cierro el archivo
	}
	
	
	
	return 0;
}

