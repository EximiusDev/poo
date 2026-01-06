//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 7
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	//Declaro el objeto archi
	fstream archi("/POO/crecer.dat" , ios::binary |ios::in|ios::out|ios::trunc);
	for (int c=5; c<=35; c+=5)
		//Escribo el archivo con 5,10,15,20,25,30,35
		archi.write(reinterpret_cast<char*>( &c), sizeof(c));
	//El archivo ya fue creado
	int i, pos, dato=0;
	archi.seekg(0,ios::end);//Me posciono al final del archivo
	int largo= (archi.tellg()/sizeof(i));//Calculo cantidad de elementos
	archi.seekg(0,ios::beg);//llevo el puntero al inicio para comenzar la lectura
	cout<<"Lee archivo original: //5,10,15,20,25,30,35"<<endl;
	cout<<endl<<"Largo en cantidad de numeros: "<<largo<<endl;
	for (int c=0; c<largo; c++){
		archi.read(reinterpret_cast<char*>( &i), sizeof(i));
		cout<<(i/5)-1<<"  "<<i<<endl;}
	//***********************************************************************************
	srand( time(NULL) );//Para generar numeros distintos
	i=rand()% 50; // genera entero menor que 50;
	cout<<"Numero generado: "<<i<<endl;
	pos = -1;//Posicion de lectura, la primera es 0.-
	archi.seekg(0,ios::beg);//llevo el puntero al inicio para comenzar la lectura
	//Mientras no se pase del tamaño y el dato leido sea menor al numero a insertar
	while((pos<largo-1)&&(dato < i)){
		archi.read(reinterpret_cast<char*>(&dato), sizeof(dato));
		pos++;//cuento que lei otro.-
		//cout<<"Tellg: "<<archi.tellg()<<endl;
	}
	cout<<i<<" -- Encontro la posicion siguiente: "<<pos<<endl;
	if (i <= dato){//Si NO esta al final del archivo escribe en el lugar que leyo el último 
		archi.seekp((pos*sizeof(i)),ios::beg);
		archi.write(reinterpret_cast<char*>( &i), sizeof(i));//escribe en el archivo el entero ordenado
		pos++;//cuenta una posicion mas.
		while(pos<largo){//Si no llego al final del archivo
			archi.seekg((pos*sizeof(i)),ios::beg);//Posiciono para leer el siguiente
			archi.read(reinterpret_cast<char*>(&i), sizeof(i));//Leo
			archi.seekp((pos*sizeof(i)),ios::beg);//Retrocedo y escribo el anterior
			archi.write(reinterpret_cast<char*>( &dato), sizeof(dato));//Escribe el siguiente ordenado
			dato= i;//Refresco dato con el que acabo de leer
			pos++;//cuento una posicion mas.-
		}//del while*/
		
	}//del if.-
	else
		dato=i;//En el caso que sea mas grande que el ultimo
	//ahora me falta escribir el ultimo 
	archi.seekg(0,ios::end);//cuando ya lei todos 
	archi.seekp(0,ios::end);//voy al final y escribo el ultimo
	archi.write(reinterpret_cast<char*>( &dato), sizeof(dato));//escribe en el archivo el ultimo
	//***********************************************************************************
	int c;//Lee y muestra el archivo con el dato nuevo insertado
	archi.seekg(0,ios::end);
	largo= (archi.tellg()/sizeof(i));//Vuelve a calcular el largo del archivo
	cout<<endl<<"Largo en cantidad de numeros: "<<largo<<endl;
	archi.seekg(0,ios::beg);//Muevo el puntero de lectura al principio del archivo
	for(c=0; c<largo; c++){//Leo y muestro los numeros del archivo
		archi.read(reinterpret_cast<char*>(&i), sizeof(i));
		cout<<c<<"  "<<i<<endl;
	}
	archi.close();
}//Programación Orientada a Objetos - Prof. Gerardo Sas
