#include <iostream>
#include <vector>
using namespace std;

class PremadeMap{
	int difficulty = 1;
	vector<int>sequence;
	int cont = 0;
	int n=100;
public:
	PremadeMap();
	int GetDif(){return difficulty;}
	int Get_Current_Platform(){return sequence[cont];}
	int Get_Platform(int i){return sequence[i];}
	int Get_Final_Platform(){return sequence[n-1];}
	vector <int> Get_Sequence(){return sequence;}
};

int main() {
	PremadeMap PM;
	
	return 0;
}

PremadeMap::PremadeMap(){
	sequence.push_back(0);
	int num_rand;
	int num_rand2;
	int num_rand3;
	int part_cont = 0;
	for(int i=1;i<n;i++) { 
		num_rand = rand()%(5 + (part_cont/4)*difficulty) + 1;
		sequence.push_back(num_rand);
		part_cont++;
		cout<<i<<". sequence: "<<sequence[i]<<endl;
	}
	/*
	int num_rand;
	int num_rand2;
	int num_rand3;
	
	
	int prev = 0;
	int prev1 = 0;
	
	int part_cont = 0;
	for(int i=1;i<99;i++) { 
		num_rand = rand()%(5 + (part_cont/4)*difficulty) + 1;
		num_rand2 = rand()%(5 + (part_cont/4)*difficulty) + 1;
		num_rand3 = rand()%(5 + (part_cont/4)*difficulty) + 1;
		
		if ((num_rand == sequence[i-1]) or (num_rand == prev) or (num_rand == prev1)){
			if(num_rand2 == sequence[i-1] or num_rand2 == prev or num_rand2 == prev1){
				
			}else sequence.push_back(num_rand2);
		}else sequence.push_back(num_rand);
		prev = sequence[i-1];
		prev1 = sequence[i-2];
		
		part_cont++;
		
		//cout<<i<<". "<<sequence[i]<<endl;
		cout<<i<<". "<<sequence[i]<<"  "<<num_rand<<" "<<num_rand2<<" "<<num_rand3<<" "<<prev<<" "<<prev1<<endl;
	}*/
}
