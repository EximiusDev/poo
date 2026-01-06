#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
struct ficha{
	string nombre;
	int n1,n2;
}; 

vector<ficha> leeArchivo(){
	vector<ficha> aux;
	ifstream archi("alumnos.txt");
	ficha a;
	while(getline(archi,a.nombre)){
		archi>> a.n1 >> a.n2; 
		aux.push_back(a);
		//cout<<a.nombre<<" "<<a.n1<<"  "<<a.n2<<endl;
		archi.ignore();
	}
	archi.close();
	return aux;
}

bool modifica(string al, int nn1,int nn2){
	vector<ficha> v=leeArchivo();
/*	ifstream archi("alumnos.txt");
	ficha a;
	while(getline(archi,a.nombre)){
		archi>> a.n1 >> a.n2; 
		v.push_back(a);
		cout<<a.nombre<<" "<<a.n1<<"  "<<a.n2<<endl;
		archi.ignore();
	}
	archi.close();*/
	int p=0;
	while(p<v.size() && v[p].nombre!=al) 
		p++;
	
		v[p].n1=nn1;
		v[p].n2=nn2;
		ofstream archi2("alumnos.txt",ios::trunc);
		for(int i=0;i<v.size();i++) {
			archi2<<v[i].nombre<<endl;
			archi2<<v[i].n1<<"  "<<v[i].n2<<endl;
		}
		archi2.close();
		return true;
	}else
		return false;
}

	
void promedio(){
	vector<ficha> v=leeArchivo();
	/*ifstream archi("alumnos.txt");
	ficha a;
	while(getline(archi,a.nombre)){
		archi>> a.n1 >> a.n2; 
		v.push_back(a);
		archi.ignore();
	}
	archi.close();*/
	ofstream archi2("promedios.txt",ios::trunc);
	for(int i=0;i<v.size();i++) {
		float prom=(v[i].n1+v[i].n2)/2.0;
		archi2<<setw(20)<<left<<v[i].nombre<<"  "<<right<<setw(8)<<setprecision(2)<<fixed<<prom<<"   ";
		if(prom>=70) archi2<<"promociona\n";
		else if(prom>=40) archi2<<"regular\n";
			else archi2<<"libre\n";
		}
		archi2.close();
	}
		
int main(int argc, char *argv[]) {
	cout<<modifica("ana",40,41);
	promedio();
	return 0;
}

