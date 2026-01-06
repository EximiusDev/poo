#ifndef PERSONAJE_H
#define PERSONAJE_H
//#include "Equipamiento.h"

//class Personaje : public Equipamiento {
class Personaje {
private:	
	int vida_m;
	int combustible_m;
	int dinero_m;
	
	Equipamiento equipo_pj; // composicion de clases
	///mejoras, equipamiento, inventario
	
public:
	
	//Personaje();
	Personaje(Equipamiento equipo_p());
	
	//Personaje(int vida, int combustible, int dinero,Equipamiento equipo_p):vida_m(vida),combustible_m(combustible),dinero_m(dinero),equipo_pj(equipo_p);
	//Personaje(int vida, int combustible, int dinero, Equipamiento equipo_p(int kit_rep, int radar, int andamios, int motor, int taladro, int tanque_combust, int refuerzo_estruc, int bombas));
	Personaje(int vida, int combustible, int dinero, Equipamiento equipo_p);
	int Ver_vida();
	int Ver_combustible();
	int Ver_dinero();
	
	//Equipamiento Ver_Equipamiento(){return equipo_pj;}
	
	void Personaje::Modificar_Equipamiento(Equipamiento equipo_p);
	//void Ver_Equipamiento();
	
};

#endif

