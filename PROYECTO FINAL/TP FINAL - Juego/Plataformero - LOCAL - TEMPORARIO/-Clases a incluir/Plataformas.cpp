#include <iostream>
#include <vector>
using namespace std;

class Preset{
private:
	vector<vector<int>>MatrizBloq;
	int num_plat;
public:
	Preset();
	Preset(int num_plat);
	int VerTipoBloq(int x, int y);
	int VerTamanio_x(){return MatrizBloq.size();}
	int VerTamanio_y(){return MatrizBloq[0].size();}
};


int main() {
	Preset Platf1;
	Preset Platf2(1);
	
	cout<<Platf1.VerTipoBloq(1,1)<<endl;
	cout<<endl;
	
	for(int i=0;i<Platf1.VerTamanio_x();i++) { 
		for(int j=0;j<Platf1.VerTamanio_y();j++) { 
			cout<<Platf1.VerTipoBloq(i,j)<<"   ";
		}
		cout<<endl;
	}
	//cout<<Platf1.ver()<<endl;
	
	return 0;
}

Preset::Preset(){
	MatrizBloq.resize(10);
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		MatrizBloq[i].resize(5);
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			MatrizBloq[i][j] = rand()%100;
		}
	}
}
Preset::Preset(int num_plat):num_plat(num_plat){
	/*
	switch(num_plat){
		case 0:
			//Plat1[x].Init(Name4,x,1);
		
		break;
		
		case 1:
			int z;// code block
		
			break;
		
		
		default:
			int y;// code block
		
			//break;
	}*/
}
int Preset::VerTipoBloq(int x, int y){
	return MatrizBloq[x][y];
}/*
int Preset::ver(){
	return 1;
}*/

