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
	vector<FichaMedico> f;
public:
	Clinica(){
	    FichaMedico aux;
		aux.nomMedico="Raul Perez";aux.dniPacientes.clear(); f.push_back(aux);
		aux.nomMedico="Marcos Sosa";aux.dniPacientes.clear(); f.push_back(aux);
		aux.nomMedico="Carlos Lopez";aux.dniPacientes.clear(); f.push_back(aux);
		aux.nomMedico="Julio Gomez";aux.dniPacientes.clear(); f.push_back(aux);
		aux.nomMedico="Ana Marquez";aux.dniPacientes.clear(); f.push_back(aux);
		aux.nomMedico="Miriam Rodriguez";aux.dniPacientes.clear(); f.push_back(aux);
	}
	//------------------------------------------------
	string mostrarMedicos(){
		stringstream s;	
		for(size_t i=0;i<f.size();i++) 
			s<<" Medico "<<i+1<<": "<< f[i].nomMedico <<endl;
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
		/*
	void elimPaciente(long dnip){//Numero de medico,  dniP nuevo
		for(size_t i=0;i<f.size();i++) { 
			vector <long>::iterator it,ini,fin;    //puedo recorrer en todos los medicoa
			ini=f[nm-1].dniPacientes.begin();
			fin=f[nm-1].dniPacientes.end();
			it =  find( ini,fin,dnip);
			if (it != (f[nm-1]).dniPacientes.end())
				(f[nm-1]).dniPacientes.erase(it);
		
		}
	}*/
		
		vector <long>::iterator it,ini,fin;   
		ini=f[nm-1].dniPacientes.begin();
		fin=f[nm-1].dniPacientes.end();
		it =  find( ini,fin,dnip);
		if (it != (f[nm-1]).dniPacientes.end())
			(f[nm-1]).dniPacientes.erase(it);
	
	//	auto it=remove(f[nm-1].dniPacientes.begin(),f[nm-1].dniPacientes.end(),dnip);  //borraria varios ocurrencias
	//	f[nm-1].dniPacientes.erase(it,f[nm-1].dniPacientes.end());                     //tengo que redimencionar....
		
	}
	
	
	int CantMedicos(){return f.size();}
	
	int BuscarMedico(string n){
		for(size_t i=0;i<f.size();i++) 
			if( f[i].nomMedico==n ) return i;
	return -1;
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
			
			/*string nm;
			cout<<"\nIngrese mombre de medico: ";
			cin>>nm;
			nummed=C.BuscarMedico(nm);
			*/
			
			
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
