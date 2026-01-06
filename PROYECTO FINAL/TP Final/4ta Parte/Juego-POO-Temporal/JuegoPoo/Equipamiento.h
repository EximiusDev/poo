#ifndef EQUIPAMIENTO_H
#define EQUIPAMIENTO_H

class Equipamiento {
private:
	int kit_rep_m;
	int radar_m;
	int andamios_m;
	int motor_m;
	int taladro_m;
	int tanque_combust_m;
	int refuerzo_estruc_m;
	int bombas_m;
	
public:
	Equipamiento(int kit_rep, int radar, int andamios, int motor, int taladro, int tanque_combust, int refuerzo_estruc, int bombas); /// 
	Equipamiento(); /// sobrecarga de construcctor
	
	int VerCant_andamios();
	void ModifCant_andamios(int andamios);
	int Ver_kit_rep();
	void Modif_kit_rep(int kit_rep);
	int Ver_motor();
	void Modif_motor(int motor);
	int Ver_taladro();
	void Modif_taladro(int taladro);
	int Ver_tanque_combust();
	void Modif_tanque_combust(int tanque_combust);
	int Ver_refuerzo_estruc();
	void Modif_refuerzo_estruc(int refuerzo_estruc);
	int VerCant_bombas();
	void ModifCant_bombas(int bombas_m);
};

#endif

