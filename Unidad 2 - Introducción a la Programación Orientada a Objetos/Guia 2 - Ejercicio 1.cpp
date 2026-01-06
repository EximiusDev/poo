/* Ejercicio 1
Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el
volumen del cuerpo conociendo el radio de su base y la altura del mismo.
a. Cree los métodos AsignarDatos(...) y ObtenerVolumen(...) para asignar los
datos del problema y obtener el volumen del cuerpo.
b. Escriba un programa cliente que utilice dicha clase. Defina 2 instancias de
Cilindro llamadas c1 y c2. El objeto c1 debe utilizar datos ingresados por el
usuario, mientras que para c2 utilice 5.3 cm y 10.2 cm para el radio y la
altura respectivamente.
c. Agregue un constructor a la clase Cilindro que reciba 2 parámetros para
inicializar el radio y la altura. Luego intente compilar nuevamente el
programa. ¿Puede explicar por qué se produce un error? Proponga una
solución.
*/

#include <iostream>
using namespace std;

class Cilindro{
	float m_rad, m_alt;
public:
	void AsignarDatos(float rad, float alt){ m_rad = rad; m_alt = alt; }
	float ObtenerVolumen(){ return 3.14 * m_rad * m_rad * m_alt; }
	
	Cilindro(float  = 0 , float  = 0); /// Constructor
	///Cilindro(float  , float  ); /// Constructor
	///Cilindro(){}
};

int main() {
	float radio, altura;
	
	cout<<"Ingrese el radio y la altura del Cilindro 1:"<<endl;
	radio = 1;
	altura = 10;
	cin>>radio>>altura;
	
	Cilindro C1; /// Constructor por defecto
	Cilindro C2( 0 , 0 ); /// Uso el Contructor del objeto (creado)
	C1.AsignarDatos( radio , altura );
	cout<<"vol de prueba: "<<C2.ObtenerVolumen()<<endl;
	C2.AsignarDatos( 5.3 , 10.2 ); // funciona bien
	
	cout<<"Volumen del Cilindro 1: "<<C1.ObtenerVolumen()<<endl;
	cout<<"Volumen del Cilindro 2: "<<C2.ObtenerVolumen()<<endl;
	
	return 0;
}

///Cilindro::Cilindro(float radio, float altura){
Cilindro::Cilindro(float radio, float altura){

	m_rad = radio;
	m_alt = altura;
}
