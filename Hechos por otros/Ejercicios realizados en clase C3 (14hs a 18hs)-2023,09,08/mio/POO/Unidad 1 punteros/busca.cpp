#include <iostream>
using namespace std;

int * busca(int *x, int c, int vb){
	for(int i=0;i<c;i++) { 
		if(*(x+i)==vb)
			return x+i;
	}
	return nullptr;
}

int main(int argc, char *argv[]) {
	int v[]={6,34,2,35,7,3,1,2,5,9};
	int *p;
	p=busca(v,10,17);
	cout<<"\nvalor encontrado en la dirección: "<<p;
	cout<<"\nindice: "<<p-v;
	
	return 0;
}

