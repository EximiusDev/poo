#include <iostream>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};

void redimensionar(int * &din,int n, int c){
	int * aux = new int [c];
	for(int i=0;i<n;i++) { 
		if(i<c){
			*(aux + i) = *(din + i);
		}
	}
	delete []din;
	if(n<c){
		for(int i=n;i<c;i++) { 
			*(aux + i) = 0;
		}	
	}
	din = aux;
	
}

int main() {
	
	int n=5;
	int * din = new int [n];
	for(int i=0;i<n;i++) { 
		*(din + i) = rand()%10 + 1;
		cout<<i<<". "<<(din + i)<<": "<<*(din + i)<<endl;
	}
	cout<<endl;
	
	int c=8;
	
	redimensionar(din, n, c);
	
	for(int i=0;i<c;i++) { 
		cout<<i<<". "<<(din + i)<<": "<<*(din + i)<<endl;
	}
	
	
	return 0;
}

