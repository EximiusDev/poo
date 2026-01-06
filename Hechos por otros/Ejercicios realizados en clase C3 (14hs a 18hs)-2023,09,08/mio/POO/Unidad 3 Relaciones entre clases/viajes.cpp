
#include <iostream>
#include <vector>
using namespace std;

class MedioTrans{
public:
	virtual float Tiempo(int d)=0;
	virtual string VerMedio()=0;
	virtual ~MedioTrans(){}
};

class Auto: public MedioTrans{
public:
	float Tiempo(int d){return d/110.0+5*(d%110);}
	string VerMedio(){return "Auto";}
	
};

class Avion: public MedioTrans{
public:
	float Tiempo(int d){return 2+d/900.0;}
	string VerMedio(){return "Avion";}
};

class Colectivo: public MedioTrans{
public:
	float Tiempo(int d){return d/90.0;}
	string VerMedio(){return "Colectivo";}
};


class Viaje{
	string ciuO,ciuD;
	int dist;
	MedioTrans *mt;
public:
	Viaje(string co,string cd, int di, MedioTrans *m):
		ciuO(co),ciuD(cd), dist(di), mt(m){}
	string VerCO(){return ciuO;}
	string VerCD(){return ciuD;}
	int VerDist(){return dist;}
	float TiempoDeViaje(){return mt->Tiempo(dist);}
	string VerMedioTransporte(){return mt->VerMedio();}
};


float TiempoTotal(vector<Viaje> &x){
	float tt=0;
	for(size_t i=0;i<x.size();i++) {
		cout<<"\nMedio de transporte: "<<x[i].VerMedioTransporte()<<"  : "<<x[i].TiempoDeViaje();;
		tt=tt+x[i].TiempoDeViaje();
	}
	return tt;
}


int main(int argc, char *argv[]) {
	vector<Viaje> v;
	
	v.push_back(Viaje("Rosario","Parana",200,new Auto));
	v.push_back(Viaje("Parana","Buenos Aires",400,new Avion));
	
	/*
	Colectivo *c=new Colectivo;
	Viaje v1("Rosario","Parana",320,c);
	v.push_back(v1);
	*/  //estas 3 lineas son lo mismo que la de abajo
	v.push_back(Viaje("Buenos Aires","Rosario",320,new Colectivo));
	
	float tiempo=TiempoTotal(v);
	cout<<"\ntiempo total de viajes: "<<tiempo<<endl;
	//delete c;   // esto es si usan las 3 lineas comentadas de arriba
	
	
	
	//para probar los metodos de un solo viaje
	/*Viaje v1("Rosario","Parana",320,new Colectivo);
	cout<<"\nCiudad origen: "<<v1.VerCO();
	cout<<"\nCiudad destino: "<<v1.VerCD();
	cout<<"\ndistancia: "<<v1.VerDist();
	cout<<"\nMedio de transporte: "<<v1.VerMedioTransporte();
	cout<<"\nTiempo de viaje: "<<v1.TiempoDeViaje();
	*/
	
	
	return 0;
}

