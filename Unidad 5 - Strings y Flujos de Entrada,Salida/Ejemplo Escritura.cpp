#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
	
	srand(time(0));
	
	string cadena_string;
	ofstream archi_salid("Escritura.txt"); ///es lo  mismo que: //ofstream f("Escritura.txt",ios::trunc)
	// ofstream f("Escritura.txt",ios::trunc) // trunc sobreescribe (borra o crea un archivo)
	
	for(int i=0;i<10;i++) { 
		archi_salid<<rand()%10<<endl;
	}
	archi_salid.close();
	
	
	
	string cad;
	ifstream archi_escritura("Escritura.txt");
	
	int cont=0;
	while(archi_escritura>>cad){ /// mientras siga leyendo va a seguir
		cont++;
		cout<<cont<<". "<<cad<<endl;
	}
	archi_escritura.close();
	
	/*
	while((getline(cin,cadena_string))){
		cout<<cadena_string<<endl;
	}
	while(cin>>cadena_string){
		cout<<cadena_string<<endl;
	}
	f.close();
	
		//while(getline(entrad,cadena_string))
		//while(ent>>cadena_string)
	*/
	
	return 0;
}

