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
			I[i][j]= rand() % 9;	} //////////////////////////PARA MAS REALIZMO PONDRE HASTA 100 Y CON LA PROBABILIDAD DARE NUMEROS ESPECIFICOS A LOS BLOQUES ESO SUMADO A UNA ANIDACION DE IF QUE REVISARAN QUE NO HALLA TIERRA DEBAJO DE LOS 6 BLOQUES APROXIMADAMENTE NI PIEDRA NI HIERRO NI ORO EN LAS PRIMERAS FILAS
	}
	
	for(int i=0;i<500;i++) { 
		for(int j=0;j<500;j++){
			
			
			switch(I[i][j]){
			case 0:
				J[i][j].modificardatos(1,5,"Tierra");
				break;
			case 1:
				J[i][j].modificardatos(3,100,"Fosil");
				break;
			case 2:
				J[i][j].modificardatos(7,50,"MineralDiam");
				break;
			case 4:
				J[i][j].modificardatos(5,25,"MineralHierro");
				break;
			case 5:
				J[i][j].modificardatos(6,30,"MineralOro");
				
				break;
			case 6:
				J[i][j].modificardatos(2,10,"BloquePiedraDureza1");
				break;
			case 7:
				J[i][j].modificardatos(3,15,"BloquePiedraDureza2");
				break;
			case 8:
				J[i][j].modificardatos(4,20,"BloquePiedraDureza3");
				break;
				
			}}
		
		
	}
	
	cout<<J[10][10].verdureza1()<<endl;
	cout<<J[10][10].verpuntos1()<<endl;
	cout<<J[10][10].NomBlo();
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	/// x representa horizontalmente la pantalla
	/// y representa verticalemente la pantalla
	int x1 = 250 - 16; /// la mitad del mundo menosla mitad de la pantalla
	int y1 = 0; /// posicion inicial del jugador
	int x2 = 250 + 14;
	int y2 = 20;
	
	for(int i = x1;i < x2;i++) { 
		for(int j = y1;j < y2;j++){
			cout<<J[i][j].verdureza1()<<"  ";
			//cout<<J[i][j].verpuntos1();
			//cout<<J[i][j].NomBlo();
		}
		cout<<endl;
	}
	
	
	
	
	
	return 0;
}
