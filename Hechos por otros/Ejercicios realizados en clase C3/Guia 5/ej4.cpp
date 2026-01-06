#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct clave{
	string campo,valor;
};

class ConfigFile{
	vector<clave>v;
	string archivo;
public:
	ConfigFile(string x);
	string VerValor(string ca);
	void ModificaValor(string ca,string nuevo);
	void ActualizaArchivo();
	clave VerClave(int x){return v[x];}
	int CantClaves(){return v.size();}
	
};


ConfigFile::ConfigFile(string x){
	archivo=x;
	ifstream archi(archivo);
	string linea;
	clave aux;
	while (getline(archi,linea)){
		if (linea[0] != '#'){
			aux.campo=linea.substr(0,linea.find("=",0));
			aux.valor=linea.substr(linea.find("=",0)+1);
			v.push_back(aux);
		}
	//	cout<<"se ignoro: "<<linea<<endl;
	}
	archi.close();
}


string ConfigFile::VerValor(string ca){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].campo.find(ca,0) != string::npos){
			return v[i].valor;
		}
	}
	return "";
}

void ConfigFile::ModificaValor(string ca,string nuevo){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].campo.find(ca,0) != string::npos){
			v[i].valor=nuevo;
			break;
		}
	}
}

void ConfigFile::ActualizaArchivo(){
	ofstream ar(archivo,ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		ar<<v[i].campo<<"="<<v[i].valor<<endl;
	}
	ar.close();
}
	
int main(int argc, char *argv[]) {
	ConfigFile C("configuracion.txt");
	for(int i=0;i<C.CantClaves();i++) { 
		clave aux=C.VerClave(i);
		cout<<aux.campo<<"="<<aux.valor<<endl;
	}

	cout<<endl<<C.VerValor("carre")<<endl<<endl;
	
	C.ModificaValor("otro_campo_mas", "este es un nuevo valor cambiado");
	
	for(int i=0;i<C.CantClaves();i++) { 
		clave aux=C.VerClave(i);
		cout<<aux.campo<<"="<<aux.valor<<endl;
	}
	
	C.ActualizaArchivo();
	
	return 0;
}



