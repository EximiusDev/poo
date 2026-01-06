#include <iostream>
#include <vector>
using namespace std;

class Empleado{
	int dni;
	string nombre;
	int sueldo_basico;
public:
	Empleado(int d, string nom, int suel):dni(d),nombre(nom),sueldo_basico(suel){}
	virtual int MontoACobrar()=0;
	virtual ~Empleado(){} ///destructor de la clase base (se usa cuando se hace polimorifismo)
	int Versueldo_basico(){return sueldo_basico;}
};

class Contructor:public Empleado{
	int hsExtra, mts2;
public:
	Contructor(int d, string nom, int suel, int hs,int  m2):Empleado(d,nom,suel){
		hsExtra = hs;
		mts2 = m2;
	}
	int MontoACobrar()override; /// override no es obligatorio pero puede evitar problemas
};
class Instalador:public Empleado{
	int dias_trab;
public:
	Instalador(int d, string nom, int suel, int dias):Empleado(d,nom,suel),dias_trab(dias){}
	int MontoACobrar()override;
};
class Yesero:public Empleado{
	int metros2;
public:
	Yesero(int d, string nom, int suel, int m2):Empleado(d,nom,suel),metros2(m2){}
	int MontoACobrar()override;
};

int Contructor::MontoACobrar(){
	return Versueldo_basico() + 300* hsExtra + 100*mts2;
}
int Instalador::MontoACobrar(){
	return Versueldo_basico() + 300* dias_trab;
}

int Yesero::MontoACobrar(){
	return Versueldo_basico() + 200*metros2;
}

int TotalAPagar(vector<Empleado*> x){ /// La funcion tiene como atributo un vector de Punteros de tipo Empleado (el vector con todos los Empleados)
	/// se trabaja con un puntero de tipo Empleado porque asi se hace polimorfismo con clase virtual pura
	int suma =0;
	int n=x.size();
	for(int i=0;i<n;i++) { 
		//suma =+ (*x[i]).MontoACobrar(); /// accedo al metodo MontoACobrar del elemento del vector, que es un objeto
		suma =+ x[i]->MontoACobrar(); /// es equivalente al anterior
	}
	return suma;
}

int main() {
	vector<Empleado*> v; // Creo un venctor de punteros de tipo Empledo (clase base vitual pura)
	v.push_back(new Contructor(12,"ss",100,10,30)); /// Agrego un elemnto (que es de tipo de las distintas hijas de la base) de forma dinamica porque es un puntero (ver polimorfismo)
	v.push_back(new Yesero(12,"ss",200,20));  /// como es un vector los elementos se asignas con push back, agregando los elemntos de forma dinamica (con new)
	v.push_back(new Instalador(12,"ss",200,3)); // para cada hija de Empleado se asigna sus respectivos parametros (para el constructor de la clase), con lo necesario para la base y la hija 
	
	
	for(unsigned int i=0;i<v.size();i++){
		cout<<v[i]->MontoACobrar()<<endl;
	}
	int suma = TotalAPagar(v);
	cout<<suma<<endl;
	
	
	for(unsigned int i=0;i<v.size();i++) { /// tengo que hacer un for para borrar todos los elementos del vector
		///(los elementos del vector son punteros con una asignacion de espacio dinamico para cada elemnto, por lo que cada uno debe tener un delete)
		delete v[i]; // hago delete a cada elemnto del vector (son punteros con memoria dinamica)
		// No hay que hacer delete []v porque el vector v (de tipo puntero de tipo Empleado) no es un vector dinamico, sus elementos si son dinamicos
	}
	
	return 0;
}

