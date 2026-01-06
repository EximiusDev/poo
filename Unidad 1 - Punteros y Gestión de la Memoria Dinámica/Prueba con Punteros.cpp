#include <iostream>
#include <ctime>
using namespace std;

int main() {
	
	/// srand(time(0)); /// hace distintos los valores de rand() cada vez que se ejecute
	
	int *v = new int[10];
	
	/// int *d = 99; // ERROR
	int var;
	int *d;
	d = & var;
	*d = 99;
	
	int *b = new int;
	
	int *h = new int;
	
	int a = 10;
	int *k = &a; 
	
	for(int i = 0; i < 10; i++){
		*(v+i) = rand()%11 + 10;
	}
	
	for(int i = 0; i < 10; i++){
		cout<< v+i <<" (v+i) = "<< *(v+i) << endl;
	}
	
	int c = 100;
	
	/// *b =  &c;  /// Error
	
	/// b =  c;  /// Error
	
	/// *b =  c; /// guarda el val de la var c en el puntero b
	
	/// &c =  *b; /// Error
	
	/// &b =  *c; /// Error
	
	///	*b = *d; ///No sigue el prog, Variable de salida
	
	///	b = d; ///No sigue el prog, Variable de salida
	
	/// *b =  d; /// Error
	
	/// *b = &d; /// Error
	
	/// &b = d; /// Error
	
	/// *d = b; /// Error
	
	/// *d = &b; /// Error
	
	/// d = &b; /// Error
	
	/// c = &b; /// Error
	
	///	int z = *b; 
	
	cin >> *h;
	
	int   &z = *h; 
	
	*b =  c;
	
	cout << endl;
	cout << z << endl;
	
	cout<< h <<" (h) = "<< *h << endl;
	cout<<endl;
	cout<< d <<" (d) = "<< *d << endl;
	
	
	
	cout<< b <<" (b) = "<< *b << endl;
	
	cout<< k <<" (k) = "<< *k << endl;
	cout<< a <<endl;
	
	delete []v;
	///	delete d; /// No es necesario borrar d porque no se uso new int para inicializardo
	
	delete b;
	
	delete h;
	
	///	delete k; /// k tampoco se inicializo con new int
	
	return 0;
}

