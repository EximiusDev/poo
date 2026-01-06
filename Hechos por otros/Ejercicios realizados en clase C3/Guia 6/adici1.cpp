#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

void CreateDummyFile(string n,int tam){
   fstream archi(n,ios::binary|ios::in|ios::out|ios::trunc);
   char v;
   for(int i=0;i<tam;i++) { 
	   v=rand()%256;
	   archi.write(&v,sizeof(v));
   }
   archi.close();
}

void CreateDummyFile(string n,string s){
	string unidad,nvalor;
	unidad=s.substr(s.length()-2);
	int valor, expo=0;
	if(unidad=="Kb") expo=1;
	else if (unidad=="Mb") expo=2;
	else if (unidad=="Gb") expo=3;
	nvalor=s.substr(0,s.length()-2);
	valor= atoi(nvalor.c_str())*pow(1024,expo);
	CreateDummyFile(n,valor);
}

int main(int argc, char *argv[]) {
	CreateDummyFile("prueba.dat","130Mb");
	return 0;
}

