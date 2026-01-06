/*Ejercicio 8.7
Diseñe y programe una clase para manipular datos del tipo que se muestra en el
recuadro. La clase será utilizada para
administrar los pacientes de una clínica.
La clínica está conformada por 6 médicos y cada uno de ellos atiende a un número variable de pacientes.
La clase debe proveer funciones para:
• Incorporar nuevos pacientes indicando el número de médico y el DNI del paciente.
• Listar el nombre de cada médico y los DNI de los pacientes que atiende.
• Eliminar un paciente indicando solamente su DNI.
Utilice la clase desarrollada desde un programa cliente

structFichaMedico{ 
string nombreMedico; 
vector <long> dniPacientes; 
}; 


*/

#include <iostream>
#include <conio.h>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct FichaMedico{ 
	string nomMedico; 
	vector <long> dniPacientes; 
}; 

class Clinica{
private:
	FichaMedico f[6];
	int largo;
public:
	Clinica(){ 	largo =6;
		f[0].nomMedico="Raul Perez";
		f[1].nomMedico="Marcos Sosa";
		f[2].nomMedico="Carlos Lopez";
		f[3].nomMedico="Julio Gomez";
		f[4].nomMedico="Ana Marquez";
		f[5].nomMedico="Miriam Rodriguez";
	}
	//------------------------------------------------
	string mostrarMedicos(){
		stringstream s;	
		for (int x=0; x< largo; x++)
			s<<" Medico "<<x+1<<": "<< f[x].nomMedico <<endl;
		return s.str(); 
	};
	string mostrarPacientes(int nm){
		stringstream s;	
		s<<"Pacientes de "<<f[nm-1].nomMedico<<":  ";
		for (unsigned int x=0; x<f[nm-1].dniPacientes.size(); x++)
			s<< (f[nm-1].dniPacientes[x]) <<", ";
		return s.str(); 
	}

	void modMedico(int nm, string nomb){
			f[nm-1].nomMedico=nomb;
	}

	FichaMedico verMedico(int nm){
		return 	f[nm-1];
	}

	void agrPaciente(int nm, long num_dni){
			f[nm-1].dniPacientes.push_back(num_dni);//agrego dni al final
	}

	void modPaciente(int nm, long np, long dnip){//Numero de medico, dniP viejo, dniP nuevo
		vector <long>::iterator it,ini,fin;
		ini=f[nm-1].dniPacientes.begin();
		fin=f[nm-1].dniPacientes.end();
		it =  find( ini,fin,np);
		
		if (it != (f[nm-1]).dniPacientes.end())
			*it= dnip;//modifico valor
	}

	void elimPaciente(int nm, long dnip){//Numero de medico,  dniP nuevo
		vector <long>::iterator it,ini,fin;
		ini=f[nm-1].dniPacientes.begin();
		fin=f[nm-1].dniPacientes.end();
		it =  find( ini,fin,dnip);
		if (it != (f[nm-1]).dniPacientes.end())
			(f[nm-1]).dniPacientes.erase(it);
	}
	

};

//funcion que devuelve una cadena con el texto del menu
string menu(){
	stringstream s;
	s<<"           MENU DE OPCIONES\n";
	s<<"1 - LISTADO DE MEDICOS.\n";
	s<<"2 - MODIFICACIONES DATOS DE MEDICOS.\n";
	s<<"3 - LISTADO DE PACIENTES POR MEDICO.\n";
	s<<"4 - ALTA DE PACIENTES.\n";
	s<<"5 - MODIFICACIONES DE PACIENTES.\n";
	s<<"6 - ELIMINAR PACIENTE.\n";
	s<<"0 - SALIR\n";
	s<<"Ingrese su opcion:  ";
	return s.str();
}

//**********************************************************	

int main(int argc, char *argv[]) {
	Clinica C;
	int nummed;
	char op;
	while (op!='0'){
		system("cls");
		cout<<menu();
		cin>>op;
		
		switch (op){
		case '1':{cout<<"\nLista de medicos\n";
			cout<<C.mostrarMedicos();
			break;}
		case '2':{
			cout<<"\nIngrese numero de medico (1 - 6): ";
			cin>>nummed;
			cout<<"Medico ("<<nummed<<"): "<<C.verMedico(nummed).nomMedico<<endl;
			cout<<"\nReingrese el nombre del medico: ";
			string nombre;
			cin.ignore();
			getline(cin,nombre);
			C.modMedico(nummed, nombre);
			break;}
		case '3':{cout<<"\nIngrese numero de medico (1 - 6): ";
			cin>>nummed;
			cout<<"Medico ("<<nummed<<"): "<<C.verMedico(nummed).nomMedico<<endl;
			cout<<C.mostrarPacientes(nummed);
			break;}
		case '4':{cout<<"\nIngrese numero de medico (1 - 6): ";
			cin>>nummed;
			cout<<"Medico ("<<nummed<<"): "<<C.verMedico(nummed).nomMedico<<endl;
			cout<<"Ingrese el DNI del paciente: ";
			long num_dni;
			cin>>num_dni;
			C.agrPaciente(nummed, num_dni);
			break;}
		case '5':{long dniv,dnin;
			cout<<"\nIngrese numero de medico (1 - 6): ";
			cin>>nummed;
			cout<<C.mostrarPacientes(nummed);
			cout<<"\nIngrese el DNI viejo del paciente: ";
			cin>>dniv;
			cout<<"Ingrese el DNI nuevo del paciente: ";
			cin>>dnin;
			C.modPaciente(nummed,dniv,dnin);
			break;}
		case '6':{cout<<"\nIngrese numero de medico (1 - 6): ";
			cin>>nummed;
			cout<<C.mostrarPacientes(nummed);
			cout<<"\nIngrese el DNI del paciente: ";
			long num_dni;
			cin>>num_dni;
			C.elimPaciente(nummed, num_dni);
			break;}
        		
		};//del switch
		cout<<endl;
		system("pause");
	};//del while
	
	return 0;
}
