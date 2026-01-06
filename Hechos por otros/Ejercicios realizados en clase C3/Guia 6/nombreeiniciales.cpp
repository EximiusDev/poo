#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

struct Alumno{
	char nombre[20];
	char apellido[20];
};




int main(int argc, char *argv[]) {
	Alumno a;
	strcpy(a.nombre,"Juan Jose Alberto");
	strcpy(a.apellido,"Lopez");
	string s;
	s=a.apellido;
	char *tn;
	tn=strtok(a.nombre," ");
	while(tn != NULL){
		s=s+" "+tn[0]+".";
		tn=strtok(NULL," ");
	}
	cout<<s;
	return 0;
}

