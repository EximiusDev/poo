/*
Ejercicio 2 (35pts)
a) Diseñe una clase para representar un viaje que guarde y permita consultar la siguiente información: ciudades de origen y
destino, medio de transporte (un string, por ej "avión”), y distancia (en kms).
b) Implemente 3 clases que representen viajes en tres medios de transportes específicos: en avión, en auto y en colectivo.
Cada una de estas clases debe permitir obtener el tiempo del viaje de la siguiente forma:
- en auto: t = distancia/110 + .5*(distancia%110) // se viaja a 110km/h, con un descanso de 30m cada 2h
- en avión: t = 2+distancia/900 // se viaja a 900km/h, pero hay que estar 2 horas antes en el aeropuerto
- en colectivo: t = distancia/90 // se viaja a 90km/h, sin esperas antes ni paradas
c) Implemente una función que reciba un vector de viajes y retorne el tiempo total (la suma).
d) Escriba un programa cliente que genere un vector con 3 viajes: de Rosario a Paraná en auto (200km), de Paraná a Buenos
Aires en avión (400km), y de Buenos Aires a Rosario en colectivo (320km). El programa debe usar la función para obtener
y luego mostrar el tiempo total.
*/

#include <iostream>
#include <vector>
using namespace std;

class Viaje{
	string origen, destino, transporte;
	int distancia; ///(en kms).
	float t=10; /// duracion
public:
	Viaje(string origen,string destino,string transporte, int distancia):origen(origen),destino(destino),transporte(transporte), distancia(distancia){}
	string VerOrigen(){return origen;}
	string VerDestino(){return destino;}
	string VerTransporte(){return transporte;}
	int VerDistancia(){return distancia;}
	void CambiarDuracion(int t){this->t = t;}
	virtual float VerDuracion(){return t;}
	void Prueba(){cout<<"Prueba metodo base"<<endl;}
};
class Auto: public Viaje{
	/* ///YA ESTA EN LA BASE
	string origen, destino, transporte;
	int distancia; ///(en kms).
	int t; /// duracion
	*/
	float t;
public:
	Auto(string origen,string destino, int distancia):Viaje( origen, destino, "Auto", distancia){
		//this->origen = origen; /// NO VA PORQUE YA LO HAGO EN LA BASE
		t = VerDistancia()/110 + .5*(VerDistancia()%110);
		CambiarDuracion(t);
	}
	float VerDuracion() override{
		///int t = VerDistancia()/110 + .5*(VerDistancia()%110);
		///return t;
		return t;
	}// t = distancia/110 + .5*(distancia%110)
	
};
class Avion: public Viaje{
	float t;
public:
	Avion(string origen,string destino, int distancia):Viaje( origen, destino, "Avion", distancia){
		t = 2 + VerDistancia()/900.0;
		CambiarDuracion(t);
	}
	float VerDuracion() override{
		///int t = 2 + VerDistancia()/900;
		///return t;
		return t;
	}	// t = 2+distancia/900
};
class Colectivo: public Viaje{
	float t;
public:
	Colectivo(string origen,string destino, int distancia):Viaje( origen, destino, "Avion", distancia){
		t = VerDistancia()/90.0;
		CambiarDuracion(t);
	}
	float VerDuracion() override{
		///int t = VerDistancia()/90;
		///return t;
		return t;
	}	// t = distancia/90
};

float TiempoTotal(vector<Viaje>Viajes){
	float suma=0;
	for(unsigned int i=0;i<Viajes.size();i++) { 
		suma += Viajes[i].VerDuracion();
	}
	return suma;
}

int main() {
	Viaje V1( "Rosario","Paraná","auto", 200);
	Auto Au1( "Rosario","Paraná", 200);
	Avion Av1( "Parana","Buenos Aires", 400);
	Colectivo Co1( "Buenos Aires","Rosario", 320);
	
	cout<<Au1.VerDuracion()<<endl;
	cout<<Av1.VerDuracion()<<endl;
	cout<<Co1.VerDuracion()<<endl;
	
	vector<Viaje>Viajes;
	//Viajes.push_back(V1);
	//Viajes.push_back(V1);
	Viajes.push_back(Au1);
	Viajes.push_back(Av1);
	Viajes.push_back(Co1);
	
	float tt = TiempoTotal(Viajes);
	cout<<tt;
	
	return 0;
}

