#include <iostream>
using namespace std;
class Persona{
private:
	string m_apenom;
 	int m_dni,m_dn,m_mn,m_an;
	char m_ec;
public:
	Persona(string aapenom,int adni, int adn, int amn, int aan, char aec){
		m_apenom=aapenom; m_dni=adni; m_dn=adn; m_mn=amn; m_an=aan; m_ec=aec;
	} 
	string VerApenom(){return m_apenom;}
	int Edad(int ada, int ama, int aaa);
	int VerDni(){return m_dni;}
	int verDn(){return m_dn;}
	int verMn(){return m_mn;}
	int verAn(){return m_an;}
	char verEc(){return m_ec;}
};

class Alumno: public Persona{
private:
	float m_prom;
	int m_cantma;
public:
	Alumno(string aapenom,int adni, int adn, int amn, int aan, char aec,float aprom, int acantma):
		Persona(aapenom,adni,adn,amn,aan,aec), m_prom(aprom), m_cantma(acantma){}
	float VerProm(){return m_prom;}
	int VerCantMA(){return m_cantma;}
	float MeritoAcademico(){return m_prom*m_cantma;}
};

class Docente: public Persona{
private:
	int m_di, m_mi, m_ai;
public:
	Docente(string aapenom,int adni, int adn, int amn, int aan, char aec,int adi,int ami, int aai):
		Persona(aapenom,adni,adn,amn,aan,aec), m_di(adi), m_mi(ami), m_ai(aai){}
	int Antiguedad(int ada, int ama, int aaa);
};

int Persona::Edad(int ada, int ama, int aaa){
	return ((aaa*10000+ama*100+ada)-(m_an*10000+m_mn*100+m_dn))/10000;
}

int Docente::Antiguedad(int ada, int ama, int aaa){
	return ((aaa*10000+ama*100+ada)-(m_ai*10000+m_mi*100+m_di))/10000;
}



int main(int argc, char *argv[]) {
	Alumno a1("Juan Perez",30202020, 14,01,1987, 'S',7.65,15);
	Alumno a2("Julio Taborda",40123456, 24,11,1999, 'C',8.6,5);
	Docente d("Ana Lopez", 20056768,13,1,1968,'C',1,7,1995);
	
	cout<<a1.VerApenom()<<"   "<<a1.VerDni()<<"     "<<a1.verDn()<<"/"<<a1.verMn()<<"/"<<a1.verAn()<<endl;
	cout<<"Edad:  "<<a1.Edad(18,9,2020)<<endl;
	cout<<"Mat aprobadas: "<<a1.VerCantMA()<<"    promedio: "<<a1.VerProm()<<"    Merito: "<<a1.MeritoAcademico()<<endl;
	cout<<endl;
	cout<<a2.VerApenom()<<"   "<<a2.VerDni()<<"     "<<a2.verDn()<<"/"<<a2.verMn()<<"/"<<a2.verAn()<<endl;
	cout<<"Edad:  "<<a2.Edad(18,9,2020)<<endl;
	cout<<"Mat aprobadas: "<<a2.VerCantMA()<<"    promedio: "<<a2.VerProm()<<"    Merito: "<<a2.MeritoAcademico()<<endl;
	cout<<endl;
	cout<<d.VerApenom()<<"   "<<d.VerDni()<<"   "<<d.verDn()<<"/"<<d.verMn()<<"/"<<d.verAn()<<endl;
	cout<<"Antigüedad:  "<<d.Antiguedad(18,9,2020)<<endl;
	
	
	return 0;
}

