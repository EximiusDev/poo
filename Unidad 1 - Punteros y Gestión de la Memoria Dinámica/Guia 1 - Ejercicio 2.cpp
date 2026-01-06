/*Ejercicio 2
Utilizando notación de punteros, generar un arreglo dinámico y lineal de N
elementos numéricos enteros, con valores aleatorios entre 1000 y 1500, y muestre
en pantalla la dirección de memoria del mayor elemento. N es un dato ingresado
por el usuario.*/
#include <iostream>
using namespace std;

int *mayor(int* , int );

int main() {
	int n;
	cin>>n;
	
	int *arDim = new int[n]; //creo un arreglo dinamico ("vector" hecho con un puntero)
	for(int i=0;i<n;i++) { 
		*(arDim+i) = rand() %501 +1000;
		cout<<(arDim+i)<<": "<<*(arDim+i)<<endl;
	}
	cout<<endl;
	
	int *may;
	may = mayor(arDim, n);
	

	cout<<"Direccion del mayor del arreglo dinamico: "<<may<<", Valor del mayor: "<<*may<<endl;
	
	delete []arDim;
	
	return 0;
}

int *mayor(int* v, int cant){
	int *mayo; /// puntero de direccion de mayor
	mayo = new int;
	*mayo = 0; 
	//mayo = nullptr;
	/// int *mayo = (v+0); //Me ahorro todo lo anterior en la funcion
	
	int ma;
	
	
	for(int i=0;i<cant;i++) { 
		if(*(v+i) > *mayo){
			mayo = (v+i); // Cambia la direccion a la que apunta el puntero
			/// *mayo = *(v+i); 
			/* parece que da lo mismo que el anterior
			pero no cambia la direccion del puntero,
			sino que guarda el dato que estaba apuntado en el otro puntero,
			no la direccion de memoria del dato guardada en el puntero
			*/
		}
		if(*(v+i) > ma) ma = *(v+i); // guarda el valor, no probar, incompatible con la funcion
	}
	return mayo;
}
