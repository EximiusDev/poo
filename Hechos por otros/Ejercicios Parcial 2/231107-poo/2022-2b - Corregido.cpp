/**
2022 - Parcial 2 - Tema B

Ej 2 (30pts) Un archivo de texto "mundial2022.txt" registra los resultados de los partidos.
Cada línea indica un partido y tiene 5 datos separados por coma, la fecha (mmdd), el nombre
del 1er equipo, los goles que hizo, el nombre del 2do, y los goles que hizo (Por ej, el
martes podría decir: "1122,Argentina,5,Arabia Saudita,0"). Los partidos que no se jugaron
todavía tendrán -1 en ambas cantidades de goles (Por ej:"1130,Polonia,-1,Argentina,-1").
Escriba una función cargarResultado que sirva para actualizar el archivo cada vez que
finaliza un partido. La función debe recibir la fecha, los nombres de los dos equipos y 
las cantidades de goles. Si el partido estaba en el archivo (misma fecha y equipos pero con
-1 en goles) debe modificarlo, y si no agregarlo al final (pues los de la fase de grupos
estarán precargados con -1 porque se ya se conocen los equipos, pero los de octavos en
adelante no).
**/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Partido {
	int fecha;
	string nom1, nom2;
	int gol1, gol2;
};

bool operator==(Partido p1, Partido p2) {
	return p1.fecha==p2.fecha and p1.nom1==p2.nom1 and p1.nom2==p2.nom2;
}

vector<Partido> cargarDatos(string fname) {
	ifstream f(fname);
	vector<Partido> v;
	Partido p;
	string aux_f, aux_g1, aux_g2;
	// le puedo pedir a getline que lea hasta la coma y no hasta el enter
	while(getline(f,aux_f,',') and getline(f,p.nom1,',') and getline(f,aux_g1,',')
		  and getline(f,p.nom2,',') and getline(f,aux_g2)) 
	{
		p.fecha = stoi(aux_f);
		p.gol1 = stoi(aux_g1);
		p.gol2 = stoi(aux_g2);
		v.push_back(p);
	}

	// version alternativa: leer toda la linea y cortar con find y substr
//	string todo;
//	while(getline(f,todo)) 
//	{
//		size_t p1 = todo.find(',');
//		size_t p2 = todo.find(',',p1+1);
//		size_t p3 = todo.find(',',p2+1);
//		size_t p4 = todo.find(',',p3+1);	
//		
//		                
//		p.fecha = stoi( todo.substr(0,p1) );
//		p.nom1 = todo.substr(p1+1,p2-p1-1);
//		p.nom2 = todo.substr(p3+1,p4-p3-1);
//		p.gol1 = stoi( todo.substr(p2+1,p3-p2-1) );
//		p.gol2 = stoi( todo.substr(p4+1) );
//		v.push_back(p);
//	}
	return v;
}

void guardarDatos(const vector<Partido> &v, string fname) {
	ofstream f(fname);
	for(Partido p : v)
		f << p.fecha << ',' << p.nom1 << ',' << p.gol1 << ',' << p.nom2 << ',' << p.gol2 << endl;
}

void reemplazar(vector<Partido> &v, Partido p) {
	/// modificacion de Fran M, POR ERROR DE RESOLUCION
	Partido aux = p;
	aux.gol1 = -1;
	aux.gol2 = -1;
	auto it = find(v.begin(),v.end(),aux);
	/// FIN DE LA MODIFICACION
	if (it!=v.end()) *it = p;
	else v.push_back(p);
}

void cargarResultado(Partido p) {
	vector<Partido> v = cargarDatos("mundial2022.txt");
	reemplazar(v,p);
	guardarDatos(v,"mundial2022.txt");
}


