/*Ej 3 (pts) Una empresa constructora tiene empleados para diferentes tipos de tareas: constructor, instalador y
yesero. Los datos de cada empleado son el dni, nombre, apellido y sueldo básico. Declare las clases
Empleado, Constructor, Instalador y Yesero. Las clases deben tener un método MontoACobrar() para
calcular la remuneración mensual del trabajador. Puedes codificar todos los métodos adicionales que
consideres necesarios. Los datos adicionales para el constructor son la cantidad de horas extras y los metros
cubiertos, para el instalador son los días trabajados y para el yesero los metros cuadrados de revestimiento
hechos. De acuerdo a la información, el cálculo los montos a cobrar correspondientes son:
Constructor = sueldo básico + 300 * horas extras + 100 * metros cubiertos
Instalador = sueldo básico + días trabajados * 3000
Yesero = sueldo básico + 200 * metros cuadrados
Codifique un programa cliente que tenga un único vector de 20 empleados (Constructor, Instalador y Yesero)
y permita obtener el total de dinero que la administración deberá contar para pagarles el sueldo en un mes.
*/

#include <iostream>
#include <vector>
using namespace std;
class Empleado{
	int dni, sb;
	string nya;
public:
	Empleado(int d, string n, int s):dni(d),nya(n),sb(s){}
	virtual int MontoACobrar()=0;
	int VerSB(){return sb;}	
	virtual ~Empleado(){}
};

class Constructor: public Empleado{
	int horase, m2;
public:
	Constructor(int d, string n, int s, int h, int m):
		Empleado(d,n,s), horase(h), m2(m){}
	int MontoACobrar() override;
};

class Instalador: public Empleado{
	int dias;
public:
	Instalador(int d, string n, int s, int di):Empleado(d,n,s), dias(di){}
	int MontoACobrar() override;
};
class Yesero: public Empleado{
	int m2;
public:
	Yesero(int d, string n, int s, int m):Empleado(d,n,s), m2(m){}
	int MontoACobrar() override;
};

int Constructor::MontoACobrar(){
	return VerSB() + 300 * horase + 100 * m2;
}
int Instalador::MontoACobrar(){
	return VerSB() + 3000 * dias;
}
int Yesero::MontoACobrar(){
	return VerSB() + 200 * m2;
}

int TotalAPagar(vector<Empleado*> x){                         //en lugar de hacer todo en el main como pide el enunciado, hago una funcion para probar
	int s=0;
	for(int i=0;i<x.size();i++) { 
		s += x[i]->MontoACobrar();     //   *(x+i).MontoACobrar()
	}
	return s;
}

int main(int argc, char *argv[]) {
	vector<Empleado*> v;
	v.push_back(new Constructor(12,"ss",100,10,30));
	v.push_back(new Constructor(12,"strts",100,10,30));
	v.push_back(new Constructor(12,"ssdgsdgs",100,10,30));
	v.push_back(new Constructor(12,"ssdss",100,10,30));
	v.push_back(new Constructor(12,"smmhmgs",100,10,30));
	v.push_back(new Yesero(12,"wess",200,30));
	v.push_back(new Yesero(12,"sskhj",200,30));
	v.push_back(new Yesero(12,"sgfs",200,30));
	v.push_back(new Instalador(12,"ssfgh",200,3));
	v.push_back(new Instalador(12,"sfghs",200,3));
	v.push_back(new Instalador(12,"svbns",200,3));
	cout<<TotalAPagar(v);
	
	for(int i=0;i<v.size();i++) { 
		delete v[i];
	}	
	return 0;
}

