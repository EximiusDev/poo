#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct DatosTexto{
	int codigo; 
	string sector; 
	string nomApe;
	string password; 
};  

struct EscribeBin{
	int codigo; 
	char nomApe [30];
	char password[30]; 
};  

class ProcesaPassword{
	vector<DatosTexto> v;
public:
	ProcesaPassword(){
		ifstream archi("usuarios.txt");
		DatosTexto r;
		while (archi>>r.codigo>>r.sector && getline(archi,r.nomApe)){
			if(r.nomApe[0]=' ') r.nomApe.erase(0,1);   //POR SI HAY UN ESPACIO EN BLANCO AL COMIENZO
			v.push_back(r);
		//	cout<<"--"<<r.codigo<<"--"<<r.sector<<"--"<<r.nomApe<<"--"<<endl;   //PARA VERIFICAR LO QUE LEE
		}
	    archi.close();
	}
	
	void GeneraPassword(){
		for(size_t i=0;i<v.size();i++) { 
			v[i].password = v[i].sector + v[i].nomApe.substr(0,1) + v[i].nomApe.substr(v[i].nomApe.find(" ",3)+1);
//			cout<<v[i].password <<endl;    //PARA VERIFICAR LOS PASSWORD
		}
	}
		
	void CreaBinario(){
		EscribeBin aux;
		fstream f("usuarios.dat",ios::binary|ios::in|ios::out|ios::trunc);
		for(size_t i=0;i<v.size();i++) { 
			aux.codigo=v[i].codigo;
			strcpy(aux.nomApe,v[i].nomApe.c_str());
			strcpy(aux.password,v[i].password.c_str());
			f.write((char*)&aux,sizeof(aux));
		}
		f.close();
	}
	
	void MuestraBinarioParaVerificar(){
		EscribeBin aux;
		fstream f("usuarios.dat",ios::binary|ios::in|ios::out|ios::ate);
		int cant=f.tellg()/sizeof(aux);
		f.seekg(0);
		for(int i=0;i<cant;i++) { 
			f.read((char*)&aux,sizeof(aux));
		    cout<<"codigo: "<<aux.codigo<<"   nombre y apellido: "<<aux.nomApe<<"               password: "<<aux.password<<endl;   //PARA VERIFICAR LO QUE LEE
		}
		f.close();
	}
			
	
};


int main() {
	ProcesaPassword PP;
	PP.GeneraPassword();
	PP.CreaBinario();
	PP.MuestraBinarioParaVerificar();
	return 0;
}
