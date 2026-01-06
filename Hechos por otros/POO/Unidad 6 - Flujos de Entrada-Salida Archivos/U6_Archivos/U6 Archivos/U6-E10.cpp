//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 10
/*clase Persona para representar a una persona a partir de su nombre,  
apellido y fecha de nacimiento con día, mes y año. Diseñe una clase llamada  
RecursosHumanos  que permita manejar los datos de un grupo de personas. La  
clase debe poseer métodos para: 
a)  Guardar los datos de las personas en un archivo binario. 
b)  Cargar los datos de las personas desde un archivo binario. 
c)  Agregar una persona. 
d)   Eliminar una persona a partir de su nombre o apellido. 
e)   Indicar la cantidad de personas en la base de datos. 
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef struct{
	char apeynomb[50];
	int diaNac, mesNac, anioNac;
} persona;

class recursosHumanos{
	char nombreArchi[50];//Aqui se guardará el nombre físico del archivo
	persona p[100];//Este arreglo cargará todos los registros del disco a memoria
	int cantidad;//Contador de registros
public:
	recursosHumanos(string nArch){strcpy(nombreArchi,nArch.c_str());};//Constructor
	void carga();//Metodo que permitira la carga de los registros al vecctor
	persona buscar(string cad);//Buscara el nombre (cad) en el arreglo
	void guardar();//Permitira guardar el arreglo en disco;
	bool eliminar(string cad);//Elimina un nombre del arreglo y guarda en disco el vector midificado
	void agregar(persona per);//Agrega un registro en el arreglo y en el archivo en disco.
	int ver_cantidad(){return cantidad;};//Devuelve la cantidad de registro o posiciones del arreglo
	char * ver_apeynomb(int n){return p[n].apeynomb;};//Devuelve el nombre de la persona en la posicion n
	int ver_diaNac(int n){return p[n].diaNac;};//Devuelve el dia de nacimiento en la posicion n.
	int ver_mesNac(int n){return p[n].mesNac;};//Devuelve el mes de nacimiento en la posicion n.
	int ver_anioNac(int n){return p[n].anioNac;};//Devuelve el anio de nacimiento en la posicion n.
};
void recursosHumanos::carga(){
	fstream archi_in(nombreArchi,ios::binary|ios::in);//Declaro el objeto archi_in para leer datos del archivo
	if(!archi_in.is_open()){//Si no se abrio informo del error
		cout<<"Error en apertura de archivo"<<endl;
		//Intento crearlo por si el error se genero porque no existia
		//cout<<"Se creara un archivo vacio"<<endl;
		getchar();
		fstream archi(nombreArchi,ios::binary|ios::in|ios::out|ios::trunc);
		archi.clear();//Limpio
		archi.close();//Cierro el archivo
	}else{
		cantidad=0;//Pongo el contador de registors en 0
		archi_in.seekg(0,ios::end);//Voy al final del archivo
		int total = archi_in.tellg()/sizeof(persona);//Calculo el tamaño
		archi_in.seekg(0,ios::beg);//Vuelvo al principio
		while(cantidad < total){//leo todos los registros y los cargo en el arreglo
			archi_in.read(reinterpret_cast<char*>(&p[cantidad]), sizeof(persona));
			//cout<<cantidad<<"- "<<p[cantidad].apeynomb<<endl;//Voy mostrando lo que leo
			cantidad++;//Incremento en 1 la cantidad
		}
		archi_in.close();//Cierro el archivo
	}
}
persona recursosHumanos::buscar(string cad){
	persona aux;
	int c=0;
	while(c<cantidad){//Mientras c < cantidad no llega al final del arreglo
		if(strcmp(p[c].apeynomb,cad.c_str())==0){//Compara nombres y si lo encuentra
			aux= p[c];//Devuelvo el struct completo
			return aux;
		}
		c++;//Incrementa el contador de registros
	}//Si pasa es porque no lo encontro.
	strcpy(aux.apeynomb,"No Encontrado");//Asigno el mensaje y devuelvo el struct
	return aux;
}

void recursosHumanos::guardar(){
	//Abro el archivo para sobreescribirlo con el arreglo de struct
	fstream archi_out(nombreArchi,ios::binary|ios::out|ios::trunc);
	if(!archi_out.is_open()){
		cout<<"Error en apertura de archivo"<<endl;
		//getchar();
	}else{
		int c=0;
		archi_out.seekg(0,ios::beg);//Vuelvo al principio
		while(c< cantidad){//escribo todos los registros del arreglo
			archi_out.write(reinterpret_cast<char*>(&p[c]), sizeof(persona));
			//cout<<c<<"- "<<p[c].apeynomb<<endl;
			c++;//incremento el contador de registros grabados
		}
		archi_out.close();//Cierro el archivo
	}
}

bool recursosHumanos::eliminar(string cad){
	int c=0;//contador en cero
	while(c<cantidad){//Mientras no llegue al último
		if(strcmp(p[c].apeynomb,cad.c_str())==0){
			break;//Si lo encuentra sale del while
		}
		c++;//Incremento el contador
	}//fin del while
	if (c<cantidad){//Si el contador no llego al final, lo encontro.
		for(int k= cantidad-1; k > c;k--){
			p[k-1]=p[k];//Corro todos los registros 1 lugar para arriba
		} 
		cantidad--;//Decremento cantidad en 1
		guardar();//Guardo en disco el arreglo modificado		
	}
	return 0;
}
void recursosHumanos::agregar(persona per){
	fstream archi_out(nombreArchi,ios::binary|ios::out|ios::ate);
	if(!archi_out.is_open()){
		cout<<"Error en apertura de archivo"<<endl;
		//getchar();
	}else{
		//archi_out.seekp(0,ios::end);//al final
		archi_out.write(reinterpret_cast<char*>(&per), sizeof(per));
		p[cantidad]= per;
		cantidad++;
		}
		archi_out.close();
}

int menu(){
	int op;
	cout<<"Recursos Humanos"<<endl;
	cout<<"1) Salir"<<endl;
	cout<<"2) Ver archivo"<<endl;
	cout<<"3) Buscar Persona"<<endl;
	cout<<"4) Guardar datos en Archivo"<<endl;
	cout<<"5) Eliminar Persona"<<endl;
	cout<<"6) Ver cantidad de personas en el archivo"<<endl;
	cout<<"7) Agregar Persona"<<endl;
	cout<<endl<<"Elija una Opcion: ";cin>>op;
	return op;
}

int main(int argc, char *argv[]) {
recursosHumanos A("C:/POO/archivo.bin");
A.carga();
int opcion=0;
while(opcion != 1){
	opcion = menu();
	switch (opcion){
	case 1: {A.guardar(); return 0;};
		break;
	case 2:{int c=0;
		for(c=0;c < A.ver_cantidad(); c++){
			cout<<"Nombre : "<<A.ver_apeynomb(c)<<", Fecha Nac: "
				<<A.ver_diaNac(c)<<"/"<<A.ver_mesNac(c)<<"/"<<A.ver_anioNac(c)<<endl;
			}
		};break;
	case 3:{persona dato,encontro;
		cout<<"Ingrese el nombre y apellido a buscar: "; cin>>dato.apeynomb;
		encontro= A.buscar(dato.apeynomb);
		if(strcmp(encontro.apeynomb, "No Encontrado") == 0){
			cout<<"Nombre no encontrado."<<endl;
		}else{
			cout<<"Nombre: "<<encontro.apeynomb<<endl;
			cout<<"Fecha de Nacimiento: "<<encontro.diaNac<<"/"<<encontro.mesNac
				<<"/"<<encontro.anioNac<<endl;
			};break;
	
	}//switch
	case 4:{A.guardar();};break;
	case 5:{persona dato,encontro;
		cout<<"Ingrese el nombre y apellido a Eliminar: "; 
		cin.ignore();gets(dato.apeynomb);
		encontro= A.buscar(dato.apeynomb);
		if(strcmp(encontro.apeynomb,"No Encontrado")== 0){
			cout<<"Nombre no encontrado."<<endl;
		}else{
			cout<<"Nombre: "<<encontro.apeynomb<<endl;
			cout<<"Fecha de Nacimiento: "<<encontro.diaNac<<"/"<<encontro.mesNac
				<<"/"<<encontro.anioNac<<endl;
			A.eliminar(encontro.apeynomb);
			cout<<"ELIMINADO"<<endl;
		}};break;
	case 6:{cout<<"Cantidad de personas en al archivo: "<<A.ver_cantidad()<<endl;
		};break;
	case 7:{ persona dato;
			cin.ignore();
			cout<<"Ingrese Apellido y Nombre: "; cin.getline(dato.apeynomb,50);
			cout<<"Ingrese dia de Naciminento: "; cin>>dato.diaNac;
			cout<<"Ingrese mes de Naciminento: "; cin>>dato.mesNac;
			cout<<"Ingrese Anio de Naciminento: "; cin>>dato.anioNac;
			A.agregar(dato);};break;
	}//del switch
}//del while
return 0;
}
