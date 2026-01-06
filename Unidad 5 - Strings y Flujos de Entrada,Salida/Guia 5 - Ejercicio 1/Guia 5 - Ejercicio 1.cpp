#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
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
	
	int contador = 0;
	
	if (Archi_lect.is_open()){ /// si el archivo se abre (verfico por si no lo encuentro):
		
		while(Archi_lect >> s1){ /// mientras leo el archivo y lo asigno en s (se aplica la accion)
			
			//Archi_lect.ignore(); /// antes de un getline usar el ignore (sino no funciona bien)
			//getline(Archi_lect, s); /// tambien fuenciona el getline (para este caso particular hacen lo mismo)
			
			Palabras.push_back(s1); // pongo la variable en el vector
			cout<<Palabras[contador]<<endl;
			
			contador++;
		}
		Archi_lect.close();
	}else cout<<"No se pudo abrir el archivo"<<endl;
	
	cout<<endl;
	cout<<"La cantadad de Palabras leidas es: "<<contador<<endl;
	cout<<endl;
	
	sort(Palabras.begin(),Palabras.end()); /// ordena alfabeticamente el vector desde el inicio hasta el final
	
	for(int i=0;i<contador;i++) { 
		cout<<Palabras[i]<<endl;
	}
	
	ofstream Archi_escr("Palabras_2.txt", ios::trunc);
	//if (Archi_escr.is_open()){ ///Para escritura con trunc no es necesario porque si no existe se crea
		for(int i=0;i<contador;i++) { 
			Archi_escr<<Palabras[i]<<endl;
		}
		Archi_escr.close();
	//}else cout<<"No se pudo abrir el archivo"<<endl;
	
	
	return 0;
}

