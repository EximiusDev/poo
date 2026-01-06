#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
list<int>Lista;

list<int> ListaProceso(list<int> &lista)
{
	list<int>Ordenada;
	// Los primeros dos términos que no necesariamente están ordenados.
	int A(lista.front()); lista.pop_front();
	int B(lista.front()); lista.pop_front();
	
	list<int>::iterator beg = lista.begin();
	list<int>::iterator end = lista.end();
	
	lista.pop_front();
	lista.pop_front();
	
	while (lista.size() > 0)
	{
		Ordenada.push_back(lista.front());
		lista.pop_front();
		
		if (lista.front() > A && Ordenada.back() < A)
		{
			Ordenada.push_back(A);
//			A = 0;
		}
		if (lista.front() > B && Ordenada.back() < B)
		{
//			B = 0;
			Ordenada.push_back(B);
		}
	}
	
	return Ordenada;
}


int main(int argc, char *argv[]) {
	
	Lista.push_back(12);
	Lista.push_back(13);
	Lista.push_back(1);
	Lista.push_back(2);
	Lista.push_back(3);
	Lista.push_back(4);
	Lista.push_back(5);
	Lista.push_back(20);
	Lista.push_back(25);

	list<int>resultado = ListaProceso(Lista);
	
	while (resultado.size() > 0)
	{
		cout << resultado.front() << endl;
		resultado.pop_front();
	}
	
	return 0;
}

