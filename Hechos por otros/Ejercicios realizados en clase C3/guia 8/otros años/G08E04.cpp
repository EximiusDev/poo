/*Ejercicio 8.4
	Genere un arreglo estático (no un vector STL) de 20 elementos enteros aleatorios
	entre 0 y 10. Luego:
	• Utilice los algoritmos genéricos de la STL para ordenarlo y eliminar los elementos
	repetidos.
	• Utilice el algoritmo copy para mostrar el arreglo resultante.
	• Responda: ¿Pueden los algoritmos de la STL eliminar realmente los elementos
	y liberar la memoria del vector? Justifique su respuesta.
*/

#include<iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;
int main( ){
	srand(time(0));
	int v[15];			//crea un vector de 15 elem.
	int *p;
	int i;
	cout<<"Arreglo original de 15 posiciones"<<endl;
	for (i=0; i<15; i++){
		v[i]= rand()%10;		// asignamos valores flotantes
		cout<<setw(2)<<v[i];	//Muestro por pantalla
	};
	p=&v[0];
	cout<<"\n\nOrdeno el arreglo"<<endl;
	sort (p,(p+15));
	copy(p,(p+15),ostream_iterator<int,char>(cout," "));    //Muestro con copy por pantalla
	cout << endl<<endl;

	cout<<"Muestro los no repetidos"<<endl;
	p= unique(v,(v+15));
	copy(v,p,ostream_iterator<int,char>(cout," ")); //Muestro con copy por pantalla, hasta p que marca los repetidos
	cout << endl<<endl;
	return 0;
}

// no elimina realmente los datos ya que accede a traves de los iteradores y no a la clase
