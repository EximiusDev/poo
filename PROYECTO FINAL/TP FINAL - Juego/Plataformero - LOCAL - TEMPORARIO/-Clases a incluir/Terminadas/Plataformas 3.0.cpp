#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
class Actual_Platform{
	vector<Preset> Seeing_Platform;
	PremadeMap Map_Sequence;
public:
	Actual_Platform()
};*/

///Preset_Platform
class Preset{
private:
	//vector<vector<string>>MatrizBloq;
	vector<vector<int>>MatrizBloq;
	//vector<vector<char>>MatrizBloq;
	vector<string>Preset_Plat;
	int num_plat;
	int tamanio = 8;
	int tamanio_x = 10;
	int tamanio_y = 9;
	void str_to_int();
public:
	Preset();
	Preset(int num_plat);
	//int VerTipoBloq(int x, int y);
	string VerEsquemaBloq(int x, int y);
	int VerTipoBloq(int x, int y);
	
	int VerTamanio_x(){return Preset_Plat[0].size();}
	int VerTamanio_y(){return Preset_Plat.size();}
};


int main() {
	//Preset Platf1;
	Preset Platf1(2);
	Preset Platf2(1);
	
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
Preset::Preset(){
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
	Preset_Plat.resize(tamanio_y);
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		string aux = "";
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			///aux = aux + "" + std::to_string(rand()%10) ; 
			aux = aux  + std::to_string(MatrizBloq[i][j]) ; 
			//aux = std::to_string(j) + aux;
			//aux = aux + std::to_string(j) ;
			//aux = aux + std::to_string(rand()%10);
		}
		Preset_Plat[i] = aux ; 
		cout<<i<<". "<<Preset_Plat[i]<<endl;
	}
	cout<<endl;cout<<endl;
}*/
Preset::Preset(int num_plat):num_plat(num_plat){
	
	Preset_Plat.resize(tamanio_y); /// de 0 a 7
	
	switch(num_plat){
	case 0:
		//				 "0123456789"
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..........";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "..........";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		Preset_Plat[8] = "..........";
		
		break;
		
	case 1:
		
		//				 "0123456789"
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..........";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "..........";
		Preset_Plat[6] = "OOOOOOOOOO";
		Preset_Plat[7] = "..........";
		Preset_Plat[8] = "..........";
		
		break;
		
	case 2:
		
		//				 "0123456789"
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..........";
		Preset_Plat[3] = "....OOO...";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "..........";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		Preset_Plat[8] = "..........";
		
		break;
		
	default:
		Preset_Plat.push_back("..........");
		///int y;// code block
		
		//break;
	}
	this->str_to_int();
}

string Preset::VerEsquemaBloq(int x, int y){
	string aux(Preset_Plat[y],x,1); /// tomo Preset_Plat[y], que es un string desde la posicion "x" "1" caracter
	return aux;
}
int Preset::VerTipoBloq(int x, int y){
	return MatrizBloq[y][x];
}

void Preset::str_to_int(){
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
