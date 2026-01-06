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
	

	
	int altura=500;
	int ancho=500;
	
	vector<vector<int>>I(altura); ///Creo la matriz de aleatoriedad ///Creo la matriz de tipo int 
	vector<vector<tipobloque>>J(altura); ///Creo la matriz de bloques
	
	for(int i=0;i<ancho;i++) { /// Le doy el tamanio
		I[i].resize(ancho);
	}
	for(int i=0;i<ancho;i++) { /// Le doy el tamanio
		J[i].resize(ancho);
	}
	
	for(int i=0;i<altura;i++) { 
		for(int j=0;j<ancho;j++) { 
			I[i][j]= rand() % 10000;	} ////////////////PARA MAS REALIZMO PONDRE HASTA 100 Y CON LA PROBABILIDAD DARE NUMEROS ESPECIFICOS A LOS BLOQUES
		////ESO SUMADO A UNA ANIDACION DE IF QUE REVISARAN QUE NO HALLA TIERRA DEBAJO DE LOS 6 BLOQUES APROXIMADAMENTE NI PIEDRA NI HIERRO NI ORO EN LAS PRIMERAS FILAS
	}
	for(int i=0;i<1;i++) { 
		for(int j=0;j<ancho;j++){
			J[i][j].modificardatos(1,5,"TierraConPasto");
		}}
	for(int i=1;i<2;i++) { 
		for(int j=0;j<ancho;j++){
			J[i][j].modificardatos(1,5,"Tierra");
		}}
	
	for(int i=2;i<4;i++) { 
		for(int j=0;j<ancho;j++){
			J[i][j].modificardatos(2,10,"BloquePiedraDureza1");
		}}
	
	for(int i=4;i<(altura/2);i++) { 
		for(int j=0;j<ancho;j++){
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
	for(int i=(altura/2);i<(altura*(4/5));i++) { 
		for(int j=0;j<ancho;j++){
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
	for(int i=(altura*(4/5));i<altura;i++) { 
		for(int j=0;j<ancho;j++){
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
	
	
	
	for(int i=0;i<altura;i++) { 
		cout<<endl;
		for(int j=((ancho/2)-25);j<((ancho/2)+25);j++) { 
			cout<<J[i][j].verdureza1();
		}
	}
	cout<<endl;
	cout<<endl;
	cout<<altura<<endl;
	cout<<ancho<<endl;
	cout<<endl;
	
	
	for(int i=0;i<altura;i++) { 
		cout<<endl;
		for(int j=((ancho/2)-10);j<((ancho/2)+10);j++) { 
			cout<<I[i][j]<<" ";
		}
	}
	
	/*
	cout<<endl;
	cout<<I[1][1]<<" ";
	cout<<I[10][10]<<" ";
	cout<<endl;
	*/
	cout<<endl;
	return 0;
}

