#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
using namespace std;
string ver(list<float> &X){
	stringstream s;
	for(list<float>::iterator p=X.begin();p != X.end();p++){
		s<< *p<<", ";
	}
	return s.str();
}
//*******************************
int main(int argc, char *argv[]) {
	srand(time(0));
	//(std::list) Declaro la lista y reservo 15 posiciones
	list <float> lista(15);
	//std:: iterator, utilizado para recorrer la lista
	list<float>::iterator p;
	//Para ingresar por teclado
	cout<<"Generacion de 15 números flotantes:"<<endl;
	//for( p = lista.begin(); p != lista.end(); p++)
	//	*p= (float)(rand()%10);

	for(float &x: lista) x=rand()%10;	
		
		
		//a) mostrar por pantalla 
	cout<<"\na) lista(): tamaño:"<<lista.size()<<endl;
	
	cout<<ver(lista)<<endl;
	//b) Inserto cada 2 posiciones el promedio.
	//El iterador p apunta al primer elemento del vector
	p = lista.begin();
	list<float>::iterator a , b;
	//cout<<"\n\npares de datos para el promedio\n";
	/*int cant=lista.size();
	for (unsigned i=1; i< cant; i++){
		//Busco los dos datos
		a= p;
		b= ++p;      //aca ya adelanto el iterador
		cout<<*a<<"-"<<*b<<"  ";
		lista.insert( b,(*a + *b)/2.0);//calculo e inserto promedio
	}
	*/
	/*for( auto it=next(lista.begin()); it!=lista.end(); advance(it,2) ) {
		float p=(*it + *prev(it))/2.0;
		it=lista.insert(it,p);
	}
	*/
	for(auto it=lista.begin(); it!=lista.end(); ++it) {
		float p=(*it + *next(it))/2.0;
		it=lista.insert(next(it),p);
	}
	
	cout<<"\n\nb) lista con los promedios. Tamaño: "<<lista.size()<<endl;
	cout<<ver(lista)<<endl;

	//para ordenar parte de una lista se crea una auxiliar con el rango de lo que se quiere ordenar , se ordena y luego se reemplaza en la original con copy
	list<float> aux(next(lista.begin(),2), next(lista.begin(),10));
	cout<<ver(aux)<<endl;
	aux.sort();
	cout<<ver(aux)<<endl;
	copy(aux.begin(),aux.end(),next(lista.begin(),2));
	cout<<ver(lista)<<endl;
	
	
	
	//abrir archivo para escritura
	ofstream archi("listafloat.txt",ios::trunc);
	if(!archi.is_open()){cout<<"ERROR DE ARCHIVO";exit(1);}
	// grabar los datos de la lista en el archivo 
	p= lista.begin();
	cout<<"\nGrabar los datos de la lista en el archivo : "<<lista.size()<<endl;
	
//	for( unsigned i=0; i<lista.size(); ++i, p++ ){ 
//  o   
	for(list<float>::iterator p=lista.begin();p != lista.end();p++){
		archi<<*p<<endl; 
		cout<<*p<<", ";
	}
	archi.close(); 
	return 0;
}
