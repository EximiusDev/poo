#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

int Tamanio_Archi(fstream &Archi){
	int tamanio = Archi.tellg(); /// tamanioo en bytes
	return tamanio/sizeof(int);
}
int Tamanio_Archi(ifstream &Archi){
	int tamanio = Archi.tellg(); /// tamanioo en bytes
	return tamanio/sizeof(int);
}


int main() {
	//ifstream("SaveData.dat"); //HighScores ///Archi("nombre.bin",ios::binary|ios::in|ios::out|ios::ate)
	
	srand(time(0));
	
	int current_score = 50;
	
	vector<int> score;
	vector<int> prueba;
	prueba.resize(10);
	/*
	for(int &aux : prueba){
		aux = rand()%100;
		cout<<". "<<aux<<endl;
	}*/
	
	///sort(highscore.begin(),highscore.end(),reverse_sort);
	/*
	bool highscores_menu::reverse_sort(hsStruct a1,hsStruct a2){
	return a2._points<a1._points;
	}
	*/
	
	//fstream read_archi("SaveData.bin",ios::binary|ios::ate|ios::in);
	ifstream read_archi("SaveData.bin",ios::binary|ios::ate|ios::in);
	
	if(!read_archi.is_open()){
		ofstream write_archi("SaveData.bin",ios::binary|ios::trunc);
		cout<<"El archivo se creo de nuevo"<<endl;
		
		int valor;
		for(unsigned int i=0;i<score.size();i++) { 
			valor = rand()%101;
			cout<<i<<". "<<valor<<endl;
			write_archi.write(reinterpret_cast<char*>(&valor),sizeof(int));
		}
		
		write_archi.close();
	}
	else{
		cout<<"Se Lee el archivo"<<endl;
		
		int tamanio = Tamanio_Archi(read_archi);
		read_archi.seekg(0);
		
		/// score.resize(tamanio); 
		
		int dato;
		for(int i=0;i<tamanio;i++) { 
			read_archi.read	(reinterpret_cast<char*>(&dato),sizeof(int));
			cout<<i<<". "<<dato<<endl;
			score.push_back(dato); ///
		}
		
		read_archi.close();
	}
	
	
	cout<<endl;
	
	for(unsigned int i=0;i<score.size();i++) {
		cout<<i<<". "<<score[i]<<endl;
	}
	
	
	return 0;
}
