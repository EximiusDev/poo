#include <iostream>
#include <fstream>
using namespace std;
struct par{
	int entero; 
	float flotante;
};

int main(int argc, char *argv[]) {
	fstream f("grupo.dat",ios::binary|ios::in|ios::out|ios::ate);
	par p;
	int pos=-1;
	if (f.is_open()){
		int cant=f.tellg()/sizeof(par);
		
		/*
		cout<<"ingrese un entero: "; cin>>p.entero;
		cout<<"ingrese un flotante: "; cin>>p.flotante;
		cout<<"ingrese la posicion: "; cin>>pos;

		f.seekp(pos*sizeof(par));
		f.write(reinterpret_cast<char*>(&p),sizeof(p));
		*/
		
		f.seekg(0);
		for(int i=0;i<cant;i++) { 
			f.read(reinterpret_cast<char*>(&p),sizeof(p));
			cout<<i<<") "<<p.entero<<"\t"<<p.flotante<<endl;
		}
		
		f.close();
	} else cout<<"error";
	
	return 0;
}






  











