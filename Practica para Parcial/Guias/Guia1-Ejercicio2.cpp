#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	
	int n = 5;
	cin>>n;
	
	int* A;
	
	A = new int [n];
	
	for(int i=0;i<n;i++) { 
		*(A+i) = rand()%501 + 1000;
	}
	
	for(int i=0;i<n;i++) { 
		cout<<i<<". "<<(A+i)<<": "<<*(A+i)<<endl;
	}
	
	delete []A;
	
	return 0;
}

