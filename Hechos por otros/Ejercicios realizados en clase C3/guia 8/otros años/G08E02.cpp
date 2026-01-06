//GUIA 8 - EJERCICIO 2.
/*Cree un programa que lea 10 valores flotantes menores a 50 ingresados por teclado
	y los inserte en una lista. Luego:
	a) Muestre dicha lista.
	b) Inserte en medio de cada par de elementos contiguos el promedio de dichos
	elementos y guarde la lista resultante en un archivo de texto llamado “listafloat.
	txt”.
	c) Genere otra lista de 10 reales con valores aleatorios y combínela con la primera
	utilizando el algoritmo merge. Muestre el resultado.
	d) Responda: ¿es posible ordenar solamente una porción de la lista de la misma
	manera que se hizo con el vector en el ejercicio 8.1?
	e) Elimine de la lista resultante los valores máximo y mínimo y muestre la lista
	sin dichos valores.*/

#include<iostream>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
using namespace std;  

string ver(list<float>x)     //funcion que devuelve el contenido de una lista de float
{ stringstream s;
  list<float>::iterator w;
  for(w=x.begin(); w!=x.end(); w++) { 
	  s<<*w<<" - ";
  }	
  return s.str();
}

int main( )
{
	list<float> l(10),z(10),y,m; 	//declaro listas
	list <float>::iterator p,q;		//declaro iteradores
	int c;
	srand(time(0)); 
	// mostramos el tamaño original de v
	cout<< "Tamaño de l:"<< l.size() << endl;
	// asignamos valores menores de 50
	for (p=l.begin(); p!=l.end(); p++){
		*p= (float)(rand()%500/100);}
	
	cout<<ver(l);
	
	cout<<endl;
	system("pause");
	
	//	b) Inserte en medio de cada par de elementos contiguos el promedio de dichos
	c= l.size();
	float d1,d2,prom;
	p=l.begin();
	for (int k=0; k<c-1; k++) {
		// calculamos promedio
		q=p;     //iteradores 
		d1=*q;
		advance(q,1);
		d2= *q;
		prom= (d1+d2)/2.0;
		l.insert(q,prom);
		advance(p,2);
	}
	//y guardo la lista resultante en un archivo de texto llamado “listafloat.txt”
	ofstream archi_s("C:\\listafloat.txt",ios::trunc);
	cout<<"\nElementos de l :"<<l.size()<<endl;
	for (p=l.begin(); p!=l.end(); p++){
		cout<<*p<<" - ";
		archi_s<<*p<<" - ";
	};
	archi_s.close();

	cout<<endl;
	system("pause");
	
	//	c) Genere otra lista de 10 reales con valores aleatorios y combínela con la primera
	for (p=z.begin(); p!=z.end(); p++){
		*p= (float)(rand()%3/20.0);
	}
	
	cout<<"\nLista 2, Tamaño: "<<z.size()<<endl;
	
	//copy(z.begin(),z.end(),ostream_iterator<float,char>(cout," - "));    //muestro los valores de la lista z
	 cout<<ver(z);
	
	merge(l.begin(),l.end(),z.begin(),z.end(),back_inserter(y));
	cout<<"\n\nMerge Lista 3, Tamaño: "<<y.size()<<endl;
	
	//copy(y.begin(),y.end(),ostream_iterator<float,char>(cout," - "));    //muestro la lista y
	cout<<ver(y);
	
	cout<<endl<<endl;
	system("pause");
	
	copy(y.begin(), y.end(), back_inserter(m));      // copio la lista y en m   (no es necesario)
	cout<<"\nLista 3, ordenada, Tamaño: "<<m.size()<<endl;
	m.sort();
	//copy(m.begin(),m.end(),ostream_iterator<float,char>(cout," - "));
	cout<<ver(m);
	
	cout<<endl<<endl;
	system("pause");
	
	float Max, Min;
	//y.sort();
	p= min_element(y.begin(), y.end());
	Min= *p;
	cout<<"\nMinimo= "<<Min<<endl;
	p= max_element(y.begin(), y.end());
	Max= *p;
	cout<<"\nMaximo= "<<Max<<endl;

	y.remove(Min);
	y.remove(Max);
	
	cout<<"\nLista 3, depurada sin Max ni Min, Tamaño: "<<y.size()<<endl;
	//copy(y.begin(),p,ostream_iterator<float,char>(cout," - "));
	cout<<ver(y);
	
	
	return (0);
}
