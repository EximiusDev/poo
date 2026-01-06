#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

///Si pedis una plataforma con un numero cualquiera empieza a contar desde ahi
///Es decir current_plat y Plat[i] van a ser distintos si i>cont


class PremadeMap{
	int difficulty;
	vector<int>sequence;
	int cont = 0;
	int score = 0;
	int n;
	void Add_Secuence(int i=0);
	void Generate_Secuence();
	int num_max = 50;
public:
	PremadeMap(int dif=1);
	int GetDif(){return difficulty;}
	int Get_Current_Platform(){Add_Secuence();	cont++;	 return sequence[cont-1];}
	int Get_Platform(int i){Add_Secuence(i); 	return sequence[i-(score*num_max)];}
	int Get_Final_Platform(){Add_Secuence(); 	return sequence[n-1];}
	int Get_Score(){return score;}
	vector <int> Get_Sequence(){return sequence;}
};

int main() {
	srand(time (0) );
	PremadeMap pmm;
	
	cout<<endl;
	cout<<endl;
	cout<<"Final_plat: "<<pmm.Get_Final_Platform()<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"plat: "<<pmm.Get_Platform(30)<<endl;
	cout<<endl;
	cout<<endl;
	//cout<<"plat: "<<pmm.Get_Platform(300)<<endl;
	cout<<"plat: "<<pmm.Get_Platform(622)<<endl;
	vector<int>seq;
	seq = pmm.Get_Sequence();
	
	for(unsigned int i=0;i<seq.size();i++) { 
		cout<<i<<". seq[i]: "<<seq[i]<<" Current: "<<pmm.Get_Current_Platform()<<endl;
	}
	cout<<endl;
	cout<<endl;
	cout<<"Final_plat: "<<pmm.Get_Final_Platform()<<endl;
	
	return 0;
}

PremadeMap::PremadeMap(int dif){
	difficulty = dif;
	n = num_max/2;
	sequence.push_back(0);
	sequence.resize(n);
	Generate_Secuence();
}
void PremadeMap::Generate_Secuence(){
	int num_rand=-1;
	//int num_rand2;
	//int prev=-1;
	
	int part_cont = 0;
	for(int i=cont;i<n;i++) {
		num_rand = rand()%(5 + ((part_cont + num_max*score)/4)*difficulty) + 1;
		//num_rand2 = rand()%(5 + (part_cont/4)*difficulty) + 1;
		
		while((num_rand == sequence[i-1]) or (num_rand == sequence[i-2] )){
			///cout<<"num_rand: "<<"/"<<num_rand<<"/";
			num_rand = rand()%(5 + ((part_cont + num_max*score)/4)*difficulty) + 1;
		} //prev = num_rand;
		//sequence.push_back(num_rand);
		sequence[i] = num_rand;
		part_cont++;
		///cout<<i<<". sequence: "<<sequence[i]<<" "<<sequence[i-1]<<" "<<num_rand<<endl;
		cout<<i<<". sequence: "<<sequence[i]<<" score: "<<score<<endl;
	}cout<<"-----------------------"<<endl;
}

void PremadeMap::Add_Secuence(int i){
	if (i>=cont) cont = i ;// - (i/num_max)*num_max; 
	cout<<(i/num_max)*num_max<<endl;
	if (cont >= n){
		n = num_max;
		sequence.resize(n);
		Generate_Secuence();
	}
	if(cont>=num_max){
		if (i>=cont) score = (cont)/num_max ;
		else score++; 
		cont = 0;
		
		Generate_Secuence();
	}
}
