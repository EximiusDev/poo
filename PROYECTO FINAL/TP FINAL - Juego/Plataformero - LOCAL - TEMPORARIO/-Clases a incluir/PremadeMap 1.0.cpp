#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class PremadeMap{
	int difficulty = 0;
	vector<int>sequence;
	int cont = 0;
	int n=50;
public:
	PremadeMap();
	int GetDif(){return difficulty;}
	int Get_Current_Platform(){return sequence[cont];}
	int Get_Platform(int i){return sequence[i];}
	vector <int> Get_Sequence(){return sequence;}
};

int main() {
	srand(time (0) );
	PremadeMap PM;
	
	
	return 0;
}

PremadeMap::PremadeMap(){
	n = 20;
	sequence.push_back(0);
	sequence.resize(n);
	int num_rand=-1;
	//int num_rand2;
	//int num_rand3;
	//int prev=-1;
	
	int part_cont = 0;
	for(int i=1;i<n;i++) {
		num_rand = rand()%(5 + (part_cont/4)*difficulty) + 1;
		//num_rand2 = rand()%(5 + (part_cont/4)*difficulty) + 1;
		
		while(num_rand == sequence[i-1]){
			cout<<"/"<<num_rand<<"/";
			num_rand = rand()%(5 + (part_cont/4)*difficulty) + 1;
		} //prev = num_rand;
		//sequence.push_back(num_rand);
		sequence[i] = num_rand;
		/*
		if ((num_rand == sequence[i-1])){ //or (num_rand == prev) or (num_rand == prev1)){
			sequence.push_back(num_rand2);
		} else sequence.push_back(num_rand);
		*/
		part_cont++;
		//cout<<sequence[i]<<endl;
		cout<<i<<". sequence: "<<sequence[i]<<" "<<sequence[i-1]<<" "<<num_rand<<endl;
		//cout<<i<<". sequence: "<<sequence[i]<<"  "<<num_rand<<" "<<num_rand2<<" "<<num_rand3<<" "<<prev<<" "<<prev1<<endl;
	}
	/*
	int num_rand;
	int num_rand2;
	int num_rand3;
	
	
	int prev = 0;
	int prev1 = 0;
	
	int part_cont = 0;
	for(int i=1;i<n;i++) { 
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
