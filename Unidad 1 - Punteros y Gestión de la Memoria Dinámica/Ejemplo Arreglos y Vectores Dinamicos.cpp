#include <iostream>
#include <ctime>
using namespace std;

/// funcion de tipo puntero
int *genera_vector_dinam(int n){
	int *vd = new int [n]; 
	for(int i=0;i<n;i++) { 
		vd[i] = rand()%501 + 1000;
	}
	return vd;
}

int *buscar(int *v, int n, int x){
	for(int i=0;i<n;i++) { 
		if (v[i] == x) return v+i;
	}
	return nullptr; /// puntero (nulo direccion 0)
}

int main() {
	
	/// srand(time(0)); /// hace distintos los valores de rand() cada vez que se ejecute
	
	int arreglo[5]; /// un arreglo es un vector estatico (no se puede modificar su tamanio)
	//int arreglo[n]; /// no es valido
	int arreglo_mat[5][5]; /// un arreglo tambien puede ser una matriz
	
	for(int i=0;i<5;i++) { 
		arreglo[i] = rand()%101 + 100;
		cout<< "arreglo[i] : " << arreglo[i] <<endl; // se mueve [i * (espacio de entero)] espacios cada vez		
	}
	
	cout << endl; ////////////////////////////////////////////////////////////////////////////////////////
	
	/// Punteros dinamicos y vectores con punteros
	
	int n = 5;
	//cin >> n;
	float *vect = new float[n]; /// declaro un arreglo dinamico
	//float *vect; /// declaro un puntero de tipo flotante
	// = new float[n]; /// reservo "n" espacios de memoria
	/// float *vect = new float[n]; /// entonces reservo "n" espacios de memoria y le asigno el puntero creado vect al 1er espacio de memoria que reserve
	
	int *puntero = new int; /// de la misma forma reservo un espacio de memoria y le asigno un puntero 
	
	
	cout << endl;
	
	/////////////////////////////////////////////////////////  //vector dinamico 
	
	//int * v = new int[n]; ///los punteros definidos con el new se llaman punteros dinamicos 
	int * v = new int[n]; ///los punteros definidos con el new tienen reservado un espacio de memoria y a ese espacio le asigno un puntero 
	// v es un punter que apunta al 1er entero de todo el espacio reservado para los n enteros (es decir el espacio perservado es n * el espacio que ocupa un entero)
	
	for(int i = 0; i < n; i++){
		*(v+i) = rand()%11 + 10; // v es un punter
	}
	for(int i = 0; i < n; i++){
		cout<< v+i <<" (v+i) = "<< *(v+i) << endl;
	}
	cout << endl;
	
	delete []v; /// livero la mer¿moria ocupada por v
	
	///////////////////////////////////////////////// // vector dinamico (funcion)
	
	int *v_dinam = genera_vector_dinam(n); /// llamo a la funcion genera_vector_dinam (es un puntero)
	for(int i=0;i<n;i++) { 
		//cout<< &v_dinam[i]<<" v_dinam[i] : " << v_dinam[i] <<endl;
		cout<< &v_dinam[i] <<" v_dinam[i] : " << *(v_dinam + i) <<endl; // se mueve [i * (espacio de entero)] espacios cada vez		
	}
	cout << endl;
	
	int x;
	cin>>x;
	int *p1 = buscar(v_dinam, n, x);
	if (p1 == nullptr) 		cout<< "no se encuentra el valor"<<endl;
	else{
		cout <<"valor : "<< *p1 ;
		cout <<", posicion en el vector: "<< p1 - v_dinam ;
		cout <<", direccion: "<< p1 <<endl;
	}
	
	delete []v_dinam;
	v_dinam = nullptr; // se pone el nullptr para que si se usa el puntero ya eliminado el programa reviente (sino no nos damos cuenta del error)
	
	cout << endl;
	
	
	//////////////////////////////////////////////////////// //MATRICES con Punteros
	
	int alto = 6;
	int ancho = 12;
	
	/*
	arreglo de 8 elementos de tipo puntero a float: // arreglo de punteros
	float*[8] 
	Ej: float *vp[10];
	puntero a un arreglo de 8 elementos de tipo float: // puntero de arreglos
	float(*)[8] 
	Ej: float (*pv)[10];
	*/
	
	/*
	int m[6][10];
	m es de tipo "puntero a arreglo de 10"
	,
	int (*p)[10] = m;
	*/
	
	////m[i][j] = *( *(m+i)+j ) una matriz, es decir un vector o arreglo cuyos elementos son a su vez vectores o arreglos
	
	/// arreglo de punteros
	
	// int **mat_punt; /// este es una matriz de tipo puntero, cuyos elementos que conforman su vector a su vez son punteros
	
	int **mat_punt = new int*[alto]; /// entonces se crea un arreglo o vector con "alto" cantidad de punteros 
	for(int i=0; i<alto; i++){
		mat_punt[i] = new int[ancho]; /// y a cada puntero del total "alto", le reservo espacio para "ancho" cantidad de enteros 
		//(se reserva el espacio de memoria a cada uno de los "alto" arreglos)
	}
	
	for(int i=0; i<alto; i++){
		for(int j=0;j<ancho;j++) {
			*(*(mat_punt + i) + j ) = rand()%10 ; // v es un punter
		}
	}
	
	for(int i=0; i<alto; i++){
		for(int j=0;j<ancho;j++) {
			cout<< *(*(mat_punt + i)+ j) <<" ";
		}
		cout << endl;
	}
	
	cout << endl;
	cout << endl;
	
	for(int i=0; i<alto; i++){
		for(int j=0;j<ancho;j++) {
			cout<< ((mat_punt + i)+ j) <<" ";
		}
		cout << endl;
	}
	
	for(int i=0; i<6; i++){
		delete [] mat_punt[i];
		delete [] mat_punt;
	}
	
	return 0;
}

