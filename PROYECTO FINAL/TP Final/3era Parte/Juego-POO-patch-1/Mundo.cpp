#include <iostream>
#include "Bloque.cpp"
#include <vector>


using namespace std;


struct Bloques{
	Tierra T;
	Fosil F;
	BloquePiedraDureza1 B1;
	BloquePiedraDureza2 B2;
	BloquePiedraDureza3 B3;
	MineralDiam MD;
	MineralHierro MH;
	MineralOro MO;
	
};

int main(int argc, char *argv[]) {
	

	
	
	
	vector<vector<int>>I(500); ///Creo la matriz de aleatoriedad
	vector<vector<Bloque>>J(500); ///Creo la matriz de bloques
	
	for(int i=0;i<500;i++) { /// Le doy el tamanio
		I[i].resize(500);
	}
	for(int i=0;i<500;i++) { /// Le doy el tamanio
		J[i].resize(500);
	}
	
	for(int i=0;i<500;i++) { 
		for(int j=0;j<500;j++) { 
			I[i][j]= rand() % 8;	} //////////////////////////PARA MAS REALIZMO PONDRE HASTA 100 Y CON LA PROBABILIDAD DARE NUMEROS ESPECIFICOS A LOS BLOQUES ESO SUMADO A UNA ANIDACION DE IF QUE REVISARAN QUE NO HALLA TIERRA DEBAJO DE LOS 6 BLOQUES APROXIMADAMENTE NI PIEDRA NI HIERRO NI ORO EN LAS PRIMERAS FILAS
	}
	Bloques Z;
	for(int i=0;i<500;i++) { 
		for(int j=0;j<500;j++){
		
		
		switch(I[i][j]){
		case 0:
			J[i][j];
			break;
		case 1:
			J[i][j]= Z.F;
			break;
		case 2:
			J[i][j]= Z.B1;
			break;
		case 4:
			J[i][j]= Z.B3;
			break;
		case 5:
			J[i][j]= Z.MD;
			break;
		case 6:
			J[i][j]= Z.MO;
			break;
		case 7:
			J[i][j]= Z.MH;
			break;
			
		}}
			
		
	}
	cout<<J[10][10].verdureza();
	
	
	
	
	return 0;
}

