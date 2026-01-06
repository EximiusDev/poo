#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;


struct Ficha { int dni; string apellido, nombres; };
bool operator==(Ficha f1, Ficha f2){
	return (f1.apellido==f2.apellido and f1.dni==f2.dni and f1.nombres==f2.nombres);
}

template<typename T>
T azar(T aux){
	aux = rand()%10;
	return aux;
}
int azar(){
	int aux = rand()%899 + 100;
	return aux;
}

template<typename T>
T mas_repetido(list<T> l){
	auto it_repetido = l.begin();
	int cont, mas = 0;
	for( auto it=l.begin(); it!=l.end(); ++it ) { 
		cont = count(l.begin(),l.end(), *it);
		if(cont>mas){
			mas = cont;
			it_repetido = it;
		}
	}
	return *it_repetido;
}


int main() {
	list<int> l(20);
	list<string> l_str(5);
	vector<int> v(10);
	//generate(l.begin(),l.end(), azar());
	for( list<int>::iterator it=l.begin(); it!=l.end(); ++it ) { 
		*it = azar(1);
		//cout<<*(it)<<endl;
		cout<<*(it)<<"  ";
	}	
	cout<<endl;
	for( auto it=l_str.begin(); it!=l_str.end(); ++it ) { 
		*it = azar('a');
		cout<<*it<<endl;
	}	
	cout<<endl;
	auto it1= l_str.begin();
	*it1 = "Martin";
	advance(it1,1);
	*it1 = "Milhouse";
	it1 = next(it1);
	*it1 = "Rafa";
	it1 = next(it1);
	*it1 = "f";
	it1 = next(it1);
	*it1 = "Milhouse";
	for(auto x:l_str) cout<<x<<endl;
	
	cout<<endl;
	int a = mas_repetido(l);
	cout<<a<<endl;
	string b = mas_repetido(l_str);
	cout<<b<<endl;
	
	list<Ficha> Fichas;
	Ficha f;
	
	ifstream leer("lista.txt");
	string aux_dni;
	//string aux_apellido;
	string aux_nombres;
	//while(getline(leer,aux_dni,' ')and getline(leer,f.apellido,',')and leer.ignore() and getline(leer,aux_nombres)){
	while(leer>>aux_dni and leer.ignore() and getline(leer,f.apellido,',')and leer.ignore() and getline(leer,aux_nombres)){
		f.dni = stoi(aux_dni);
		f.nombres = aux_nombres;
		Fichas.push_back(f);
		cout<<f.dni<<" "<<f.apellido<<", "<<f.nombres<<endl;
	}
	Ficha c = mas_repetido(Fichas);
	cout<<c.apellido<<endl;
	
	return 0;
}

