#include <iostream>
#include <fstream>
using namespace std;

void crea(string x, int c){
	fstream f(x,ios::binary|ios::in|ios::out|ios::trunc);
	int a;
	for(int i=0;i<c;i++) {
		a=i*5;
		f.write(reinterpret_cast<char*>(&a),sizeof(a));
	}
	f.close();
}

int posicion(string x, int valor){
	fstream f(x,ios::binary|ios::in|ios::out|ios::ate);
	int cant=f.tellg()/sizeof(int);
	int i,a;
	f.seekp(0);
	for(i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*>(&a),sizeof(a));
		if(valor<a) break;
	}
	f.close();
	return i;
}

int main(int argc, char *argv[]) {
	int a, pos, v;
	//crea("ordenados.dat",100);
	cout<<"ingrese un valor a insertar: ";
	cin>>v;
	
	//obtengo la posicion 
	pos=posicion("ordenados.dat",v);
	//cout<<pos;
	
	fstream f("ordenados.dat",ios::binary|ios::in|ios::out|ios::ate);
	int cant=f.tellg()/sizeof(int);
	f.seekp(0);
	for(int i=cant-1;i>=pos;i--) { 
		f.seekg(i*sizeof(int));
		f.read(reinterpret_cast<char*>(&a),sizeof(a));
		f.seekg((i+1)*sizeof(int));   // esta linea no haria falta ya que estoy en ese lugar despues de la lectura
		f.write(reinterpret_cast<char*>(&a),sizeof(a));
	}
	f.seekg(pos*sizeof(int));
	f.write(reinterpret_cast<char*>(&v),sizeof(v));
	f.close();
	
	f.open("ordenados.dat",ios::binary|ios::in|ios::out|ios::ate);
	cant=f.tellg()/sizeof(int);
	f.seekp(0);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*>(&a),sizeof(a));
		cout<<a<<" ";
	}
	f.close();
	
	
		
	
	return 0;
}

