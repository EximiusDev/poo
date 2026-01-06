#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Alumno{
private:
	string nombre_al; 
	int DNI; 
	float nota1, nota2, nota3;
	float promedio;
	char condicion;
public:
	Alumno(string nom, int dni, float n1, float n2, float n3) : nombre_al(nom), DNI(dni), nota1(n1), nota2(n2), nota3(n3) {}
	
	tuple<string,int> ver_datos_alumno() const {return make_tuple(nombre_al,DNI);}
	
	tuple<int,char> CalcCondicion(){
		float prom = (nota1 + nota2 + nota3)/3;
		promedio = prom;
		char cond;
		if(prom>=60){
			cond = 'P';
		}else{
			if(prom< 40){
				cond = 'L';
			}else{
				cond = 'R';
			}
		};
		condicion = cond;
	return make_tuple(prom,cond);
	}
	
	~Alumno() {}
};

class Materia{
private:
	string nombre_mat;
	vector<Alumno> v_alumnos;
	string nombre_prof;
public:
	Materia(string nombre, vector<Alumno> v, string nombreprof) : nombre_mat(nombre), v_alumnos(v), nombre_prof(nombreprof) {}

	tuple<int,char> condYprom(int dni){
		int prom;
		char cond;
		string nom;
		int DNI;
		
		for(size_t(i)=0;i<v_alumnos.size();i++) { 
			tie(nom,DNI) = v_alumnos[i].ver_datos_alumno();
			if(DNI == dni){
				tie(prom,cond) = v_alumnos[i].CalcCondicion();
				break;
			}
			break;
		}
		return make_tuple(prom,cond);
	}
	
	int CantRegulares(){
		int cantreg = 0;
		for(size_t(i)=0;i<v_alumnos.size();i++) {
			int prom;
			char cond;
			tie(prom,cond) = v_alumnos[i].CalcCondicion();
			if( cond == 'R') ++cantreg;
		}
		return cantreg;
	}
	int CantLibres(){
		int cantlib = 0;
		for(size_t(i)=0;i<v_alumnos.size();i++) {
			int prom;
			char cond;
			tie(prom,cond) = v_alumnos[i].CalcCondicion();
			if( cond == 'L') ++cantlib;
		}
		return cantlib;
	}
	int CantProm(){
		int cantprom = 0;
		for(size_t(i)=0;i<v_alumnos.size();i++) {
			int prom;
			char cond;
			tie(prom,cond) = v_alumnos[i].CalcCondicion();
			if( cond == 'P') ++cantprom;
		}
		return cantprom;
	}
		
	tuple<int,int,int> Cantidades(){
		int libres, regul, promo;
		libres = CantLibres();
		promo = CantProm();
		regul = CantRegulares();
		
		return make_tuple(libres,regul,promo);
	};
		
	

	~Materia() {}
};

int main() {
	
	vector<Alumno> v_alumnos;
	
	for(size_t(i)=0;i<80;i++) { 
		cout << "Ingrese: " << endl;
		cout << "Nombre Alumno: ";
		string nombre_al; 
		cin >> nombre_al;
		cout << "DNI:";
		int DNI; 
		cin >> DNI;
		cout << "Notas en orden: ";
		float nota1, nota2, nota3;
		cin >> nota1 >> nota2 >> nota3;
		Alumno p(nombre_al,DNI,nota1,nota2,nota3);  // me dí cuenta que acá hay un error pero
		v_alumnos[i] = p ;                          // no llegué a solucionarlo.
	}
	string nombre;
	string nombreprof;
	
	Materia M(nombre, v_alumnos, nombreprof);
	int reg, libres, prom;
	tie(libres,reg,prom) = M.Cantidades();
	cout << "Cantidad de libres: " ;
	cout << libres << endl;
	cout << "Cantidad  Regulares: " ;
	cout << reg << endl;
	cout << "Cantidad Promocionados: ";
	
	cout << prom << endl;
	
	cout << "Ingrese DNI: " << endl;
	int dni; cin >> dni;
	
	int promedio;
	int condicion;
	

	tie(promedio,condicion) = M.condYprom(dni);
	
	cout << "El promedio es: " << promedio;
	cout << " y la condicion: " << condicion << endl;
	
	
	
	
	return 0;
}

