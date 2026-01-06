#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;
struct par{
	int ent;
	float flo;
};
int main(int argc, char *argv[]) {
	/*fstream f("grupo.dat",ios::binary|ios::in|ios::out|ios::trunc);
	srand(time(0));
	par aux;
	for(int i=0;i<20;i++) { 
		aux.ent=rand()%100;
		aux.flo=rand()%1000/100.0;
		f.write(reinterpret_cast<char*>(&aux), sizeof(aux));
		cout<<aux.ent<<"  "<<aux.flo<<endl;
	}
	f.close();
	*/
	fstream f("grupo.dat",ios::binary|ios::in|ios::out);
	f.seekg(0,ios::end);
	int cant=f.tellg()/sizeof(par);
	cout<<cant<<endl;
	f.seekg(0);
	par aux;
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*>(&aux), sizeof(aux));
		cout<<aux.ent<<"  "<<aux.flo<<endl;
	}

	int pos;
	cout<<"Ingrese la posición: "; 
	cin>>pos;
	cout<<"Ingrese el par int  y float: ";
	cin>>aux.ent>>aux.flo;
	f.seekg(pos*sizeof(par));
	f.write((char*)&aux,sizeof(aux));
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*>(&aux), sizeof(aux));
		cout<<aux.ent<<"  "<<aux.flo<<endl;
	}
		
	f.close();
	
	
	return 0;
}

