#include <iostream>
#include <ctime>
using namespace std;

int main() {
	
	/// srand(time(0)); /// hace distintos los valores de rand() cada vez que se ejecute
	
	/// al correr el programa ver las posiciones de memoria que usa
	//se puede observar que algunos punteros ocupan espacios sucesivos
	
	int var = 0;
	cout<<"var = "<< &var << endl; /// la direccion de var
	int & alias = var; /// el alias es otro nombre para una variable
	cout<< &alias;		/// apunta a la direccion del dato original del alias
	cout<<" (alias) = "<< alias << endl; /// apunta al dato 
	cout << endl;
	
	/// int *punt1 = 99; // ERROR
	int var1 = 1;
	cout<<"var1 = "<< &var1 << endl; // la direccion de var
	int * punt1; /// es un puntero
	punt1 = & var1; /// punt1 toma la dirección de memoria de var1
	cout<< punt1; // la direccion de punt1
	cout<<" (punt1) = "<< *punt1 << endl; // muestro el dato apuntado por punt1
	* punt1 = 101;	/// cambio el valor del dato que apunta punt1
	cout<< punt1 <<" (punt1) = "<< *punt1 << endl;
	cout << endl;
	
	
	int n = 5;
	//int * v = new int[10]; ///los punteros definidos con el new se llaman punteros dinamicos 
	int * v = new int[n]; ///los punteros definidos con el new tienen reservado un espacio de memoria y a ese espacio le asigno un puntero 
	// v es un punter que apunta al 1er entero de todo el espacio reservado para los n enteros (es decir el espacio perservado es n * el espacio que ocupa un entero)
	
	for(int i = 0; i < n; i++){
		*(v+i) = rand()%11 + 10; // v es un punter
	}
	for(int i = 0; i < n; i++){
		cout<< v+i <<" (v+i) = "<< *(v+i) << endl;
	}
	cout << endl;
	
	
	int * punt2 = new int; /// no necesita una variable asignada
	cout <<"punt2 : ";
	cin >> * punt2;
	cout<< punt2 <<" (punt2) = "<< *punt2 << endl;
	cout<<endl;
	
	
	
	int   &var2 = *punt2;   /// le puedo asignar a una variable el valor que apunta el puntero
	cout <<"var2 = "<< var2 << endl;
	cout<<endl;
	
	
	
	
	int * punt3 = new int;
	cout<< punt3 <<" (punt3) = "<< *punt3 << endl;
	
	int var3 = 103;
	*punt3 =  var3;  /// puedo asignarle a un puntero el valor de la variable (sin modificar la posicion que apunta el mismo)
	cout<< punt3 <<" (punt3) = "<< *punt3 << endl;
	cout<<endl;
	
	
	int var4 = 4;
	int * punt4 = &var4;  /// puntero no dinamico
	
	cout<< punt4 <<" (punt4) = "<< *punt4 << endl;
	cout<<"var4 = "<< var4 <<endl;
	
	*punt4 = 104;
	cout<<"var4 = "<< var4 <<endl;
	cout << endl;
	
	
	
	punt1 = punt4; /// cambio la posicion donde apunta el puntero 
	cout<< punt1 <<" (punt1) = "<< *punt1 << endl;
	cout << endl;
	
	
	punt2 = punt3; /// cambio la posicion donde apunta el puntero dinamico
	cout<< punt2 <<" (punt2) = "<< *punt2 << endl;
	cout<<endl;
	
	delete []v; /// livero la mer¿moria ocupada por v
	
	delete punt2;  /// se eliminan los punteros inicializados con el new int
	delete punt3;
	
	punt2 = nullptr; // se pone el nullptr para que si se usa el puntero ya eliminado el programa reviente (sino no nos damos cuenta del error)
	punt3 = nullptr;
	
	///	delete punt1; /// No es necesario borrar punt1, porque no se uso new int para inicializardo
	
	return 0;
}

