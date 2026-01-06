#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <cstdlib>
using namespace std;

template <class T>

class MiVector{
public:
	vector <T> v;
int l;
public:
	MiVector();
	void eliminar(T d);
	T verRango(int r1, int r2);
};

template <class T>

MiVector<T>::MiVector(){
	ifstream archi("D:/vec.txt");
	int c=0;
	string aux;

	while (archi){
	getline(archi, aux, ' ');
	
	v.push_back(atoi(aux.c_str()));
	
	c++; 
	}
	c--;
	
}

int main(int argc, char *argv[]) {
	MiVector<int> abc;
	cout << abc.v[1];
	return 0;
}

