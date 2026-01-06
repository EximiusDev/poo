#include <iostream>
#include <vector>
#include <string>
using namespace std;

///Preset_Platform
class Preset{
private:
	//vector<vector<string>>MatrizBloq;
	vector<vector<int>>MatrizBloq;
	//vector<vector<char>>MatrizBloq;
	vector<string>Preset_Plat;
	int num_plat;
public:
	Preset();
	Preset(int num_plat);
	//int VerTipoBloq(int x, int y);
	string VerTipoBloq(int x, int y);
	
	int VerTamanio_x(){return Preset_Plat[0].size();}
	int VerTamanio_y(){return Preset_Plat.size();}
};


int main() {
	Preset Platf1;
	Preset Platf2(1);
	
	cout<<Platf1.VerTipoBloq(0,1)<<endl;
	cout<<endl;
	/*
	for(int i=0;i<Platf1.VerTamanio_x();i++) { 
		cout<<Platf1.VerTipoBloq(i)<<endl;
	}*/
	
	for(int i=0;i<Platf1.VerTamanio_y();i++) { 
		for(int j=0;j<Platf1.VerTamanio_x();j++) { 
			cout<<Platf1.VerTipoBloq(j,i)<<"   ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<Platf1.VerTipoBloq(0,1)<<endl;
	cout<<Platf2.VerTipoBloq(0,1)<<endl;
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<Platf2.VerTamanio_y();i++) { 
		for(int j=0;j<Platf2.VerTamanio_x();j++) { 
			cout<<Platf2.VerTipoBloq(j,i)<<"   ";
		}
		cout<<endl;
	}
	
	return 0;
}

Preset::Preset(){
	MatrizBloq.resize(10);
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		MatrizBloq[i].resize(5);
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			MatrizBloq[i][j] = rand()%100;
			//MatrizBloq[i][j] = "A";
		}
	}
	Preset_Plat.resize(10);
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		string aux = "";
		for(unsigned int j=0;j<10;j++) { 
			aux = aux + "" + std::to_string(rand()%10) ; 
			//aux = std::to_string(j) + aux;
			//aux = aux + std::to_string(j) ;
			//aux = aux + std::to_string(rand()%10);
		}
		Preset_Plat[i] = aux ; 
	}
}
Preset::Preset(int num_plat):num_plat(num_plat){
	
	Preset_Plat.resize(7); /// 6
	
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
		
		break;
		
	default:
		Preset_Plat.push_back("..........");
		///int y;// code block
		
		//break;
	}
}
//int VerTipoBloq(int x, int y){
string Preset::VerTipoBloq(int x, int y){
	string aux(Preset_Plat[y],x,1); /// tomo Preset_Plat[y], que es un string desde la posicion "x" "1" caracter
	return aux;
}
