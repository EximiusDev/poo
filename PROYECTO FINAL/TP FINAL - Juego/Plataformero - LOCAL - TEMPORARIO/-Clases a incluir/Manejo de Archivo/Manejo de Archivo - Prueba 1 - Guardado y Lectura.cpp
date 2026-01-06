#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;

struct Data_Struct{
public:
	Data_Struct(){
		points_str = 0;
		strcpy(date_str, "_");
		strcpy(name_str, "_");
		//is_topScore = false;
	}
	char date_str[25];
	char name_str[20];
	int points_str;
	bool is_topScore = false;
	//int life_str;
	//long time_str;
	//bool is_saved = false;
	//bool is_current_save = false;
};


int Tamanio_Archi(fstream &Archi){
	int tamanio = Archi.tellg(); /// tamanioo en bytes
	return tamanio/sizeof(int);
}
int Tamanio_Archi(ifstream &Archi){
	int tamanio = Archi.tellg(); /// tamanioo en bytes
	return tamanio/sizeof(int);
}

	///sort(highscore.begin(),highscore.end(),reverse_sort);
	/*
	bool highscores_menu::reverse_sort(hsStruct a1,hsStruct a2){
	return a2._points<a1._points;
	}
	*/
	bool reverse_sort(Data_Struct h1,Data_Struct h2){
		return h2.points_str < h1.points_str;
	}
	/*bool reverse_sort(int h1,int h2){
		return h2 < h1;
	}*/

int main() {
	//ifstream("SaveData.dat"); //HighScores ///Archi("nombre.bin",ios::binary|ios::in|ios::out|ios::ate)
	
	string nombre_archivo = "SaveData.bin"; /// "SaveData.bin"
	
	srand(time(0));
	
	int current_score = rand()%100;
	cout<<"current_score: "<<current_score<<endl;
	
	vector<int> score;
	vector<Data_Struct> prueba;
	prueba.resize(10);
	
	for(Data_Struct &Str_aux : prueba){
		Str_aux.points_str = rand()%100;
		
		time_t current_time; /// current_time es una clase de tipo time_t
		current_time = time(NULL); 
		strcpy(Str_aux.date_str, ctime(&current_time)); /// pone un \n al final
		
		if(Str_aux.is_topScore){
			cout<<"Esta en el TOP: ";
		}
		//cout<<". Puntos: "<<Str_aux.points_str<<" Nombre: "<<Str_aux.name_str<<" Fecha: "<<Str_aux.date_str;
		//printf(". Puntos: %d Nombre: %s Fecha: %s", Str_aux.points_str, Str_aux.name_str, Str_aux.date_str); /// elimina el \n al final
		
	}
	
	cout<<endl;
	sort(prueba.begin(),prueba.end(),reverse_sort);
	for(Data_Struct &Str_aux : prueba){
		//printf(". Puntos: %d Nombre: %s Fecha: %s", Str_aux.points_str, Str_aux.name_str, Str_aux.date_str); /// elimina el \n al final
	}
	
	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//fstream read_archi("SaveData.bin",ios::binary|ios::ate|ios::in);
	ifstream read_archi(nombre_archivo,ios::binary|ios::in); // ifstream read_archi(nombre_archivo,ios::binary|ios::ate|ios::in);
	int dato;
	
	if(!read_archi.is_open()){
		ofstream write_archi(nombre_archivo,ios::binary|ios::trunc);
		cout<<"El archivo se creo de nuevo"<<endl;
		
		int valor = current_score;
		/*
		for(unsigned int i=0;i<score.size();i++) { 
			valor = rand()%101;
			cout<<i<<". "<<valor<<endl;
			write_archi.write(reinterpret_cast<char*>(&valor),sizeof(int));
		}*/
		write_archi.write(reinterpret_cast<char*>(&valor),sizeof(valor));
		
		write_archi.close();
	}
	else{
		cout<<"Se Lee el archivo"<<endl;
		
		score.push_back(current_score);
		
		while (read_archi.read	(reinterpret_cast<char*>(&dato),sizeof(int))){
			cout<<". "<<dato<<endl;
			score.push_back(dato);
		}
		/*
		int tamanio = Tamanio_Archi(read_archi);
		cout<<"tamanio "<<tamanio<<endl;
		read_archi.seekg(0);
		
		/// score.resize(tamanio); 
		
		for(int i=0;i<tamanio;i++) { 
			read_archi.read	(reinterpret_cast<char*>(&dato),sizeof(int));
			cout<<i<<". "<<dato<<endl;
			score.push_back(dato); ///
		}
		*/
		
		read_archi.close();
		
		cout<<endl;
		
		/*
		if(score.size()> 11 ){
			auto it10 = score.begin()+ 11;
			sort(score.begin(),it10);
			reverse(score.begin(),it10);
		}
		else{
			sort(score.begin(),score.end()); // sort(score.begin(),score.end(),reverse_sort);
			reverse(score.begin(),score.end());
		}
		if(score.size()> 20 ){
			for(int i=10;i<20;i++) { 
				score[i] = score[i+1];
			}
			score.resize(20);
		}
		*/
		sort(score.begin(),score.end()); // sort(score.begin(),score.end(),reverse_sort);
		reverse(score.begin(),score.end());
		if(score.size()> 10 )score.resize(10);
		
		ofstream re_write_archi(nombre_archivo,ios::binary|ios::trunc);
		
		for(unsigned int i=0;i<score.size();i++) { 
			cout<<i<<". "<<score[i]<<endl;
			re_write_archi.write(reinterpret_cast<char*>(&score[i]),sizeof(score[i]));
		}
		re_write_archi.close();
	}
	
	
	cout<<endl;
	int n = 10;
	if (score.size()< 10) n = score.size();
	for(unsigned int i=0;i<n;i++) {
		cout<<i<<". "<<score[i]<<endl;
	}
	
	
	
	return 0;
}
