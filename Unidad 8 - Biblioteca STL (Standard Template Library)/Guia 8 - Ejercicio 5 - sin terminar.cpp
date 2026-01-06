#include <iostream>
#include <vector>
using namespace std;

struct FichaMedico{
	string nombreMedico;
	vector <long> dniPacientes;
};

class Clinica{
	FichaMedico fm[6];
public:
	Clinica(vector <string> nm){
		for(int i=0;i<6;i++) { 
			fm[i].nombreMedico = nm[i];
		}
	}
	void AltaPaciente(int m, long d){
		fm[m].dniPacientes.push_back(d);
	}
		int CantPacientes(int m){return fm[m].dniPacientes.size();	}
};


int main() {
	vector <string> med = {
		
	};
	
	return 0;
}

