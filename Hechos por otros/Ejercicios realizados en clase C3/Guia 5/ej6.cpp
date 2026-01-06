#include <iostream>
#include <fstream>
using namespace std;


int BuscaYReemplaza(string archivo, string bus, string reem){
	ifstream t(archivo);
	string todo="",lin;
	int p=0,cant=0;
	if(t.is_open()){
		while (getline(t,lin))
			todo+=lin+"\n";
		t.close();
		p=todo.find(bus,p);
		while(p!=string::npos){
	    	todo.replace(p,bus.length(),reem);
			cant++;
			p=todo.find(bus,p+reem.length());
		}
		ofstream t1(archivo,ios::trunc);
		t1<<todo;
		t1.close();
	} else cant=-1;
	return cant;
}
int main(int argc, char *argv[]) {
	cout<<"Reemplazos: "<<BuscaYReemplaza("palabras.txt","---","a")<<endl;
	return 0;
}

