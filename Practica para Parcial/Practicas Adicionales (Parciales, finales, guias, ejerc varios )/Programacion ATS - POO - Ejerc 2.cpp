/*
Construir una clase Tiempo que contenga ...
*/
#include <iostream>
using namespace std;

class Tiempo{
private:
	int m_horas, m_minutos, m_segundos;
public:
	Tiempo(int, int, int); /// se escribe el constructor por fuera de la clase
	Tiempo(int);
	int Ver_hora(){
		return m_horas;
	}
	int Ver_minutos(){
		return m_minutos;
	}
	int Ver_segundos(){
		return m_segundos;
	}
};
Tiempo::Tiempo(int horas, int minutos, int segundos){
	m_horas = horas;
	m_minutos = minutos;
	m_segundos = segundos;
}
Tiempo::Tiempo(int segundos){
	m_horas = segundos/(60*60);
	m_minutos = (segundos - (m_horas *60*60))/60;
	m_segundos = segundos - (m_horas *60*60) - (m_minutos *60);
}

int main() {
	
	Tiempo t1( 2, 30, 20);
	/// 	Tiempo t2( 10800); /// 3 horas
	Tiempo t2( 11415); // 3 hs 10 min 15 seg
	
	cout<<"La hora es :"<<t1.Ver_hora()<<endl;
	cout<<"La hora es :"<<t2.Ver_hora()<<endl;
	
	cout<<"min :"<<t1.Ver_minutos()<<endl;
	cout<<"min :"<<t2.Ver_minutos()<<endl;
	cout<<"segundos :"<<t1.Ver_segundos()<<endl;
	cout<<"segundos :"<<t2.Ver_segundos()<<endl;
	
	return 0;
}

