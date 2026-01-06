#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <ctime>
using namespace std;
//Salida por pantalla

string ver(int v[], int n) {
	stringstream s;
	for(int i=0;i<n;i++)
		s << setw(5) <<right << v[i];
	return s.str();
}

int rand10() { return -10+rand()%21; }

bool es_par(int x) { return x%2==0; }

bool multip_3(int x) { return x%3==0; }

bool entremenos2y3(int x) { return x>=-2 && x<=3; }

bool menor_abs(int a, int b) { return abs(a)<abs(b); }

bool menor_abs1(int a, int b) { 
	int aa=abs(a), ab=abs(b);
	if(aa==ab) return a<b;      //si son iguales devuelvo el menor primero
	return aa<ab;             
}


//***************************************************************************
int main() {
	srand(time(0));
	int v[20];
	cout<<"\nVector generado:\n";
	generate(v,v+20,rand10);
	cout<<ver(v,20)<<endl;

	cout << "\nCant pares: " << count_if(v,v+20,es_par)<<endl;

	//otras pruebas (no se pide en el enunciado)
	cout << "\nCant multiplos de 3: " << count_if(v,v+20,multip_3);
	cout << "\nCant valores entre -2 y 3 inclusive " << count_if(v,v+20,entremenos2y3) << endl;
	
	sort(v,v+20);
	cout<<"\nDespues de sort(v,v+20):\n";
	cout<<ver(v,20)<<endl;
	
	sort(v,v+20,menor_abs);
		cout<<"\nDespues de sort(v,v+20,menor_abs):\n";
	cout<<ver(v,20)<<endl;
	
	sort(v,v+20,menor_abs1);
		cout<<"\nDespues de sort(v,v+20,menor_abs1):\n";
	cout<<ver(v,20)<<endl;
	
	
	sort(v,v+20);	
	int *p = unique(v,v+20);
	int n = p-v;
	cout<<"\nDespues de unique:\n";
	cout<<ver(v,n)<<endl;
	
	return 0;
}

