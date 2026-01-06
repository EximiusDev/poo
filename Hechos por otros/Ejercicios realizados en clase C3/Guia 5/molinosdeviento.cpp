#include <iostream>

using namespace std;
string minusculas(const string &cad){
	string aux=cad;
	for(char &x: aux)
		x=tolower(x);
	return aux;
}


int main(int argc, char *argv[]) {
	string todoeltexto="", linea,sm;
	int cont=0;
	
	/*ifstream archi("texto.txt");
	while(getline(archi,linea)){
		todoeltexto += linea+" ";
	}
	archi.close();
	*/
	
	todoeltexto="Esto es UNA prueba de MAYUSculas a minuSCULAS y contar cuantas veces aparece, SIN QUe SEA relevante como esta escrito";    //comenta esta linea y descomenta el bloque de arriba para usar archivos
	
	sm=minusculas(todoeltexto);
	
	cout<<"texto: \n"<<todoeltexto<<endl;
	cout<<"\ntexto en minusculas: \n"<<sm<<endl<<endl;
	
	
	string cadenaabuscar="ta";    //aca irua "molinos de viento"
	
	size_t pos=sm.find(cadenaabuscar);
	while(pos != string::npos){
		cont++;
		pos=sm.find(cadenaabuscar,pos+cadenaabuscar.length());
	}
	cout<<"Cantidad de veces que se encontro \"" << cadenaabuscar <<"\" fue de "<<cont<<" veces\n";
		
	return 0;
}

