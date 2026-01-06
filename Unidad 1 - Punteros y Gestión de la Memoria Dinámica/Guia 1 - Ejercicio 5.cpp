#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	
	int * vect = new int [n];
	for(int i=0;i<n;i++) { 
		//* (vect + i) = rand() %500 + 1000; 
		vect[i] = rand() %500 + 1000; 
	}
	for(int i=0;i<n;i++) { 
		cout<<(vect + i)<<" : "<< *(vect + i) <<endl;
	}
	cout<<endl;
	
	int mayor = -1;
	int *dir_mayor;
	for(int i=0;i<n;i++) { 
		if (mayor< *(vect + i)){
			mayor = *(vect + i);
			dir_mayor = (vect + i);
		}
	}
	cout<<mayor<<" : ";
	cout<<dir_mayor;
	cout<<endl;
	
	return 0;
}

