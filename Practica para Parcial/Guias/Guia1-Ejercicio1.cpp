#include <iostream>
using namespace std;

int main() {
	int a;
	int * b = new int;
	int * c;
	int * d;
	d = new int; /// sino no puedo hacerle un cout a &d (&d representa la memoria dinamica)
	a = 10;
	c = &a;
	*d = a;
	//cin>>*b;
	*b=2;
	cout<<&a<<"  "<<a<<endl;
	cout<<&b<<" "<<b<<" "<<*b<<endl;
	cout<<&c<<" "<<c<<" "<<*c<<endl;
	cout<<&d<<" "<<d<<" "<<*d<<endl;
	
	
	delete b;
	delete d;
	
	return 0;
}

