/// programa para generar un archivo binario con nros enteros entre 0 y 100

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {

//	srand(time(NULL)); // descomentar para que no genere siempre los mismos
	
	int n;
	cout<<"Cantidad de numeros: ";
	cin>>n;
	
	ofstream archi("numeros.dat",ios::binary|ios::trunc);
	if (!archi.is_open()){
		cerr<<"No se pudo abrir el archivo."<<endl;
		return 1;
	}
	
	int x;
	for(int i=0;i<n;i++) { 
		x=rand()%101;
		cout<<x<<endl;
		archi.write((char*)&x,sizeof(int));
	}
	
	archi.close();
	return 0;
	
}

