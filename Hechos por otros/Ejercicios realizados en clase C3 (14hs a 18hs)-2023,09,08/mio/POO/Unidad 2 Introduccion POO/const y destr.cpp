#include <iostream>
using namespace std;

class Miclase{
public:
	Miclase(){cout<<"crea objeto\n";}
	~Miclase(){cout<<"destruye objeto\n";}
};

	
int main(int argc, char *argv[]) {
	Miclase *p=new Miclase[5];
	cout<<"antes del return\n";
	delete []p;
	return 0;
}

