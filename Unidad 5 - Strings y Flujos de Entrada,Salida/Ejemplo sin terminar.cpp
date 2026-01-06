#include <iostream>
#include <fstream>
using namespace std;




int main() {
	///Puedo abrir un archivo con control + enter (probar sobre "Palabras.txt")
	ifstream archi("Prueba.txt"); // abro el archivo (unicamente puede ser de texto (?))
	string palab;
	archi>>palab;
	
	if (archi << palab) /// si lee una palabra sigue (sino da error)
	
	
	return 0;
}

