#include <iostream>
using namespace std;

int * repite_vectord(int * arreglo, int largo){
	int * vectorDoble = new int [largo*2];
	for(int i=0;i<largo;i++) { 
		*(vectorDoble + i) = *(arreglo + i);
	}cout<<endl; cout<<endl;
	/* ///FORMA ALTERNATIVA
	int x=0;
	for(int i=largo*2-1;i>largo-1;i--) { 
		*(vectorDoble + i) = *(arreglo + x);
		x++;
		cout<<i<<". "<<*(vectorDoble + i)<<endl;
	}cout<<endl; cout<<endl;
	*/
	int y = largo-1;
	for(int i=largo;i<largo*2;i++) {
		*(vectorDoble + i) = *(arreglo + y);
		y--;
		cout<<i<<". "<<*(vectorDoble + i)<<endl;
	}cout<<endl; cout<<endl;
	return vectorDoble;
}

int main() {
	
	int n=3;
	int *arreglo = new int [n];
	
	for(int i=0;i<n;i++) { 
		*(arreglo + i) = rand()%10;
		cout<<i<<". "<<*(arreglo + i)<<endl;
	}
	cout<<endl;
	
	int* arregloDoble = repite_vectord(arreglo, n);
	
	for(int i=0;i<n*2;i++) { 
		cout<<i<<". "<<*(arregloDoble + i)<<endl;
	}
	
	
	return 0;
}

