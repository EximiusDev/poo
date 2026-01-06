#include "Personaje.h"

#include <iostream>
using namespace std;

Personaje::Personaje(Equipamiento equipo_p()) {
//Personaje::Personaje() {
	vida_m = 100;
	combustible_m = 10;
	dinero_m = 0;
	
	equipo_pj = equipo_p();
}

//Personaje(int vida, int combustible, int dinero,Equipamiento equipo_p):vida_m(vida),combustible_m(combustible),dinero_m(dinero),equipo_pj(equipo_p)
//Personaje::Personaje(int vida, int combustible, int dinero, Equipamiento equipo_p(int kit_rep, int radar, int andamios)){ 
//Personaje::Personaje(int vida, int combustible, int dinero, Equipamiento equipo_p(int kit_rep, int radar, int andamios, int motor, int taladro, int tanque_combust, int refuerzo_estruc, int bombas)){ 
Personaje::Personaje(int vida, int combustible, int dinero, Equipamiento equipo_p){ 
//Personaje::Personaje(int vida, int combustible, int dinero){ 
vida_m = vida;
combustible_m = combustible;
dinero_m = dinero;

/*
int kit_rep_m;
int radar_m;
int andamios_m;
int motor_m;
int taladro_m;
int tanque_combust_m;
int refuerzo_estruc_m;
int bombas_m;

kit_rep_m = kit_rep;
radar_m = radar;
andamios_m = andamios;
motor_m = motor;
taladro_m  =  taladro;
tanque_combust_m = tanque_combust;
refuerzo_estruc_m = refuerzo_estruc;
bombas_m = bombas; */


equipo_pj = equipo_p;

cout<<endl;
cout<<equipo_p.Ver_motor()<<" motor equipo_p";
cout<<endl;
cout<<equipo_pj.Ver_motor()<<" motor equipo_pj";


//equipo_pj = equipo_p(kit_rep, radar, andamios, motor, taladro, tanque_combust, refuerzo_estruc, bombas);
//equipo_pj = equipo_p(kit_rep_m, radar_m, andamios_m, motor_m, taladro_m, tanque_combust_m, refuerzo_estruc_m, bombas_m);
}

// kit_rep, radar, andamios, motor, taladro, tanque_combust, refuerzo_estruc, bombas

int Personaje::Ver_vida(){return vida_m;}
int Personaje::Ver_combustible(){return combustible_m;}
int Personaje::Ver_dinero(){return dinero_m;}


//Equipamiento Ver_Equipamiento(){return equipo_pj;}

void Personaje::Modificar_Equipamiento(Equipamiento equipo_p){
	equipo_pj = equipo_p;
}
/*
void Ver_Equipamiento(Equipamiento equipo){
	this -> equipo = equipo_pj;
}
*/

