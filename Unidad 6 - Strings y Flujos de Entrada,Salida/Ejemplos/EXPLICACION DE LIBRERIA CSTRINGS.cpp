#include <iostream>
#include <cstring>  /// libreria cstrings, sirve para hacer cadenas de caracteres
using namespace std;




int main() {
	
	/// char N [30];
	/// char A[20], B[20];
	
	/// strcmp (); devuelve 0, <0 o >0 dependiendo cual de los datos es mas "grande"
	/// strcmp	("Maria", "Mariana"); /// Marria es mas chica
	/// Compara cual de los datos es menor (osea cual va primero alfabeticamente)
	
	
	///strcpy	(N, "la casa"); /// copia una cadena de char como si fuera un string osea una cadena de caracteres
	/// strcpy	(A,B); /// se crea un cstring una cadena como string pero de char
	
	string s = "perro";
	char c[10], d[10];
	strcpy(c,"gato");
	strcpy(d,"loro");
	
	/// s = c ; /// se puede igualar un string a un c string
	///pero no al revez, para es es necesario:
	
	
	strcpy(d,c); /// copiar un cstring a otro cstring
	strcpy(c,s.c_str()); /// copiar un string a un cstring
	
	cout<<s<<endl;
	cout<<c<<endl;
	
	cout<<endl;
	cout<<d<<endl;
	
	cout<<endl;
	cout<<endl;
	
	s = d;
	
	cout<<s<<endl;
	
	
	
	
	
	/// .substr /// sirve para cortar caracteres
	return 0;
}

