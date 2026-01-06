#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

/// PremadeMap

///Si pedis una plataforma con un numero cualquiera empieza a contar desde ahi
///Es decir current_plat y Plat[i] van a ser distintos si i>cont


class PremadeMap{
	int difficulty;
	vector<int>sequence;
	vector<int>sequence2;
	int cont = 0;
	int score = 0;
	//int n;
	void Add_Secuence(int i=0);
	void Generate_Secuence(int num_v = 1);
	int num_max = 50;
public:
	PremadeMap(int dif=1);
	int GetDif(){return difficulty;}
	int Get_Current_Platform(){Add_Secuence();	cont++;	 return sequence[cont-1];}
	int Get_Platform(int i){ Add_Secuence(i); //return sequence[i-(score*num_max)];}
		if(i>num_max){
			for(int j=0;j<i-(score*num_max);j++) { sequence[j] = sequence2[j]; }
			return sequence[i-(score*num_max)];
		}
		//if(i>num_max) return sequence2[i-(score*num_max)];
		else return sequence[i];}
	int Get_Final_Platform(){Add_Secuence(); 	return sequence[num_max-1];}
	int Get_Score(){return score;}
	int Get_Current(){return cont-1;}
	vector <int> Get_Sequence(){return sequence;}
};

int main() {
	srand(time (0) );
	PremadeMap pmm;
	
	for(unsigned int i=0;i<100;i++) { 
		cout<<i<<" cont, "<<pmm.Get_Current()<<". Current: "<<pmm.Get_Current_Platform()<<endl;
	}
	
	cout<<endl;
	cout<<endl;
	cout<<"Final_plat: "<<pmm.Get_Final_Platform()<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"plat 30: "<<pmm.Get_Platform(30)<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"plat 628: "<<pmm.Get_Platform(628)<<endl;
	cout<<"plat 11: "<<pmm.Get_Platform(11)<<endl;
	cout<<"plat 312: "<<pmm.Get_Platform(312)<<endl;
	cout<<"plat 16: "<<pmm.Get_Platform(16)<<endl;
	vector<int>seq;
	seq = pmm.Get_Sequence();
	
	for(unsigned int i=0;i<seq.size();i++) { 
		cout<<i<<" cont, "<<pmm.Get_Current()<<". seq[i]: "<<seq[i]<<" Current: "<<pmm.Get_Current_Platform()<<endl;
	}
	cout<<endl;
	cout<<endl;
	cout<<"Final_plat: "<<pmm.Get_Final_Platform()<<endl;
	
	return 0;
}

PremadeMap::PremadeMap(int dif){
	difficulty = dif;
	//sequence.push_back(0);
	sequence.resize(num_max);
	sequence2.resize(num_max);
	Generate_Secuence();
}
void PremadeMap::Generate_Secuence(int num_v){
	vector<int>vect_aux;
	vect_aux.resize(num_max);
	int num_rand=-1;
	//int num_rand2;
	//int prev=-1;
	
	int part_cont = 0;
	for(int i=cont*num_v;i<num_max;i++) {
		num_rand = rand()%(5 + ((part_cont + num_max*score)/4)*difficulty) + 1;
		//num_rand2 = rand()%(5 + (part_cont/4)*difficulty) + 1;
		
		while((num_rand == sequence[i-1]) or (num_rand == sequence[i-2] )){
			///cout<<"num_rand: "<<"/"<<num_rand<<"/";
			num_rand = rand()%(5 + ((part_cont + num_max*score)/4)*difficulty) + 1;
		} //prev = num_rand;
		//vect_aux.push_back(num_rand);
		vect_aux[i] = num_rand;
		part_cont++;
		if(score == 0)vect_aux[0] = 0;
		///cout<<i<<". sequence: "<<sequence[i]<<" "<<sequence[i-1]<<" "<<num_rand<<endl;
		cout<<i<<". sequence: "<<vect_aux[i]<<" score: "<<score<<endl;
	}cout<<"-----------------------"<<endl;
	if (num_v == 1) sequence = vect_aux;
	else sequence2 = vect_aux;
	for(int i=0;i<num_max;i++) { 
		cout<<i<<". sequence: "<<vect_aux[i]<<" "<<sequence[i]<<" "<<sequence2[i]<<" "<<score<<endl;
	}
}

void PremadeMap::Add_Secuence(int i){
	if (i>cont){
		cont = i - (i/num_max)*num_max;
	} 
	if(cont>=num_max){
		score++; 
		cont = 0;
		
		Generate_Secuence();
	}
	if (i>num_max){
		score = (i)/num_max ;
		Generate_Secuence(); //if (i>num_max) Generate_Secuence(0);
		Generate_Secuence(0); 
	} 
}
