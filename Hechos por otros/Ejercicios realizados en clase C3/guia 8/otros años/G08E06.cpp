/*Ejercicio 8.6
Genere un vector de 20 elementos y asígnele valores aleatorios utilizando el algoritmo
generate. Muestre los elementos en pantalla utilizando el algoritmo copy. Luego
pídale al usuario que ingrese un valor númerico y utilice el algoritmo find para buscar
dicho valor e informar la posición del vector en la que se encuentra o si no el valor
no existe.
Prof. Gerardo Sas.-
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iterator>
using namespace std;

// function generadora de numeros:
int RandomNumber() { return rand()%100; }
int CeroAlNueve() {return rand()%10;}


int main () {
	srand(time(0));
	vector<int> v(20);
	vector<int>::iterator it;
	
	//generate (v.begin(), v.end(), RandomNumber);
	generate (v.begin(), v.end(), CeroAlNueve);
	
	cout << "v contiene:   ";
	copy( v.begin(), v.end() ,ostream_iterator<int>(cout," ") );
	cout << endl;
	int n;
	cout<<"Ingrese numero: ";cin>>n;
	// busca el primer numero 
	it = find( v.begin() , v.end(), n);
	int pos=0;
	if(it!=v.end()){
		pos= (it - v.begin())+1;
		cout<<"\nEncontrado en posicion: "<<pos<<endl;}
	else
		cout<<"No encontrado"<<endl;
	return 0;
}
