#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

//	ifstream archi ("D:/REVISION.TXT");
//	string x,buffer;
//	x="";
//	while (archi){
//		getline(archi, buffer, '\n'); //  Guarda la ultima palabra. Con '\n' no guarda nada.
//		x+=buffer;
//	}
//	
//	cout<<x;
	
	string A = "Hola mundo mundo mundo";
	string B = "mundo";
	string C = "Andrus";
	
	while((int)A.find(B)>0)
	{
		A.replace(A.find(B),C.size(),C);
	}
	cout << A;
	int x = atoi(A.c_str());

	return 0;
}

