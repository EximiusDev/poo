#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

void creainscriptos(){
	ofstream f("inscriptos.txt",ios::trunc);
	for(int i=1;i<=100;i++) { 
		f<<"Alumno"<<i<<endl;
	}
	f.close();
}

int main(int argc, char *argv[]) {
    //creainscriptos();	
	
	ifstream archi("inscriptos.txt");
	stringstream nombrearc;
	string al;
	ofstream sal("comision1.txt",ios::trunc);
	
	if (archi.is_open()){
		int comision=1;
		int cont=0;
		while (archi>>al){
			if (cont==30){
				sal.close();
				comision++;
				nombrearc<<"comision"<<comision<<".txt";
				sal.open(nombrearc.str(),ios::trunc);
				cont=0;
				nombrearc.str("");
			}
			sal<<al<<endl;
			cont++;
		}
		sal.close();
		
	}else
		cout<<"error de apertura\n";
	return 0;
}

