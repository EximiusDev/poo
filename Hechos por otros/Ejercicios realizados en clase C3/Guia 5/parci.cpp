#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
/*Ejercicio 1 (25 pts) Un archivo de código fuente es en realidad un archivo de texto. Escriba una función
“ListarIncludes” que reciba el nombre de un archivo de código c++ y retorne una lista (std::list) de
strings con todos los includes del mismo (incluyendo < y >, o las comillas; pero sin la palabra
#include). Por ejemplo, una lista resultante podría contener: <iostream>, <fstream> <vector>, “utils.h”
y “MiClase.h”. Para simplificar, considere que las líneas de los includes siempre comienzan con
#include, luego puede o no haber un espacio entre medio, y finalmente el nombre del archivo, que
puede estar entre <> o entre comillas.*/
int cant=0;
list<string> listarincludes(string nomarch){
	vector<string> v;
	list<string> dev;
	
	
	ifstream archi(nomarch);
	string pal;
	if(archi.is_open()){
		while(getline(archi,pal)){
			v.push_back(pal);
		}
		
	}
	else cout<<"no se abrio";
	
	for(string x:v)
		cout<<x<<"-------------------"<<endl;
	
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].find("#include",0) == 0){	
			v[i].erase(0,sizeof("#include"));
			if(v[i][0]==' ')
				 v[i].erase(0,1);      //elimino el espacio si lo tenia...
			dev.push_back(v[i]);
		}
	}
		return dev;
}
	int main() {
		
		list<string> ver;
		
		ver=listarincludes("ej6.cpp");
		cout<<cant;
		for( list<string>::iterator it=ver.begin(); it!=ver.end(); ++it ) { 
			cout<<*it<<endl;
		}
		
		
		
		
		return 0;
	}
	
