#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int a=10;
	int *p=new int;
	int b=6;
	cout<<"ingrese valor:";
	cin>>*p;
	cout<<&a<<"    "<<a<<endl;
	cout<<&b<<"    "<<b<<endl;
	cout<<p<<"    "<<*p<<endl;
	delete p;
	
	
	
	
	
	/*int &x=a;
	int *y=&a;
	cout<<&x<<"  "<<&a<<endl;
	cout<<&y<<"  "<<y<<"   "<<*y;
	*/
	return 0;
}

