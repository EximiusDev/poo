#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	int anio=2020;
	char tipo[]="msw10";
	for(int i=1;i<=78;i++) { 
		stringstream nombre;
		nombre<<"design"<<i<<".wds";
		cout<<nombre.str()<<endl;
		fstream f(nombre.str(),ios::in|ios::out|ios::binary);
		f.seekp(178,ios::beg);
		f.write((char*)&tipo,sizeof(tipo));
		f.seekp(239,ios::beg);
		f.write((char*)&anio,sizeof(anio));
		f.close();
		nombre.str("");
	}
	return 0;
}

