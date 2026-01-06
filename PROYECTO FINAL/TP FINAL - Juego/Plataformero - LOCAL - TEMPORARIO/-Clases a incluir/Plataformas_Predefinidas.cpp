#include <iostream>
#include <vector>
using namespace std;

class Framework{
	vector<string>Preset_Plat;
public:
	Framework(int num_plat);
};

int main() {
	int num_plat = 0;
	Framework Plataforma(num_plat);
	
	return 0;
}

Framework::Framework(int num_plat){
	
	Preset_Plat.resize(10);
	
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
		break;
		
	case 3:
		//				 "0123456789"
		Preset_Plat[0] = "..OOOOOO..";
		Preset_Plat[1] = ".....OOO..";
		Preset_Plat[2] = "..O.......";
		Preset_Plat[3] = "..OOOOOO..";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "OO......OO";
		Preset_Plat[6] = "..........";
		break;
		
	default:
		Preset_Plat[0] = "..........";
		Preset_Plat[1] = "..........";
		Preset_Plat[2] = "..........";
		Preset_Plat[3] = "..........";
		Preset_Plat[4] = "..........";
		Preset_Plat[5] = "..........";
		Preset_Plat[6] = "..........";
		
		//break;
	}
	
	
	for(int i=0;i<7;i++) { 
		cout<<i<<"  ";
		for(int j=0;j<10;j++) { 
			cout<<Preset_Plat[i][j]<<" ";
		}
		cout<<endl;
	}
}
