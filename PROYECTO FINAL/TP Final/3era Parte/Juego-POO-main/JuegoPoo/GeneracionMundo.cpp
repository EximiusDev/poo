#include "GeneracionMundo.h"
#include "TipoBloque.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

GeneracionMundo::GeneracionMundo(/*int altura_E, int ancho_E, int nivelcero_E*/) {
	/*altura = altura_E; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	ancho = ancho_E; /// minimo 120 (por la resolucion de pantalla)
	
	nivelcero = nivelcero_E; /// nivel donde empiza el suelo
	altura_total = altura_E + nivelcero_E;
	
	for(int i=0;i<altura_total;i++) { /// Le doy el tamanio
		I[i].resize(ancho);
	}
	for(int i=0;i<altura_total;i++) { /// Le doy el tamanio
		J[i].resize(ancho);
	}*/
}

void GeneracionMundo::Modificardatos (int altura_E, int ancho_E, int nivelcero_E){
	altura = altura_E; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	ancho = ancho_E; /// minimo 120 (por la resolucion de pantalla)
	nivelcero = nivelcero_E; /// nivel donde empiza el suelo
	altura_total = altura_E + nivelcero_E;
	
	niveles.resize(altura_total);
	I.resize(altura_total);
	J.resize(altura_total);
	for(int i=0;i<altura_total;i++) { /// Le doy el tamanio
		I[i].resize(ancho);
	}
	for(int i=0;i<altura_total;i++) { /// Le doy el tamanio
		J[i].resize(ancho);
	}
	
}

vector<int> GeneracionMundo::Ver_niveles(){
	
	for(int i=0;i<altura_total;i++) { 
		int n1 = 3, n2 = 10, n3 = 25;
		int n4 = (altura/5), n5 = (altura/30), n6 = (altura/2);
		int n7 = ((altura/2)+ n4), n8 = ((altura/2)+n5*10), n9 = altura;
		
		n5 = n5*10;
		
		if(i > nivelcero && i <= nivelcero +  n1)				niveles[i] = 1;//		(rand() % 1010);
		if(i > nivelcero + n1 && i <= nivelcero +  n2)			niveles[i] = 2;//		(rand() % 1000)+200;
		if(i > nivelcero + n2 && i <= nivelcero +  n3)			niveles[i] = 3;//		(rand() % 1000)+500;
		if(i > nivelcero + n3 && i <= nivelcero +  n4)			niveles[i] = 4;//		(rand() % 2000)+500;
		if(i > nivelcero + n4 && i <= nivelcero +  n5)			niveles[i] = 5;//		(rand() % 10000)+200;
		if(i > nivelcero + n5 && i <= nivelcero +  n6)			niveles[i] = 6;//		(rand() % 10000)+200;
		if(i > nivelcero + n6 && i <= nivelcero +  n7)			niveles[i] = 7;//		(rand() % 10000)+200;
		if(i > nivelcero + n7 && i <= nivelcero +  n8)			niveles[i] = 8;//		(rand() % 10000)+200;
		if(i > nivelcero + n8 && i <= nivelcero +  n9)			niveles[i] = 9;//		(rand() % 10000)+200;
		
		if(i == nivelcero)										niveles[i] = 10;
	
		
	}
	return niveles;
}

vector<vector<int>> GeneracionMundo::Ver_Matriz_azar(){
	
	for(int i=0;i<altura_total;i++) { 
		for(int j=0;j<ancho;j++) { 
			/// I[i][j]= rand() % 10000;	 
			I[i][j] = 0;	 
			if (niveles[i] == 0) 		I[i][j] = 0;
			if (niveles[i] == 1) 		I[i][j] = (rand() % 900)+ 250;
			if (niveles[i] == 2) 		I[i][j] = (rand() % 1000)+ 250;
			if (niveles[i] == 3) 		I[i][j] = (rand() % 1500)+ 250;
			if (niveles[i] == 4) 		I[i][j] = (rand() % 2500)+ 250;
			if (niveles[i] == 5) 		I[i][j] = (rand() % 5000)+ 250;
			if (niveles[i] == 6) 		I[i][j] = (rand() % 6000)+ 250;
			if (niveles[i] == 7) 		I[i][j] = (rand() % 5000)+ 250;
			if (niveles[i] == 8) 		I[i][j] = (rand() % 8000)+ 250;
			if (niveles[i] == 9) 		I[i][j] = (rand() % 10000); //(rand() % 1000)+ 250;
			
			if (niveles[i] == 10) 		I[i][j] = 10000;
			
			////////////////PARA MAS REALIZMO PONDRE HASTA 100 Y CON LA PROBABILIDAD DARE NUMEROS ESPECIFICOS A LOS BLOQUES,
		} ////ESO SUMADO A UNA ANIDACION DE IF QUE REVISARAN QUE NO HALLA TIERRA DEBAJO DE LOS 6 BLOQUES APROXIMADAMENTE NI PIEDRA NI HIERRO NI ORO EN LAS PRIMERAS FILAS
		
	}
	return I;
}

vector<vector<TipoBloque>> GeneracionMundo::Ver_Matriz_Bloques(){
	
	for(int i=0;i<altura_total;i++) { 
		for(int j=0;j<ancho;j++){
			
			if(I[i][j]< 500)						J[i][j].Modificardatos(0,0,"Tierra_prueba1.png"); /// bloque vacio
			else{
				if((I[i][j] == 10000))								J[i][j].Modificardatos(0,0,"Tierra_prueba.png");// J[i][j].Modificardatos(1,5,"TierraConPasto.png");
				else if((I[i][j]>500) && (I[i][j]<=1000))			J[i][j].Modificardatos(1,5,"Tierra.png");
				else if((I[i][j]>1000) && (I[i][j]<=2000))			J[i][j].Modificardatos(2,10,"BloquePiedraDureza1.png");
				else if((I[i][j]>5000) && (I[i][j]<=6000))			J[i][j].Modificardatos(3,15,"BloquePiedraDureza2.png");
				else if((I[i][j]>7000) && (I[i][j]<=8000))			J[i][j].Modificardatos(4,20,"BloquePiedraDureza3.png"); //Utilizo Probabilidad
				else if((I[i][j]>6000) && (I[i][j]<=6800))			J[i][j].Modificardatos(3,100,"Fosil.png");
				else if((I[i][j]>6800) && (I[i][j]<=7000))			J[i][j].Modificardatos(3,500,"Reliquia.png");
				else if((I[i][j]>2000) && (I[i][j]<=5000)) 			J[i][j].Modificardatos(5,25,"MineralHierro.png");
				else if((I[i][j]>8000) && (I[i][j]<=9000))			J[i][j].Modificardatos(6,30,"MineralOro.png");
				else if((I[i][j]>9000) && (I[i][j]<=9700))			J[i][j].Modificardatos(7,40,"MineralPlata.png");
				else if((I[i][j]>9800) && (I[i][j]<10000))			J[i][j].Modificardatos(9,70,"MineralDiam.png");
				else{
					if((I[i][j])%2==0)								J[i][j].Modificardatos(0,0,"Tierra.png"); /// bloque vacio
					else 											J[i][j].Modificardatos(1,5,"Tierra.png");
					
					// J[i][j].Modificardatos(0,0,"Tierra_prueba.png"); /// bloque vacio
					// J[i][j].Modificardatos(0,0,"Tierra_prueba1.png"); /// bloque vacio
				}
			}
		}
	}
	
	return J;
}
