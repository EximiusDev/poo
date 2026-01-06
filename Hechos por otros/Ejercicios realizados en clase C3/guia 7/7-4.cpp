#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
using namespace std;
struct par{
	int n;
	float f;
};

struct cadena{
	char ca[10];
};


//funcion auxiliar para crear los archivos de trabajo de la cadena de sctring y la de struct pares
void crea(string archivo,int can){
	fstream fx(archivo,ios::in|ios::out|ios::binary|ios::trunc);
	srand(time(0));
	cadena a;
	//par a;
    for(int i=0;i<can;i++) { 
		for (int j=0;j<9;j++){
			a.ca[j]= 'A'+rand()%26;
		}
		a.ca[9]='\0';
		
	   /*		a.n=rand()%10;
			a.f=rand()%10+rand()%10/10.0;
	   */		
		fx.write(reinterpret_cast<char*>(&a),sizeof(a));
	}
	fx.close();
}
	
template <typename T>
class ManejadorArchivo{
	string nombrearch;
	vector<T> v;
public:
	ManejadorArchivo(string x);
	T &operator[](int x){return v[x];}  //con el & equivale al de obtener y modificar...
	void Actualizar();
	int cant(){return v.size();}
};

template <typename T>
ManejadorArchivo<T>::ManejadorArchivo(string x){
	nombrearch=x;
	fstream fx(nombrearch,ios::in|ios::out|ios::binary|ios::ate);
	int cant=fx.tellg()/sizeof(T);
	T aux;
	fx.seekg(0);
	for(int i=0;i<cant;i++) {  
		fx.read(reinterpret_cast<char*>(&aux),sizeof(aux));
	    v.push_back(aux);
	}
	fx.close();
}

template <typename T>
void ManejadorArchivo<T>::Actualizar(){
	fstream fx(nombrearch,ios::in|ios::out|ios::binary|ios::trunc);
	for(size_t i=0;i<v.size();i++) 
		fx.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
	fx.close();
}


int main(int argc, char *argv[]) {
  	//crea("cstring.dat",8);
	ManejadorArchivo <int> e("enteros.dat");
	for(int i=0;i<e.cant();i++) 
		cout<<e[i]<<"  ";
	cout<<endl;
	e[3]=96643;
	for(int i=0;i<e.cant();i++) 
		cout<<e[i]<<"  ";
	cout<<endl<<endl;
	e.Actualizar();
	
	ManejadorArchivo <float> f("flotantes.dat");
	for(int i=0;i<f.cant();i++) 
		cout<<f[i]<<"  ";
	cout<<endl;
	f[7]=3.1415;
	for(int i=0;i<f.cant();i++) 
		cout<<f[i]<<"  ";
	cout<<endl<<endl;
	f.Actualizar();
	
	ManejadorArchivo <par> s("structpar.dat");
	par aux;
	for(int i=0;i<s.cant();i++) 
		cout<<s[i].n<<" _ "<<s[i].f<<"  ";
	cout<<endl;
	aux.n=123;
	aux.f=45.67;
	s[1]=aux;
	for(int i=0;i<s.cant();i++) 
		cout<<s[i].n<<" _ "<<s[i].f<<"     ";
	cout<<endl<<endl;
	s.Actualizar();
	
	ManejadorArchivo <cadena> cs("cstring.dat");
	for(int i=0;i<cs.cant();i++) 
		cout<<cs[i].ca<<"     ";
	cout<<endl;
	strcpy(cs[2].ca,"prueba");
	for(int i=0;i<cs.cant();i++) 
		cout<<cs[i].ca<<"     ";
	cout<<endl<<endl;
	s.Actualizar();
	
	
	return 0;
}

