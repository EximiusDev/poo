#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
struct clave{
	string campo,valor;
};
class ConfigFile{
	vector<clave> v;
	string nomarch;
public:
	ConfigFile(string n): nomarch(n){
		ifstream archi(nomarch);
		if (!archi.is_open()) {
			cout << "No se pudo abrir el archivo " << nomarch << endl;
			return;
		}
		string linea;
		clave aux;
		while(getline(archi,linea)){
			if(linea.empty()) continue;     
			if(linea[0]=='#' ) continue;        // linea.substr(0,1) == "#"  ó linea.find("#")==0 
			if(linea.find("=") == string::npos ) continue;
			aux.campo = linea.substr(0,linea.find("="));
			aux.valor = linea.substr(linea.find("=")+1);
			v.push_back(aux);
		}
		archi.close();
	}

	string Ver(string x){
		for(size_t i=0;i<v.size();i++) 
			if (v[i].campo == x) return v[i].valor;
		return "";	
	}
	
	clave verclave(int x){return v[x];}
	
	int vercantclaves(){return v.size();}
	
	void Modificar(string x, string nuva){
		for(size_t i=0;i<v.size();i++) 
			if (v[i].campo == x) {
				v[i].valor=nuva;
				return;
			}
	}
		
	void ActualizarArc(){
		ofstream archi(nomarch,ios::trunc);
		for(size_t i=0;i<v.size();i++) 
			archi<<v[i].campo<<"="<<v[i].valor<<endl;
		archi.close();
	}
};

int main(int argc, char *argv[]) {
    ConfigFile C("configuracion.txt");
	cout<<"Claves leidas:\n";
	for(int i=0;i<C.vercantclaves();i++) { 
		cout<<C.verclave(i).campo<<"="<<C.verclave(i).valor<<endl;
	}
	string a,b;
	cout<<"\nIngrese el nombre de un campo para ver su valor: ";
	getline(cin,a);
	cout<<"\n\n"<<"valor del campo \""<<a<<"\"  ----> "<<C.Ver(a)<<endl<<endl;
	cout<<"Ingrese el nombre de un campo y un nuevo valor para asignarle: ";
	getline(cin,a);
	getline(cin,b);
	C.Modificar(a,b);
	C.ActualizarArc();
	cout<<"\narchivo actualizado";
	return 0;
}
