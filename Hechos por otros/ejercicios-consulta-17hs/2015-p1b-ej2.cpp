#include <iostream>
using namespace std;

class Correo {
	string m_mail, m_nombre;
	//int fecha; ///agregado por mi
public:
	//void AgregarFecha(int fecha){this->fecha = fecha;}  ///agregado por mi
	string operator[](int i) {
		if (i==0) return m_nombre;
		else return m_mail;
	}
	string VerNombre() { return m_nombre; }
	string VerMail() { return m_mail; }
	bool operator==(Correo c2) {
		return this->m_nombre==c2.m_nombre and this->m_mail==c2.m_mail;
	}
	
};

bool operator==(Correo c1, Correo c2) {
	return c1.VerNombre()==c2.VerNombre() and c1.VerMail()==c2.VerMail();
}

ostream &operator<<(ostream &o, Correo x) {
	o << x[0] << ", " << x[1];
	return o;
}

int main() {
	// completar
	///Yo mismo lo hice
	
	/*
	Correo C1;
	Correo C2();
	cout<<C1[1]<<endl;
	cout<<C2[1]<<endl;
	*/
	
	return 0;
}

