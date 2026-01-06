#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

///2) Programar una clase Animal que tenga un método desplazarse() y otro método tipo(). 

class Animal{
public:
	Animal(string tipo, string especie) : m_tipo(tipo), m_especie(especie) {}
	virtual string desplazarse()=0;
	virtual string tipo()=0;
	string VerTipo(){ return m_tipo; }
	string VerDesplazamiento(){ return m_especie; }
protected:
	string m_tipo;
	string m_especie;
};

/// · 	Programe las clases Mamifero, Ave y Pez, que son hijas de la clase Animal.
/// ·	Los atributos de las clases son el tipo y la especie del animal, cuyos valores deben ser pasados al 
/// 	constructor de la clase base.

/// ·	Además deberá sobreescribir los métodos desplazarse() y tipo(), de tal manera que el primer método devuelve una
///		cadena de texto indicando el tipo de desplazamiento según el tipo: “camina” para el tipo “mamífero”,
///		“vuela” para el tipo “ave” y “nada” para el tipo “pez”. 

class Mamifero : public Animal{
public:
	Mamifero() : Animal(tipo(),desplazarse()) {}
	string desplazarse() override { return "camina"; } 
	string tipo() override { return "mamífero"; }
};

class Ave : public Animal{
public:
	Ave() : Animal(tipo(),desplazarse()) {}
	string desplazarse() override{ return "vuela"; } 
	string tipo() override { return "ave"; }
};

class Pez : public Animal{
public:
	Pez() : Animal(tipo(),desplazarse()) {}
	string desplazarse() override{ return "nada"; } 
	string tipo() override { return "pez"; }
};

/// Escriba un programa cliente que permita modelar un Parque y almacene la información de los animales en un 
/// único arreglo de 30 elementos y luego emita un listado de los mismos describiendo el tipo y la forma de 
/// desplazamiento de cada animal. Finalmente responda: ¿Hay entre las clases algún método virtual puro? ¿Por qué?



/*struct Parque{                     //esto no va. tenes que usar polimorfismo
	vector<Mamifero>mamiferos;
	vector<Ave>aves;
	vector<Pez>peces;
};
*/
int main() {
	
	vector <Animal*> botanico;
	//char tipo;
	int tipo;
     srand(time(0));    //como lo hiciste de leer el tipo esta bien pero lo hago asi para generar mas rapido y probarlo
	//cout << "Ingrese tipo de animal... mamífero(m), ave(a) o pez(p): "; cin >> tipo;
	for(size_t i=0;i<30;i++) {
		tipo=rand()%3;
		if(tipo==0){ Mamifero *nuevo_animal=new Mamifero();  botanico.push_back(nuevo_animal);} //   o    botanico.push_back(new(Mamifero));
		if(tipo==1){ Ave *nuevo_animal=new Ave();   botanico.push_back(nuevo_animal);}          //    o    botanico.push_back(new(Ave)); 
		if(tipo==2){ Pez *nuevo_animal=new Pez();   botanico.push_back(nuevo_animal);}          // o   botanico.push_back(new Pez()); }
		
		//cout << "\nIngrese tipo de animal... mamífero(m), ave(a) o pez(p): "; cin >> tipo;
	}
	
	for(size_t i=0;i<botanico.size();i++) {  
		cout<<botanico[i]->VerTipo()<<"         "<< botanico[i]->VerDesplazamiento()<<endl;
	}

	return 0;
}

