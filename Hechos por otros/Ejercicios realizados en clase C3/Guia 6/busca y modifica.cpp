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
	int pos,ev,en;
	if (f.is_open()){
		int cant=f.tellg()/sizeof(par);
		
		cout<<"ingrese un entero a modificar: "; cin>>ev;
		cout<<"ingrese un nuevo valor de entero: "; cin>>en;
		pos=0;
		f.seekg(0);
		f.read(reinterpret_cast<char*>(&p),sizeof(p));
		while(pos<cant && p.entero!=ev){
			f.read(reinterpret_cast<char*>(&p),sizeof(p));
			pos++;
		}
		
		
		if (pos<cant){
			p.entero=en;
			f.seekp(pos*sizeof(par));     //  f.seekp(-sizeof(par),ios::cur);
			f.write(reinterpret_cast<char*>(&p),sizeof(p));
		}
		
		
		
		f.seekg(0);
		for(int i=0;i<cant;i++) { 
			f.read(reinterpret_cast<char*>(&p),sizeof(p));
			cout<<i<<") "<<p.entero<<"\t"<<p.flotante<<endl;
		}
		
		f.close();
	} else cout<<"error";
	
	return 0;
}



