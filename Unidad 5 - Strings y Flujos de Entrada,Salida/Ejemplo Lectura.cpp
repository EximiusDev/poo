#include <iostream>
#include <fstream>
using namespace std;




int main() {
	
	ifstream eeeeeee("aaaaaa.txt");
	if (eeeeeee.is_open()){ // metodo para saber si el archivo esta abierto (de tipo bool)
		///no cierro el archivo porque nunca lo abro
	}else cout<<"ARCHIVO NO ENCONTRADO"<<endl;
	cout<<endl;
	cout<<endl;
	
	
	
	string cadena_string;
	
	ifstream entrad("Prueba.txt");
	
	if (entrad.is_open()){ // metodo para saber si el archivo esta abierto (de tipo bool)
		 
	
	///getline(entrad,s); /// lo mismo que con: getline(cin,s);
	// getline(entrad,s) // recordar que el gatline solo distingue el enter ("\n")
	int cont=0;
	while(getline(entrad,cadena_string)){ /// mientras este leyendo se va a seguir ejecutando
		cout<<cadena_string<<endl;
		cont++;
	}
	cout<<endl;
	cout<<"La cantidad de Nombres son:"<<cont<<endl;
	
	entrad.close(); /// tengo que cerrar el archivo al final (para poder realizar otra funcion sobre el archivo como escribir)
	// si no lo cierro no puedo escribir el archivo despues
	}
	else cout<<"ARCHIVO NO ENCONTRADO"<<endl;
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	ifstream ent("Prueba.txt");
	///el cin ">>" toma con enter o espacio, es decir solo una palabra
	int cont1=0;
	while(ent>>cadena_string){ /// mientras este leyendo se va a seguir ejecutando
		cout<<cadena_string<<endl;
		cont1++;
	}
	cout<<endl;
	cout<<"La cantidad de Nombres son:"<<cont1<<endl;
	ent.close();
	
	/// ESCRITURA DEL MISMO ARCHIVO
	ofstream sal("Prueba.txt",ios::app); /// app escribe al final del archivo
	sal<<endl<<"hola"<<endl;
	
	return 0;
}

