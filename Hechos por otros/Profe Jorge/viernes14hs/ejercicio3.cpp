#include <iostream>
#include <fstream>
using namespace std;

void genera(){
	fstream f("ordenado.dat",ios::binary|ios::in|ios::out|ios::trunc);
	int a=0;
	for(int i=0;i<100;i++) { 
		f.write((char*)&a,sizeof(a));
		a+=5;
	}
	f.close();
}

int BuscarPos(int x){
	fstream f("ordenado.dat",ios::binary|ios::in|ios::out|ios::ate);
	int a,cant=f.tellg()/sizeof(int);
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read((char*)&a, sizeof(a));
		if(x < a){
			f.close();
			return i;
		}
	}
	f.close();
	return cant;	
}

void Insertar(int p, int x){
		fstream f("ordenado.dat",ios::binary|ios::in|ios::out|ios::ate);
		int a,cant=f.tellg()/sizeof(int);
		f.seekg(0);
		for(int i=cant-1;i>=p;i--) { 
			f.seekg(i*sizeof(a));
			f.read((char*)&a, sizeof(a));
			f.seekg((i+1)*sizeof(a));
			f.write((char*)&a, sizeof(a));
		}
		f.seekg(p*sizeof(a));
		f.write((char*)&x, sizeof(x));
		f.close();
	}
	
int main(int argc, char *argv[]) {
	//genera();
	int n,a;
	cout<<"ingrese valor: ";
	cin>>n;
	int pos=BuscarPos(n);
	Insertar(pos,n);
	
	fstream f("ordenado.dat",ios::binary|ios::in|ios::out|ios::ate);
	int cant=f.tellg()/sizeof(int);
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read((char*)&a, sizeof(a));
		cout<<a<<"  ";
	}
	f.close();
	return 0;
}

