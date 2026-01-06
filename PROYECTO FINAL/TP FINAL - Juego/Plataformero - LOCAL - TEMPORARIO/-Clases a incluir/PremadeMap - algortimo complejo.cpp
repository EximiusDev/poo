#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class PremadeMap{
	int difficulty = 1;
	vector<int>sequence;
	int cont = -1;
	int n;
	void Add_Secuence(int i);
public:
	PremadeMap();
	int GetDif(){return difficulty;}
	int Get_Current_Platform(){cont++; return sequence[cont];}
	int Get_Platform(int i){return sequence[i];}
	int Get_Final_Platform(){return sequence[n];}
	vector <int> Get_Sequence(){return sequence;}
};

int main() {
	srand(time (0) );
	PremadeMap PM;
	
	
	return 0;
}

PremadeMap::PremadeMap(){
	n = 25;
	sequence.push_back(0);
	sequence.resize(n);
	int num_rand=-1;
	//int num_rand2;
	//int prev=-1;
	
	int part_cont = 0;
	for(int i=0;i<n;i++) {
		num_rand = rand()%(5 + (part_cont/4)*difficulty) + 1;
		//num_rand2 = rand()%(5 + (part_cont/4)*difficulty) + 1;
		
		while((num_rand == sequence[i-1]) or (num_rand == sequence[i-2] )){
			cout<<"/"<<num_rand<<"/";
			num_rand = rand()%(5 + (part_cont/4)*difficulty) + 1;
		} //prev = num_rand;
		//sequence.push_back(num_rand);
		sequence[i] = num_rand;
		part_cont++;
		cout<<i<<". "<<sequence[i]<<" "<<sequence[i-1]<<" "<<num_rand<<endl;
	}
}

void PremadeMap::Add_Secuence(int i=-2){
	if (i>cont) cont = i;
	if (cont >= n){
		n = 50;
		sequence.resize(n);
	}
}
