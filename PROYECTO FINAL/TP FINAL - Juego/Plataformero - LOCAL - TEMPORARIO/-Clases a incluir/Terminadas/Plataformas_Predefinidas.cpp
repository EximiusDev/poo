#include <iostream>
#include <vector>
using namespace std;

class Framework{
	vector<string>Preset_Plat;
	int tamanio_x = 10;
	int tamanio_y = 8;
public:
	Framework(int num_plat);
};

int main() {
	int num_plat = 0;
	Framework Plataforma(num_plat);
	
	return 0;
}

Framework::Framework(int num_plat){
	
	Preset_Plat.resize(tamanio_y);
	
	switch(num_plat){
	case 0:
		//				 "0123456789"
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..........";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "OOOOOOOOOO";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		
		break;
		
	case 1:
		//				 "0123456789"
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..OOOOOO..";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "OOOOOOOOOO";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		break;
	case 2:
		//				 "0123456789"
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..OOOXOO..";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "OOO....OOO";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		break;
		
	case 3:
		//				 "0123456789"
		Preset_Plat[0] = "MMMMMMMM..";
		Preset_Plat[1] = "..OOOOOO..";
		Preset_Plat[2] = ".....OOO..";
		Preset_Plat[3] = "..O.......";
		Preset_Plat[4] = "..OOOOOO..";
		Preset_Plat[5] = "..........";
		Preset_Plat[6] = "OO......OO";
		Preset_Plat[7] = "..........";
		break;
		
	case 4:
		//				 "0123456789"
		Preset_Plat[0] = "..OOOOOO..";
		Preset_Plat[1] = ".....OOO..";
		Preset_Plat[2] = "..O.......";
		Preset_Plat[3] = "..OOOOOO..";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "OO......OO";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		break;
		
	default:
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..........";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "..........";
		Preset_Plat[6] = "..........";
		Preset_Plat[7] = "..........";
		
		//break;
	}
	
	
	for(int i=0;i<tamanio_y;i++) { 
		cout<<i<<"  ";
		for(int j=0;j<tamanio_x;j++) { 
			cout<<Preset_Plat[i][j]<<" ";
		}
		cout<<endl;
	}
}
