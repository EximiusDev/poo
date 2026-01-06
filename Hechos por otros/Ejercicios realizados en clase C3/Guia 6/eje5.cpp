#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Puntaje{
	char nombre[15];
	int puntos;
};


bool comparaPuntos(Puntaje x, Puntaje y){
	return x.puntos<y.puntos;
}


class GestionPuntajes{
private:
	vector<Puntaje> v;
	int cantMaxima;
	string nomArch;

public:
	GestionPuntajes(string na, int  can):nomArch(na),cantMaxima(can){
		fstream f(nomArch, ios::binary|ios::in|ios::out|ios::ate);
		int c=f.tellg()/sizeof(Puntaje);
		Puntaje p;
		f.seekg(0);
		for(int i=0;i<c;i++) { 
			f.read(reinterpret_cast<char*>(&p),sizeof(p));
			v.push_back(p);
		}
	}
	int Cant(){return v.size();}
	Puntaje Ver(int x){return v[x];}
	
	void Agregar(Puntaje x){
		v.push_back(x);
		sort(v.begin(),v.end(),comparaPuntos);         //ordeno de menor a mayor   
		reverse(v.begin(),v.end());     //invierto el orden del vector
		if(v.size()>cantMaxima) v.pop_back(); //si me paso de la cantidad de scores elimino el ultimo que es el mas chico 
		fstream f(nomArch, ios::binary|ios::in|ios::out|ios::trunc);
		for(size_t i=0;i<v.size();i++) { 
			f.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
		}
		f.close();
	}					
};


int main(int argc, char *argv[]) {
	GestionPuntajes Score("score.dat",5);
	Puntaje aux ;
	strcpy(aux.nombre,"pancho");
	aux.puntos=120;
	Score.Agregar(aux);
	strcpy(aux.nombre,"Ana");
	aux.puntos=78;
	Score.Agregar(aux);
	strcpy(aux.nombre,"Mario");
	aux.puntos=15;
	Score.Agregar(aux);
	strcpy(aux.nombre,"Lucia");
	aux.puntos=90;
	Score.Agregar(aux);
	strcpy(aux.nombre,"Catalina");
	aux.puntos=20;
	Score.Agregar(aux);
	strcpy(aux.nombre,"Matias");
	aux.puntos=98;
	Score.Agregar(aux);
	
	for(int i=0;i<Score.Cant();i++) { 
		cout<<Score.Ver(i).nombre<<"\t"<<Score.Ver(i).puntos<<endl;
	}
	
	return 0;
}

