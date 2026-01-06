/* Ejercicio 7
Una fábrica de Tanques los hace de forma de Cilindro o de Esfera, en ambos
envases debemos rotular el volumen en m3 y el peso en kilogramos.
Modele una clase base Tanque con un constructor que reciba el peso, un método
para consultar el peso, y un método virtual puro para obtener el volumen.
Modele la clase hija Cilindro que se construirá a partir de los argumentos
adicionales radio y altura, cuya fórmula de volumen es: área de la base x altura,
donde el área de la base se calcula como PI*radio^2; y otra clase hija Esfera con el
radio como argumento adicional, cuya fórmula de volumen es: 4/3*PI*radio^3. En el
programa principal debe usar un único puntero de tipo Tanque para crear primero
un Cilindro y mostrar su volúmen, y luego una Esfera y también mostrar su
volúmen.
*/

#include <iostream>
using namespace std;

class Tanque{
	float m_volumen;
	float m_peso;
public:
	Tanque(float peso){ /// Tanque(float peso): m_peso(peso){} /// forma alternativa
		m_peso = peso;
	};
	virtual float VerPeso(){return m_peso;}
	virtual float VerVol()=0; //{return m_volumen;} /// metodo virtual puro
	virtual ~Tanque(){} ///  ///destructor de la clase base (se usa cuando se hace polimorifismo)
};

class Cilindro:public Tanque{
	float m_radio, m_altura;
public:
	Cilindro(float pe, float radio, float altura):Tanque(pe){ /// Uso herencia 
		m_radio = radio;
		m_altura = altura;
	}
	float VerVol()override; /// polimorfismo de un virtual puro (override es opcional)
};

class Esfera:public Tanque{
	float m_rad;
public:
	Esfera(float pe, float rad):Tanque(pe),m_rad(rad){ /// otra forma de incializar m_rad = rad;
		
	}
	float VerVol()override{
		//4/3*PI*radio^3
		return 3.14* m_rad * m_rad * m_rad * (3.0/4.0);
	}
};

float Cilindro::VerVol(){
	//área de la base(=PI*radio^2) x altura
	return (3.14* m_radio * m_radio) * m_altura;
}


int main() {
	float peso = 1;
	float radio = 1;
	float altura = 1;
	
	Tanque* Cilin1; /// Creo un puntero de tipo Tanque(clase base que es virtual)
	Cilin1 = new Cilindro(peso, radio, altura); // Le asigno al puntero de Tanque una memoria dinamica de tipo Cilindro
	Tanque* Esf1 = new Esfera(5, 2); 
	
	cout<<endl;
	cout<<Cilin1->VerVol()<<endl;
	cout<<endl;
	cout<<Esf1->VerVol()<<endl;
	
	
	delete Cilin1; // para hacerlo bien hay que hacer el destructor a la base
	delete Esf1;
	
	
	return 0;
}

