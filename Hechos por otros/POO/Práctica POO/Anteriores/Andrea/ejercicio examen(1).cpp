#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <cstdlib>
using namespace std;

template <class T>

class MiVector{
vector <T> v;
//iterator<T>it;
int l;
public:
	MiVector();
	void eliminar(T d);
	void ordenarRango(int p);
	T verRango(int r1, int r2);
	void mostrar();
};

template <class T>
MiVector<T>::MiVector(){
	ifstream archi("vec.txt");
	int c=0;
	T aux;
	
	while (archi){
		archi >> aux;
//		getline(archi, aux, ' ');
		v.push_back(aux);
		c++; 
	}
	c--;
	
	l=c;
}

template <class T>
void MiVector<T>::eliminar(T d){
	remove(v.begin(), --v.end(), d);
}

template <class T>
void MiVector<T>::mostrar(){
	cout<<endl<<endl;
	for (int i=0;i<l;i++){
		cout<<v[i]<<" ";
	}
}

template <class T>
void MiVector<T>::ordenarRango(int p){
	typename vector<T>::iterator i=v.begin()+p-1;
	sort(i, v.end());
}

template <class T>

T MiVector<T>::verRango(int r1, int r2){
	cout<<endl<<endl;
	for (int i=r1;i<r2;i++){
		cout<<v[i]<<" ";
	}
}

int main(int argc, char *argv[]) {
	MiVector<string> abc;
	cout<<"Mi Vector: "<<endl;
	abc.mostrar();
	cout<<endl<<endl<<"Borro un elemento: "<<endl;
//	abc.eliminar(5);
	abc.mostrar();
	cout<<endl<<endl<<"Ordeno un rango: "<<endl;
	abc.ordenarRango(3);
	abc.mostrar();
	cout<<endl<<endl<<"Muestro un rango: "<<endl;
	abc.verRango(3, 7);
	
	
	return 0;
}

