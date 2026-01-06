/*Ej 1 (30pts) En una competencia de matemática participaron grupos de alumnos de 4
universidades: UTN, UNL, UCSF y UADER (codificadas con 1, 2, 3 o 4). Cada grupo tiene
un nombre o alias que lo identifica. Los resultados de cada uno de los grupos se
guardaron en registros en un archivo binario llamado "Competencia.dat". Cada registro
tiene el código de la universidad, el nombre del grupo, y la cantidad de puntos
logrados.  Escriba un programa que lea el archivo y actualice los datos de tal manera
que queden ordenados por el código de universidad, y además muestre por pantalla 
cuántos puntos logró cada universidad en total y el mejor grupo de cada una.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
struct equipo{
	int codigo;
	char nombre[15];
	int puntos;
}; 

//la siguientes 2 funciones no se piden pero las hago para poder probar el programa
void GeneraArchivoBinarioIncial(){  
	fstream f("competencia.dat",ios::binary|ios::in|ios::out|ios::trunc);
	equipo aux;
	srand(time(0));
	cout<<"Registros generados:\n";
	for(int j=0;j<20;j++) { 
		aux.codigo=1+rand()%4;
		aux.puntos=rand()%11;
		for(int i=0;i<4;i++){
			aux.nombre[i]=(char)((int)'A'+rand()%26);  //genero un nombre al azar
		}
		aux.nombre[4]='\0';
		cout<<aux.codigo<<"  "<<aux.nombre<<"  "<<aux.puntos<<endl;
		//f.write((char*)&aux,sizeof(aux));
		f.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	f.close();
}
string ContenidoArchivoBinario(){
	fstream f("competencia.dat",ios::binary|ios::in|ios::out|ios::ate);
	equipo aux; string salida="";
	int cant=f.tellg()/sizeof(equipo);
	f.seekg(0);
	auto f.be
	for(int i=0;i<cant;i++) { 
		f.read((char*)&aux,sizeof(aux));
		salida += to_string(aux.codigo) + "  " + aux.nombre + "  " + to_string(aux.puntos) + "\n";
	}
	f.close();
	return salida;
}
	
	
//--------------------------------------------------------
	
bool operator<(equipo x, equipo y){       //para poder usar el sort
	return x.codigo<y.codigo;
}


class funcionaccum {     //clase para poder usar el acumulate.......
private:
	int valor;
public:
	funcionaccum(int x) : valor(x) {}
	int operator()(int a, equipo b) const {return b.codigo == valor ? a+b.puntos : a;}                  //debo comparar el codigo del  b
};

int AcumulaPuntosPorCodigo1(int x, equipo y){
	if(y.codigo==1) return x+y.puntos;
	else return x;
}
int AcumulaPuntosPorCodigo2(int x, equipo y){
	if(y.codigo==2) return x+y.puntos;
	else return x;
}
int AcumulaPuntosPorCodigo3(int x, equipo y){
	if(y.codigo==3) return x+y.puntos;
	else return x;
}
int AcumulaPuntosPorCodigo4(int x, equipo y){
	if(y.codigo==4) return x+y.puntos;
	else return x;
}

	
	
	
class funcionmax {     //clase para el max_element
private:
	int valor;
public:
	funcionmax(int x) : valor(x) {}
	bool operator()(equipo a, equipo b) const {return b.codigo == valor && a.puntos<b.puntos;}   //debo comparar el codigo del b
};



int main(int argc, char *argv[]) {
	GeneraArchivoBinarioIncial();
			
	fstream f("competencia.dat",ios::binary|ios::in|ios::out|ios::ate);
	vector<equipo> v;
	equipo aux;
	int cant=f.tellg()/sizeof(equipo);
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read((char*)&aux,sizeof(aux));
		v.push_back(aux);
	}
	f.close();
	sort(v.begin(),v.end());
	
		
	cout<<"\nequipos ordenados por codigo:\n";
	for(equipo x:v)
		cout<<x.codigo<<"  "<<x.nombre<<"  "<<x.puntos<<endl;
	cout<<endl;
    vector<int> puntos(4,0);
	vector<int> m(4,0);
	vector<equipo> mejor(4);
	
	/*for(int i=0;i<cant;i++) {          //esto si no uso el max_element ni el accumulate con las clases.....
		
		puntos[v[i].codigo-1] += v[i].puntos;   //acumulo los puntos por el codigo0
	
		if(v[i].codigo==1 && v[i].puntos>mejor[0].puntos) mejor[0]= v[i];
		else if(v[i].codigo==2 && v[i].puntos>mejor[1].puntos) mejor[1]= v[i];
		else if(v[i].codigo==3 && v[i].puntos>mejor[2].puntos) mejor[2]= v[i];
		else if(v[i].codigo==4 && v[i].puntos>mejor[3].puntos) mejor[3]= v[i];
	}
	*/
	
		for(int i=0;i<4;i++){                                         //esto sustituye al for anterior (linea 127)
		//puntos[i]=accumulate(v.begin(),v.end(),0,funcionaccum(i+1));
		mejor[i]=*(max_element(v.begin(),v.end(),funcionmax(i+1)));
	}
	
	puntos[0]=accumulate(v.begin(),v.end(),0,AcumulaPuntosPorCodigo1);
	puntos[1]=accumulate(v.begin(),v.end(),0,AcumulaPuntosPorCodigo2);
	puntos[2]=accumulate(v.begin(),v.end(),0,AcumulaPuntosPorCodigo3);
	puntos[3]=accumulate(v.begin(),v.end(),0,AcumulaPuntosPorCodigo4);
		
	
	
	for(int i=0;i<4;i++) { 
		cout<<"total puntos codigo "<<i+1<<" : "<<puntos[i]<<endl;
	}
	
	cout<<"Mejor "<<mejor[0].codigo<<" : "<<mejor[0].nombre<<"  "<<mejor[0].puntos<<endl;
	cout<<"Mejor "<<mejor[1].codigo<<" : "<<mejor[1].nombre<<"  "<<mejor[1].puntos<<endl;
	cout<<"Mejor "<<mejor[2].codigo<<" : "<<mejor[2].nombre<<"  "<<mejor[2].puntos<<endl;
	cout<<"Mejor "<<mejor[3].codigo<<" : "<<mejor[3].nombre<<"  "<<mejor[3].puntos<<endl;

	//guardo en el archivo los datos ordenados por codigo
	f.open("competencia.dat",ios::binary|ios::in|ios::out|ios::trunc);
	for(int i=0;i<cant;i++) { 
		f.write((char*)&v[i],sizeof(equipo));
	}
	f.close();
	
	cout<<"\nContenido del archivo:\n"<<ContenidoArchivoBinario()<<endl;
		
	
	return 0;
}

