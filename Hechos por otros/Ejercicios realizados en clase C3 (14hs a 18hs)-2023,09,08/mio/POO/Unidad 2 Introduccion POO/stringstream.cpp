#include <iostream>
#include <sstream>
using namespace std;


int main(int argc, char *argv[]) {
	stringstream s;
	int x=3;
	s<<"esto es una prueba "<< x*65 <<" de stringstream\n";
    cout<<s.str();
	cout<<endl<<endl;
	s.str(""); //borra el valor anterior de s;
	s<<"esto es una prueba "<< x*65 <<" de stringstream\n";
	cout<<s.str();
	
	
	
	return 0;
}

