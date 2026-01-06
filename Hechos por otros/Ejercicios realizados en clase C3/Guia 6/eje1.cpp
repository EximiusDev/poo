#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct par{
	int entero; 
	float flotante;
};

int main(int argc, char *argv[]) {
	fstream f("grupo.dat",ios::binary|ios::in|ios::out|ios::trunc);
	par p;
	for(int i=0;i<200;i++) { 
		p.entero=rand()%10;
		p.flotante=rand()%1000/100.0;
		f.write(reinterpret_cast<char*>(&p), sizeof(p));
		cout<<i<<") "<<p.entero<<"\t"<<p.flotante<<endl;
	}
	f.close();
	
	return 0;
}

