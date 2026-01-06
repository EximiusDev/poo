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
	void Modificardatos(int a, int b,string c){
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
	
	///valores de generacion del mundo
	
	int altura = 200; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	int ancho = 200; /// minimo 120 (por la resolucion de pantalla)
	
	int nivelcero = 50; /// nivel donde empiza el suelo
	int n1 = 3, n2 = 10, n3 = 25;
	int n4 = (altura/5), n5 = (altura/30), n6 = (altura/2);
	int n7 = ((altura/2)+ n4), n8 = ((altura/2)+n5*10), n9 = altura;
	
	n5 = n5*10;
	int altura_total = altura + nivelcero;
	
	vector<int>niveles(altura_total); /// creo un vector para los niveles de altura 
	vector<vector<int>>I(altura_total); ///Creo la matriz de aleatoriedad ///Creo la matriz de tipo int 
	vector<vector<tipobloque>>J(altura_total); ///Creo la matriz de bloques
	
	for(int i=0;i<altura_total;i++) { /// Le doy el tamanio
		I[i].resize(ancho);
	}
	for(int i=0;i<altura_total;i++) { /// Le doy el tamanio
		J[i].resize(ancho);
	}
	/////////////////////////////////////////////////////
	
	for(int i=0;i<altura_total;i++) { 
			
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
	
	/*
	for(int i=0;i<1;i++) { 
		for(int j=0;j<ancho;j++){
			J[i][j].Modificardatos(1,5,"TierraConPasto");
		}}
	for(int i=1;i<2;i++) { 
		for(int j=0;j<ancho;j++){
			J[i][j].Modificardatos(1,5,"Tierra");
		}}
	
	for(int i=2;i<4;i++) { 
		for(int j=0;j<ancho;j++){
			J[i][j].Modificardatos(2,10,"BloquePiedraDureza1");
		}}
	
	for(int i=4;i<(altura_total/2);i++) { 
		for(int j=0;j<ancho;j++){
			if(I[i][j]<=4500){
				J[i][j].Modificardatos(2,10,"BloquePiedraDureza1");
			}//Utilizo Probabilidad
			else{
				if(I[i][j]>4500&&I[i][j]<=5000){
				J[i][j].Modificardatos(3,100,"Fosil");
				}
				else{if(I[i][j]>5000&&I[i][j]<=6000){
					J[i][j].Modificardatos(6,30,"MineralOro");}
					else{if(I[i][j]>6000&&I[i][j]<=7500){
						J[i][j].Modificardatos(5,25,"MineralHierro");}
					else{J[i][j].Modificardatos(7,50,"MineralDiam");}
					}}
				}
				}
			}
	for(int i=(altura_total/2);i<(altura_total*(4/5));i++) { 
		for(int j=0;j<ancho;j++){
			if(I[i][j]<=4500){
				J[i][j].Modificardatos(3,15,"BloquePiedraDureza2");
			}//Utilizo Probabilidad
			else{
				if(I[i][j]>4500&&I[i][j]<=5000){
					J[i][j].Modificardatos(3,100,"Fosil");
				}
				else{if(I[i][j]>5000&&I[i][j]<=6000){
					J[i][j].Modificardatos(6,30,"MineralOro");}
				else{if(I[i][j]>6000&&I[i][j]<=7500){
					J[i][j].Modificardatos(5,25,"MineralHierro");}
				else{J[i][j].Modificardatos(7,50,"MineralDiam");}
				}}
			}
		}
	}
	for(int i=(altura_total*(4/5));i<altura_total;i++) { 
		for(int j=0;j<ancho;j++){
			if(I[i][j]<=4500){
				J[i][j].Modificardatos(4,20,"BloquePiedraDureza3");
			}//Utilizo Probabilidad
			else{
				if(I[i][j]>4500&&I[i][j]<=5000){
					J[i][j].Modificardatos(3,100,"Fosil");
				}
				else{if(I[i][j]>5000&&I[i][j]<=6000){
					J[i][j].Modificardatos(6,30,"MineralOro");}
				else{if(I[i][j]>6000&&I[i][j]<=7500){
					J[i][j].Modificardatos(5,25,"MineralHierro");}
				else{J[i][j].Modificardatos(7,50,"MineralDiam");}
				}}
			}
		}
	}
	*/
	
	// /*
	for(int i=0;i<altura_total;i++) { 
		for(int j=0;j<ancho;j++){
			if(I[i][j]< 500)							J[i][j].Modificardatos(0,0,"Nada"); /// bloque vacio
			else{
				if((I[i][j] == 10000))								J[i][j].Modificardatos(1,5,"TierraConPasto");
				else if((I[i][j]>500) && (I[i][j]<=1000))			J[i][j].Modificardatos(1,5,"Tierra");
				else if((I[i][j]>1000) && (I[i][j]<=2000))			J[i][j].Modificardatos(2,10,"BloquePiedraDureza1");
				else if((I[i][j]>5000) && (I[i][j]<=6000))			J[i][j].Modificardatos(3,15,"BloquePiedraDureza2");
				else if((I[i][j]>7000) && (I[i][j]<=8000))			J[i][j].Modificardatos(4,20,"BloquePiedraDureza3"); //Utilizo Probabilidad
				else if((I[i][j]>6000) && (I[i][j]<=6800))			J[i][j].Modificardatos(3,100,"Fosil");
				else if((I[i][j]>6800) && (I[i][j]<=7000))			J[i][j].Modificardatos(3,500,"Reliquia");
				else if((I[i][j]>2000) && (I[i][j]<=5000)) 			J[i][j].Modificardatos(5,25,"MineralHierro");
				else if((I[i][j]>8000) && (I[i][j]<=9000))			J[i][j].Modificardatos(6,30,"MineralOro");
				else if((I[i][j]>9000) && (I[i][j]<=9700))			J[i][j].Modificardatos(7,40,"MineralPlata");
				else if((I[i][j]>9800) && (I[i][j]<10000))			J[i][j].Modificardatos(9,70,"MineralDiam");
				else{
					if((I[i][j])%2==0)								J[i][j].Modificardatos(0,0,"Nada"); /// bloque vacio
					else 											J[i][j].Modificardatos(1,5,"Tierra");
				}
			}
		}
	}
	// */
	
	// /*
	for(int i=0;i<altura_total;i++) { 
		cout<<endl;
		cout<<i<<" ";
		for(int j=((ancho/2)-25);j<((ancho/2)+25);j++) { 
			cout<<J[i][j].verdureza1();
		}
	}
	// */
	
	cout<<endl;
	cout<<endl;
	cout<<altura<<endl;
	cout<<ancho<<endl;
	cout<<altura_total<<endl;
	cout<<endl;
	
	
	for(int i=0;i<altura_total;i++) { 
		cout<<endl;
		cout<<i<<"  ";
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
	cout<<rand() % 1;
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<altura_total;i++) { 
		cout<<i<<"   "<<niveles[i];
		cout<<endl;
	}
	
	
	return 0;
}

