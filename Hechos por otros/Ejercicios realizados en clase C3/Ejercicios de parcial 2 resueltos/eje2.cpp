/*Ej 2 (30pts) Un archivo de texto "mundial2022.txt" registra los resultados de los
partidos. Cada línea indica un partido y tiene 5 datos separados por coma, la fecha
(mmdd), el nombre del 1er equipo, los goles que hizo, el nombre del 2do, y los goles
que hizo (Por ej, el martes podría decir: "1122,Argentina,5,Arabia Saudita,0"). Los
partidos que no se jugaron todavía tendrán -1 en ambas cantidades de goles 
(Por ej:"1130,Polonia,-1,Argentina,-1"). Escriba una función cargarResultado que 
sirva para actualizar el archivo cada vez que finaliza un partido. La función debe 
recibir la fecha, los nombres de los dos equipos y las cantidades de goles. Si el 
partido estaba en el archivo (misma fecha y equipos pero con -1 en goles) debe 
modificarlo, y si no agregarlo al final (pues los de la fase de grupos estarán 
precargados con -1 porque se ya se conocen los equipos, pero los de octavos en 
adelante no).
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
struct partido{
	string fecha, pais1, goles1, pais2, goles2;
};

void cargaarchivo(vector<partido> &x){
	ifstream t("mundial2022.txt");
	partido r;
	string s;
	while(getline(t,s)){
		r.fecha=s.substr(0,s.find(",")); s.erase (0,s.find(",")+1);
		r.pais1=s.substr(0,s.find(",")); s.erase(0,s.find(",")+1);
		r.goles1=s.substr(0,s.find(",")); s.erase(0,s.find(",")+1);
		r.pais2=s.substr(0,s.find(",")); s.erase(0,s.find(",")+1);
		r.goles2=s;
	    x.push_back(r);	
	}
	t.close();
}

bool operator==(partido x, partido y){                                  //sobrecargo para poder usar el find con el struct
	return x.fecha==y.fecha && x.pais1==y.pais1 && x.pais2==y.pais2;    //no verifico que los goles valgan -1 pero se puede agregar facilmente...
}                                                                         
	
void cargarresultado (vector<partido> &x, partido w){
	auto it= find(x.begin(),x.end(),w);
	if (it==x.end())
		 x.push_back(w);					//si no esta lo agrego
	else
		*it=w;								//si lo encuentra lo actualizo
}
	
	
void grabarchivo(vector<partido> x){
	ofstream t("mundial2022.txt",ios::trunc);
	for(partido p:x)
		t<<p.fecha<<","<<p.pais1<<","<<p.goles1<<","<<p.pais2<<","<<p.goles2<<endl;
	t.close();
}
		
	
int main(int argc, char *argv[]) {
	vector<partido> v;
	partido aux;
	
	cargaarchivo(v);
	
	for(partido p:v)
		cout<<p.fecha<<"    "<<p.pais1<<"    "<<p.goles1<<"    "<<p.pais2<<"    "<<p.goles2<<endl;


	cout<<"fecha (ddmm): "; getline(cin,aux.fecha);
	cout<<"pais1: "; getline(cin,aux.pais1);
	cout<<"goles1: "; getline(cin,aux.goles1);
	cout<<"pais2: "; getline(cin,aux.pais2);
	cout<<"goles2: "; getline(cin,aux.goles2);
	
	cargarresultado(v,aux);
	
	for(partido p:v)
		cout<<p.fecha<<"    "<<p.pais1<<"    "<<p.goles1<<"    "<<p.pais2<<"    "<<p.goles2<<endl;
	
	
	grabarchivo(v);
	
	return 0;
}

