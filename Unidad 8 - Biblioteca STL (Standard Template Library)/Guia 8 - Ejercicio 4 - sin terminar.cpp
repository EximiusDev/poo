#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int rand10(){ /// anda
	int azar = rand()%21;
	return azar - 10;
}

bool es_par(int x){ /// anda
	if (x%2 == 0 ){
		return true;
	}
	return false;
}

bool menor_abs(int a, int b){ /// anda
	/*
	if (a<0) a = a*(-1);
	if (b<0) b = b*(-1);
	
	if (a<b) return true;
	return false;
	*/
	///sino
	return abs(a)< abs(b);
	/// para resolver la eliminacion de valores correctamente se usa la funcion de abajo:
}
	
bool menor_abs1(int a, int b){ /// anda
	/// para resolver la eliminacion de valores correctamente:
	int aa = abs (a);
	int bb = abs (b);
	if(aa==bb) return a < b;
	return aa<bb;
}
	

int main() {
	srand(time(0)); /// valores aleatorios distintos cada vez
	///vector<int>v[20];
	int v[20];
	
	generate(v,v+20,rand10); /// generate(v.begin,v.end,rand10());
	
	for(int i=0;i<20;i++) { ///for(int i=0;i<v.size();i++) { 
		cout<<v[i]<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	int pares = count_if(v, v+20, es_par);
	
	cout<< pares;
	cout<<endl;
	
	sort(v,v+20,menor_abs1);
	
	for(int i=0;i<20;i++) {
		cout<<v[i]<<" ";
	}
	
	int *p = unique (v,v+20);
	int cant = p - v;
	
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<cant;i++) {
		cout<<v[i]<<" ";
	}
	
	return 0;
}

