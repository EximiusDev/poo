/*
Ejercicio  1  (35pts)  Se  dispone  de  un  archivo  binario  "Pacientes.dat".  El  archivo  fue  creado  por  un  programa  C ++  
usando  la  expresión:  archi.write (reinterpret_cast <char *> (& x), sizeof (x));  donde  x  es  de  tipo  Ficha,  
siendo  Ficha  un  struct  que  contiene  los  datos  de  cada  paciente:  DNI,  nombre,  apellido,  dirección,  teléfono, obra  social.  
Proponga  una  posible  definición  del  struct  Ficha  e  implemente  una  función  verificarDatos (…)  
que  llegaron  como  parámetros  el  DNI  de  un  paciente,  un  nombre  y  un  apellido. 
La  función  debe  buscarlo  en  el  archivo  (por  su  DNI)  y  verificar  si  el  nombre  y  el  apellido  coinciden. 
Si  ENCUENTRA  al  Paciente  en  el  archivo  Y  los  Datos  no  coinciden,  Debe  corregirlos  (Modificar  nombre  y  un apellido).  
Además  debe  retornar  un  entero  con  su  posición  en  la  lista  de  pacientes  (si  es  el  1ro  de  la  lista,  el  2do,  3ro,  etc).  
Si  el  DNI  no  ESTABA  en  la lista,  debe  retornar  -1. 
Para  implementar  la  función f,  sin  Debe  USAR  ningún  contenedor  (lista,  vector,  etc.)  
ni  Arreglo  en  memoria  para  cargar  todos  los  Datos,  Sino  Que  Debe  Operar  Directamente  Sobre  el  archivo.
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Ficha {
	int dniT,telefonoT;
	char nombreT [15];
	char apellidoT[20];
	char direccionT[20];
	char obraSocialT[20];
	
};
struct aux{
	string nombre,apellido;
};
int verificarDatos(int dni, string nombre, string apellido){
	fstream archi("Pacientes.dat",ios::binary|ios::in|ios::out);
	int n = archi.tellg()/sizeof(Ficha);
	archi.seekg(0);
	Ficha x;
	aux str;
	for(int i=0;i<n;i++) { 
		archi.read(reinterpret_cast<char*>(&x),sizeof(x));
		str.nombre = x.nombreT;
		str.apellido = x.apellidoT;
		if(x.dniT == dni){
			if(str.nombre != nombre or str.apellido != apellido){
				str.nombre = nombre;
				str.apellido = apellido;
				strcpy(x.nombreT,str.nombre.c_str());
				strcpy(x.apellidoT,str.apellido.c_str());
				archi.seekp(-sizeof(Ficha),ios::cur);
				archi.write(reinterpret_cast<char*>(&x),sizeof(x));
				
			}
			return i+1;
		}
		
	}
	return -1;
}


int main() {
	
	return 0;
}

