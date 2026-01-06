#include <iostream>

#include <vector>


#include <string>
using namespace std;
class tipobloque{	///Teoria:Con esto inutilizo completamente la creacion de diferentes clases
private:
int dureza;
int puntos;
string NomBloq;
public:
	void modificardatos(int a, int b,string c){
		dureza=a;
		puntos=b;
		NomBloq=c;								
	}
	int verpuntos1(){
		return puntos;
	}
	int verdureza1(){
		return dureza;
	}
	string NomBlo(){
			return NomBloq;
	}
	
};



int main(int argc, char *argv[]) {
	

	
	
	
	vector<vector<int>>I(500); ///Creo la matriz de aleatoriedad
	vector<vector<tipobloque>>J(500); ///Creo la matriz de bloques
	
	for(int i=0;i<500;i++) { /// Le doy el tamanio
		I[i].resize(500);
	}
	for(int i=0;i<500;i++) { /// Le doy el tamanio
		J[i].resize(500);
	}
	
	for(int i=0;i<500;i++) { 
		for(int j=0;j<500;j++) { 
			I[i][j]= rand() % 10000;	} //////////////////////////PARA MAS REALIZMO PONDRE HASTA 100 Y CON LA PROBABILIDAD DARE NUMEROS ESPECIFICOS A LOS BLOQUES ESO SUMADO A UNA ANIDACION DE IF QUE REVISARAN QUE NO HALLA TIERRA DEBAJO DE LOS 6 BLOQUES APROXIMADAMENTE NI PIEDRA NI HIERRO NI ORO EN LAS PRIMERAS FILAS
	}
	for(int i=0;i<1;i++) { 
		for(int j=0;j<500;j++){
			J[i][j].modificardatos(1,5,"TierraConPasto");
		}}
	for(int i=1;i<2;i++) { 
		for(int j=0;j<500;j++){
			J[i][j].modificardatos(1,5,"Tierra");
		}}
	
	for(int i=2;i<4;i++) { 
		for(int j=0;j<500;j++){
			J[i][j].modificardatos(2,10,"BloquePiedraDureza1");
		}}
	
	for(int i=4;i<250;i++) { 
		for(int j=0;j<500;j++){
			if(I[i][j]<=4500){
				J[i][j].modificardatos(2,10,"BloquePiedraDureza1");
			}//Utilizo Probabilidad
			else{
				if(I[i][j]>4500&&I[i][j]<=5000){
				J[i][j].modificardatos(3,100,"Fosil");
				}
				else{if(I[i][j]>5000&&I[i][j]<=6000){
					J[i][j].modificardatos(6,30,"MineralOro");}
					else{if(I[i][j]>6000&&I[i][j]<=7500){
						J[i][j].modificardatos(5,25,"MineralHierro");}
					else{J[i][j].modificardatos(7,50,"MineralDiam");}
					}}
				}
				}
			}
	for(int i=250;i<400;i++) { 
		for(int j=0;j<500;j++){
			if(I[i][j]<=4500){
				J[i][j].modificardatos(3,15,"BloquePiedraDureza2");
			}//Utilizo Probabilidad
			else{
				if(I[i][j]>4500&&I[i][j]<=5000){
					J[i][j].modificardatos(3,100,"Fosil");
				}
				else{if(I[i][j]>5000&&I[i][j]<=6000){
					J[i][j].modificardatos(6,30,"MineralOro");}
				else{if(I[i][j]>6000&&I[i][j]<=7500){
					J[i][j].modificardatos(5,25,"MineralHierro");}
				else{J[i][j].modificardatos(7,50,"MineralDiam");}
				}}
			}
		}
	}
	for(int i=400;i<500;i++) { 
		for(int j=0;j<500;j++){
			if(I[i][j]<=4500){
				J[i][j].modificardatos(4,20,"BloquePiedraDureza3");
			}//Utilizo Probabilidad
			else{
				if(I[i][j]>4500&&I[i][j]<=5000){
					J[i][j].modificardatos(3,100,"Fosil");
				}
				else{if(I[i][j]>5000&&I[i][j]<=6000){
					J[i][j].modificardatos(6,30,"MineralOro");}
				else{if(I[i][j]>6000&&I[i][j]<=7500){
					J[i][j].modificardatos(5,25,"MineralHierro");}
				else{J[i][j].modificardatos(7,50,"MineralDiam");}
				}}
			}
		}
	}
			
		
			
		
	
	
	for(int i=0;i<500;i++) { 
		cout<<endl;
		for(int j=0;j<50;j++) { 
			cout<<J[i][j].verdureza1();
		}
	}
	
	
	
	return 0;
}

