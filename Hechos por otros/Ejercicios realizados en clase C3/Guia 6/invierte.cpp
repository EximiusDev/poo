#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
void invertir(string nombre){
	fstream archi(nombre,ios::binary|ios::in|ios::out|ios::ate);
	int cant=archi.tellg()/sizeof(T);
	archi.seekg(0);
	T aux,auxiliar;
	int c=cant-1;
	for(int i=0;i<cant/2;i++){
		archi.seekg(i*sizeof(T));
		archi.read(reinterpret_cast<char*>(&aux),sizeof(T));
		archi.seekg(c*sizeof(T));
		archi.read(reinterpret_cast<char*>(&auxiliar),sizeof(T));
		archi.seekp(c*sizeof(T));
		archi.write(reinterpret_cast<char*>(&aux),sizeof(T));
		archi.seekp(i*sizeof(T));
		archi.write(reinterpret_cast<char*>(&auxiliar),sizeof(T));
		c--;	
	}
}
	
	struct par {
		int x;
		int y;};

void crea(){
	fstream f("ordenados.dat",ios::in|ios::out|ios::binary|ios::trunc);
	int a;
	for(int i=0;i<10;i++) { 
		a=10*i;
		f.write((char*)&a,sizeof(a));
	}
	f.close();
}
	
	
	int main() {
		crea();
		/*cout<<"Ingrese el nombre del archivo que guarda enteros"<<endl;
		string nom_txt; getline(cin,nom_txt);
		invertir<int>(nom_txt);
		cout<<endl;
		*/
		cout<<"Ingrese el nombre del archivo que guarda flotantes"<<endl;
		string nom_dat; getline(cin,nom_dat);
		//invertir<float>(nom_dat);
		cout<<endl;
		/*cout<<"Ingrese el nombre del archivo que guarda Pares"<<endl;
		string nom_com; getline(cin,nom_com);
		invertir<par>(nom_com);
		*/
		fstream f("ordenados.dat",ios::in|ios::out|ios::binary);
		int a;
		for(int i=0;i<10;i++) { 
			f.read((char*)&a,sizeof(a));
			cout<<a<<"   ";
		}
		f.close();
		
		return 0;
		
	}
