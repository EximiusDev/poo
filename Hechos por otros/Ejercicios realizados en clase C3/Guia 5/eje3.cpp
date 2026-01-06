#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	stringstream s;
	for(int i=0;i<1;i++) { 
		s<<"listado"<<i<<".txt";
		ofstream archi(s.str(),ios::trunc);
		for(int j=0;j<90;j++) { 
			archi<<"alumno"<<j+1<<endl;
		}
		archi.close();
		s.str("");
	}
	return 0;
}

