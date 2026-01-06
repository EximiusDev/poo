#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream Archiv("Datos.bin",ios::binary|ios::in|ios::out|ios::ate);
	
	int taman = 20;
	
	if(Archiv.is_open()){
		cout<<"Se Lee el archivo"<<endl;
		int tamanio = Archiv.tellg()/sizeof(int);
		Archiv.seekg(0);
		
		int dato;
		for(int i=0;i<tamanio;i++) { 
			Archiv.read	(reinterpret_cast<char*>(&dato),sizeof(int));
			cout<<i<<". "<<dato<<endl;
		}
		if (tamanio!=taman){
			cout<<"El archivo fue modificado"<<endl;
			cout<<"Reescribiendo el archivo"<<endl;
			
			fstream Archi("Datos.bin",ios::binary|ios::out);
			if(Archi.is_open()) cout<<"El archivo se creo de nuevo"<<endl;
			
			int valor;
			
			for(int i=0;i<taman;i++) { 
				valor = rand()%101;
				cout<<i<<". "<<valor<<endl;
				Archi.write(reinterpret_cast<char*>(&valor),sizeof(int));
			}
		} 
		
	}
	else{
		fstream Archi("Datos.bin",ios::binary|ios::out);
		if(Archi.is_open()) cout<<"Se Creo uno nuevo"<<endl;
		
		int valor;
		
		for(int i=0;i<taman;i++) { 
			valor = rand()%101;
			cout<<i<<". "<<valor<<endl;
			Archi.write(reinterpret_cast<char*>(&valor),sizeof(int));
		}
		Archi.close();
	}
	
	
	
	
	return 0;
}

