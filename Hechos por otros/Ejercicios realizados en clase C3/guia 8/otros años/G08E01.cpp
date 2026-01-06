/*Escriba un programa que defina un vector dinámico de 30 enteros aleatorios menores
	que 50. Luego:
	a) Muestre el vector generado.
	b) Ordene en forma ascendente los elementos ubicados entre las posiciones
	10 y 20 inclusive. Luego muestre el vector.
	c) Quite del vector los elementos que fueron ordenados en el apartado anterior
	e insértelos en un nuevo vector
	d) Muestre el nuevo vector sin elementos repetidos.
	e) Elimine uno por uno los elementos del nuevo vector a partir de su última posición.
	Muestre el vector resultante luego de cada eliminación.
	*/
	//---------------------------------------------------------------------------
//GUIA 8 - EJERCICIO 1.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;  //muy importante

int main( )
{  
	vector <int> v(30), aux2;//crea un vector de 30 elem. y 1 auxiliar
	vector <int>::iterator p;//crea el iterador (puntero)
	int i;
	v.e
	srand(time(0)); 
	// mostramos el tamaño original de v
	cout<< "Tamaño de v:"<< v.size() << endl;
	// asignamos valores menores de 50
	for (i=0; i<v.size(); i++)
		v[i]= rand() % 50;
	// mostramos los elementos de v
	cout<<"a) Elementos de v:"<<endl;
	int c;
	for (p=v.begin(); p!=v.end();p++)
	    cout<<*p<<" ";
	
	cout<<endl<<endl;
	system("pause");
	
	cout<<"\nb) Ordenamos el vector desde la pos 10 a la 20:"<<endl;
	sort(v.begin()+9, v.begin()+20);//ordena 10 a 20
	// c) mostramos los elementos de v
	for (p=v.begin(); p!=v.end();p++)
		cout<<*p<<" ";
	
	cout<<endl<<endl;
	system("pause");
	
	cout<<"\nc) Quite del vector los elementos que fueron ordenados en el apartado anterior e insértelos en un nuevo vector"<<endl;
	copy(v.begin()+9,v.begin()+19, back_inserter(aux2));
	v.erase(v.begin()+9,v.begin()+19);
	//Muestro lo quedo en v
	for (p=v.begin(); p!=v.end();p++)
		cout<<*p<<" ";
	
	cout<<"\n\nd) Vector Auxiliar con posiciones 10 a 20"<<endl;
	copy(aux2.begin(),aux2.end(),ostream_iterator<int,char>(cout," ")); 
	cout<<endl<<endl;
	
	system("pause");
	
	cout<<"\ne) Elimine uno por uno los elementos del nuevo vector a partir de su última posición."<<endl;
	cout<<"\noriginal:  ";
	copy(aux2.begin(),aux2.end(),ostream_iterator<int,char>(cout," ")); 
	for (c=1,p=aux2.begin(); p!=aux2.end();c++)
		{ aux2.pop_back();
		cout<<"\nciclo "<<c<<":   ";
		copy(aux2.begin(),aux2.end(),ostream_iterator<int,char>(cout," ")); 
		}
	return (0);
}
