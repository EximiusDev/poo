#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/* Ejercicio 8.1
Escriba un programa que permita al usuario ingresar 15 valores por teclado, los
almacene en un vector y luego:
a. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes.
1. utilizando el operador []
2. utilizando iteradores
3. utilizando el for basado en rangos
4. ¿en qué caso es conveniente utilizar cada mecanismo?
b. Calcule y muestre
1. los valores de los elementos máximo y mínimo
2. la suma de todos los elementos del arreglo
3. el promedio y la mediana de los elementos del arreglo
c. Permita al usuario ingresar un valor, e informe si se encuentra en el vector,
y en caso afirmativo, en qué posición.

*/

int main() {
	
	int n = 15;
	
	vector<float> v(n,0);
	
	
	for(unsigned int i=0;i<v.size();i++) { 
		v [i] = rand()%1000/10.0f;
		cout<<i<<".  "<<&(v[i])<<" : "<<v[i]<<endl;
	}
	
	cout<<endl;
	
	
	for( vector<float>::iterator it=v.begin(); it!=v.end(); ++it ) { 
		cout<<&it<<" : "<<*it<<endl;
	}
	
	
	
	cout<<endl;
	
	int cont=0;
	for(float x : v) { 
		//x = rand()%100;
		cout<<cont<<".  "<<x<<endl;
		cont++;
	}
	
	/*
	for( auto::iterator it=v.begin(); it!=v.end(); ++it ) { 
		*(v + it)= rand()%100;
	}	*/
	
	cout<<endl;
	
	auto itmin = min_element(v.begin(),v.end());
	auto itmax = max_element(v.begin(),v.end());
	
	cout<<"min "<<&itmin<<" : "<<*itmin<<endl;
	cout<<"MAX "<<&itmax<<" : "<<*itmax<<endl;
	
	float suma = accumulate(v.begin(),v.end(),0);
	cout<<"Suma "<<suma<<endl;
	
	float promedio = suma*1.0/v.size();
	cout<<"Promedio "<<promedio<<endl;
	
	cout<<endl;
	
	vector<float>v2;
	v2 = v;
	sort(v2.begin(),v2.end());
	
	for(unsigned int i=0;i<v2.size();i++) { 
		cout<<i<<".  "<<v2[i]<<endl;
	}
	
	float mediana = v2[v2.size()/2];
	cout<<"Mediana "<<mediana<<endl;
	
	float buscado = 10;
	
	auto itbuscar = find(v.begin(),v.end(),buscado);
	cout<<"Valor buscado "<<&itbuscar<<" : "<<*itbuscar<<endl;
	
	return 0;
}

