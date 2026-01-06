#include <iostream>
#include <fstream>
using namespace std;

void reemplaza(string archi, string bus, string reemp){
	string linea,todo="";
	ifstream t(archi);
	while (getline(t,linea)){
		todo=todo+linea+"\n";
	}
	t.close();
    cout<<todo;
	int p;
	p=todo.find(bus);     //por omision comienza de 0
	while(p != string::npos){
		todo.replace(p, bus.length(),reemp);
		p=todo.find(bus,p+reemp.length());  //busco a partir de lo que acabo de insertar}
	}
	//cout<<"\nReemplado todo\n";
	ofstream t1(archi,ios::trunc);
	t1<<todo;
	t1.close();
}



int main(int argc, char *argv[]) {
    reemplaza("enunciado.txt","m",".");
	return 0;
}

