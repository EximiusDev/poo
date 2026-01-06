/*Ejercicio 8.5
El archivo “datos.txt” contiene una lista de flotantes, uno por línea. Lea el contenido
del archivo y almacénelo en una lista utilizando el algoritmo copy. Para esto haga lo
siguiente:
• Abra el archivo para lectura y cree un iterador de lectura para leer valores
flotantes que apunte al principio del archivo de la siguiente forma:
istream_iterator <float> p(archi).
• Cree otro iterador a punte al final del archivo indique el fin del archivo.
• Cree un contenedor para almacenar lo que se leerá.
• Utilice el algoritmo copy para copiar los datos del archivo al contenedor.
Luego, realice lo siguiente:
a) Calcule el promedio de los elementos del contenedor (ayuda: utilice el algoritmo
accumulate).
b) Restar dicho valor a cada elemento.
c) Guarde los datos modificados en el archivo utilizando el algoritmo copy.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char *argv[]) {
	int k;
	//Creo el archivo de flotantes******************
	ofstream archi_s("datos.txt");
	ifstream archi_e("datos.txt");
	if(!archi_s.is_open()) return 1;
	//creo un archivo de textos
	for(k=0;k<10; k++){
		archi_s<<((double)(rand()%10)/10)<<endl;
	}
	archi_s.close();
	//***********************************************
	istream_iterator <float> pp(archi_e);
	istream_iterator <float> pf;
	list <float> lista;
	// lee la lista de un archivo
	//copy(istream_iterator <float> (archi_e),istream_iterator <float> (),back_inserter(lista) );
	copy(pp,pf,back_inserter(lista) );
	
	
	// muestra la lista en pantalla
	copy( lista.begin(), lista.end() ,	ostream_iterator<float>(cout," ") );
	archi_e.close();
	float t= accumulate(lista.begin(),lista.end(),0.0);           //importante el 0.0 en lugar de 0 ya que si no, no suma bien
	float prom=t/lista.size();
	cout<<endl<<endl<< t <<" / "<<lista.size()<<" =  "<<prom<<endl;
	cout<<"\na) Promedio de los elementos del contenedor: "<<prom<<endl;
	cout<<"\nb) Restar dicho valor a cada elemento."<<endl;
	list<float>::iterator it;
	
	for (it = lista.begin();it!=lista.end();it++) 
	   replace( lista.begin(), lista.end(), *it , *it-prom);	
	
	// muestra la lista en pantalla
	//ostream_iterator<float>sal(cout," ");
	//copy( lista.begin(), lista.end(),sal );
	
	copy( lista.begin(), lista.end(),ostream_iterator<float>(cout," "));
	
	
	
	//c) Guarde los datos modificados en el archivo utilizando el algoritmo copy.	
	cout<<"\n\nValores archivados"<<endl;
	archi_s.open("datos.txt");
	copy( lista.begin() , lista.end() , ostream_iterator<float>(archi_s,"\n") );
	archi_e.close();
	archi_s.close();
	
	archi_e.open("datos.txt");
	float w;
	while(archi_e>>w)
		cout<<w<<endl;
	
	return 0;
}
