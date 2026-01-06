#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//  --------- esto no se pide el ejercicio pero lo hacemos para probar el template con otro struct -------
struct par{
	int ent;
	float flo;
};
bool mayorent(par x,par y){
	return x.ent>y.ent;
}
bool mayorflo(par x,par y){
		return x.flo>y.flo;
}
//  ------------------------------------------------------------------------------------------------------

struct Persona{
	string nombre;
	string apellido;
	int dni;
};
//funciones para la comparacion del struct Persona
bool mayornombre(Persona x, Persona y){
	return x.nombre>y.nombre;
}
bool mayorapellido(Persona x, Persona y){
	return x.apellido>y.apellido;
}
bool mayordni(Persona x, Persona y){
	return x.dni>y.dni;
}

//funcion templatizada para obtener el amyor entre 2 tipos de datos simples (int, float, string, etc)	
template<typename T>
T mayor(T x, T y){
	if(x>y) return x;
	else return y;
}
//funcion templatizada para obtener el amyor entre 2  structs donde se le debe pasar una puncion booleana con el criterio de comparacion
template<typename T, typename PF>
T mayor(T x, T y, PF funcioncomparacion){
	if(funcioncomparacion(x,y)) return x;
	else return y;
}
	
//funcion para buscar el mayor de un arreglo de datos simples
template<typename T>
T mayor(vector<T> x){
	T mayor=x[0];
	for(int i=1;i
		<x.size();i++) { 
		if(x[i]>mayor)
			mayor=x[i];
	}
	return mayor;
}
	
int main(int argc, char *argv[]) {
	cout<< mayor(4.6,45.8) <<endl;
	cout<< mayor<int>(3,7) <<endl;
	cout<< mayor("carlos","patricia") <<endl;
	cout<< mayor<float>(4,1.8) <<endl<<endl;
	
	vector<int>v(10);
	vector<float>f(10);
	vector<string>s={"asd","rdf","gft","tsd","ddf","mft","jsd","ldf","hft","dsd","qdf","cft"};
	srand(time(0));
	for(int i=0;i<v.size();i++) {  
		v[i]=rand()%100;
		f[i]=rand()%100+rand()%100/100.0;
		cout<<v[i]<<"  "<<f[i]<<"   "<<s[i]<<endl;
	}
	cout<<endl;
	cout<<mayor(v)<<endl;
	cout<<mayor(f)<<endl;
	cout<<mayor(s)<<endl<<endl;
	
	Persona p1={"marcelo","perez",25000000};
	Persona p2={"luis","lopez",28000000};
	Persona ma = mayor<Persona>(p1,p2,mayorapellido);
	cout<< ma.apellido<<"   "<<ma.nombre<<"   "<<ma.dni<<endl;
	par a={12,3.4};
	par b={25,1.4};
	par m=mayor<par>(a,b,mayorent);
	cout<<m.ent<<", "<<m.flo<<endl;
	return 0;
}

