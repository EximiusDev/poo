//GUIA 8 - EJERCICIO 3.
/*Cree una lista de 15 enteros aleatorios entre 0 y 10. 
Muestre la lista antes y después de quitar los elementos repetidos. 
Haga una búsqueda bibliográfica sobre la clase ostream_iterator y utilice 
el algoritmo copy para mostrar la lista en pantalla y luego guardarla en un archivo.
*/
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;



int main(int argc, char *argv[]) {
	list<int> l(15); 	//declaro listas
	list <int>::iterator p,q;		//declaro iteradores
	int c;
	srand(time(0)); 
	cout<<"original: ";
	for (p=l.begin(); p!=l.end(); p++){
		*p= rand()%40;
		cout<<setw(4)<<*p;
	}
	cout<<endl;
	l.sort();
	
	cout<<"ordenado: ";
	
		
	for(q=l.begin();q!=l.end();q++)
		cout<<setw(4)<<*q;
	cout<<endl;
	
	p=unique(l.begin(),l.end());
	
	
	l.erase(p,l.end());
	
	cout<<"final:    ";
	for(q=l.begin();q!=l.end();q++)
		cout<<setw(4)<<*q;
	return 0;
}

