#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
class Actual_Platform{
	vector<Preset_Platform> Seeing_Platform;
	PremadeMap Map_Sequence;
public:
	Actual_Platform()
};*/

///Preset_Platform
class Preset_Platform{
private:
	//vector<vector<string>>MatrizBloq;
	vector<vector<int>>MatrizBloq;
	//vector<vector<char>>MatrizBloq;
	vector<string>Preset_Platform_Plat;
	int num_plat = 0;
	int tamanio = 8;
	int tamanio_x = 8;
	int tamanio_y = 9;
	void str_to_int();
	int tam_tot_x  = 24;
	vector<int> currents_plat;
public:
	Preset_Platform();
	Preset_Platform(int num_plat);
	//int VerTipoBloq(int x, int y);
	string VerEsquemaBloq(int x, int y);
	int VerTipoBloq(int x, int y);
	
	void Set_Predet_Plat(int num_plat);
	
	int VerTamanio_x(){return Preset_Platform_Plat[0].size();}
	int VerTamanio_y(){return Preset_Platform_Plat.size();}
};


int main() {
	//Preset_Platform Platf1;
	Preset_Platform Platf1(2);
	Preset_Platform Platf2(1);
	
	cout<<Platf1.VerEsquemaBloq(0,1)<<endl;
	cout<<endl;
	/*
	for(int i=0;i<Platf1.VerTamanio_x();i++) {
		cout<<Platf1.VerTipoBloq(i)<<endl; 
	}*/
	
	for(int i=0;i<Platf1.VerTamanio_y();i++) { 
		cout<<i<<"_ ";
		for(int j=0;j<Platf1.VerTamanio_x();j++) { 
			cout<<Platf1.VerEsquemaBloq(j,i)<<"   ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<Platf1.VerEsquemaBloq(0,1)<<endl;
	cout<<Platf2.VerEsquemaBloq(0,1)<<endl;
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<Platf2.VerTamanio_y();i++) { 
		cout<<i<<"_ ";
		for(int j=0;j<Platf2.VerTamanio_x();j++) { 
			cout<<Platf2.VerEsquemaBloq(j,i)<<"   ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<Platf2.VerTamanio_y();i++) { 
		cout<<i<<"_ ";
		for(int j=0;j<Platf2.VerTamanio_x();j++) { 
			cout<<Platf2.VerTipoBloq(j,i)<<"   ";
		}
		cout<<endl;
	}
	
	return 0;
}
/*
Preset_Platform::Preset_Platform(){
	MatrizBloq.resize(tamanio_y);
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		MatrizBloq[i].resize(tamanio_x);
		cout<<i<<". ";
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			MatrizBloq[i][j] = rand()%10;
			//MatrizBloq[i][j] = "A";
			cout<<MatrizBloq[i][j]<<"   ";
		}
		cout<<endl;
	}
	Preset_Platform_Plat.resize(tamanio_y);
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		string aux = "";
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			///aux = aux + "" + std::to_string(rand()%10) ; 
			aux = aux  + std::to_string(MatrizBloq[i][j]) ; 
			//aux = std::to_string(j) + aux;
			//aux = aux + std::to_string(j) ;
			//aux = aux + std::to_string(rand()%10);
		}
		Preset_Platform_Plat[i] = aux ; 
		cout<<i<<". "<<Preset_Platform_Plat[i]<<endl;
	}
	cout<<endl;cout<<endl;
}*/
Preset_Platform::Preset_Platform(int num_plat):num_plat(num_plat){
	currents_plat.resize(3);
	//currents_plat[0] = 0;
	//currents_plat[1] = 1;
	//currents_plat[2] = 2;
	
	
	Preset_Platform_Plat.resize(tamanio_y); /// de 0 a 7
	this->Set_Predet_Plat(num_plat);
}
void Preset_Platform::Set_Predet_Plat(int num_plat){
	this->num_plat = num_plat;
	switch(num_plat){
	case 0:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "OOOOOOOO";
		break;
		
	case 1:
		
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = ".....OO.";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = ".OO.....";
		Preset_Platform_Plat[8] = "........";
		break;
	case 2:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "....O...";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "O......O";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
	case 3:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "...OOO..";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
	case 4:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "..OOO...";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
		
	case 5:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "OOOOOOOO";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
		
	case 6:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "....OOO.";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
		
	case 7:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = ".OOOO...";
		Preset_Platform_Plat[8] = "........";
		break;
	case 8:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = ".OOOO...";
		Preset_Platform_Plat[8] = "........";
		break;
	case 9:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "..OOOO..";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
		
	default:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		//break;
	}
	this->str_to_int();
}

string Preset_Platform::VerEsquemaBloq(int x, int y){
	string aux(Preset_Platform_Plat[y],x,1); /// tomo Preset_Platform_Plat[y], que es un string desde la posicion "x" "1" caracter
	return aux;
}
int Preset_Platform::VerTipoBloq(int x, int y){
	return MatrizBloq[y][x];
}

void Preset_Platform::str_to_int(){
	MatrizBloq.resize(tamanio_y);
	
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		MatrizBloq[i].resize(tamanio_x);
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			if(this->VerEsquemaBloq(j,i)==".")MatrizBloq[i][j] = 0;
			else if(this->VerEsquemaBloq(j,i)=="O")MatrizBloq[i][j] = 1;
			//else(this->VerTipoBloq(j,i)==".")MatrizBloq[i][j] = 0;
		}
	}
}

//Preset_Platform::Update(){
	/// ACTUALMENTE LO HACE BLOQUE
	/* 
	if(positionG.x<=-1*resolutionG.x/2){
		spr.setPosition(resolutionG.x,positionG.y);
		positionG.x=resolutionG.x;
	}
	*/
	/*for(int i=0;i<currents_plat.size();i++) { 
		currents_plat[i] = currents_plat[i+1];
		currents_plat[currents_plat.size()-1] = rand()%10;
	}*/
	//currents_plat[0] = 
//}
/*
switch(num_plat){
case 0:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "OOOOOOOO";
	break;
	
case 1:
	
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "OOOOOOOO";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;
case 2:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "...OOO..";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "OOOOOOOO";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;
case 3:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "...OOO..";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;
case 4:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "..OOO...";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;	
case 5:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "OOOOOOOO";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;
	
case 6:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "....OOO.";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;	
case 7:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = ".OOO....";
	Preset_Platform_Plat[8] = "........";
	break;
case 8:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = ".OOO....";
	Preset_Platform_Plat[8] = "........";
	break;
case 9:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "..OOO...";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	break;
	
default:
	//						  "0123456789"
	Preset_Platform_Plat[0] = "........";
	Preset_Platform_Plat[1] = "........";
	Preset_Platform_Plat[2] = "........";
	Preset_Platform_Plat[3] = "........";
	Preset_Platform_Plat[4] = "........";
	Preset_Platform_Plat[5] = "........";
	Preset_Platform_Plat[6] = "........";
	Preset_Platform_Plat[7] = "........";
	Preset_Platform_Plat[8] = "........";
	//break;
}
*/

