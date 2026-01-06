#include "Equipamiento.h"

Equipamiento::Equipamiento() {
	
	motor_m = 0; // 0
	taladro_m  =  0; // 1
	tanque_combust_m = 0; // 2
	refuerzo_estruc_m = 0; //3
	bombas_m = 0; //4
	kit_rep_m = 0; //5
	radar_m = 0; //6
	andamios_m = 0; //7
}

Equipamiento::Equipamiento(int kit_rep, int radar, int andamios, int motor, int taladro, int tanque_combust, int refuerzo_estruc, int bombas){ /// Constructor
	
	motor_m = motor;
	taladro_m  =  taladro;
	tanque_combust_m = tanque_combust;
	refuerzo_estruc_m = refuerzo_estruc;
	bombas_m = bombas;
	kit_rep_m = kit_rep;
	radar_m = radar;
	andamios_m = andamios;
}
int Equipamiento::VerCant_andamios(){ return andamios_m; 	}
void Equipamiento::ModifCant_andamios(int andamios){
	andamios_m = andamios;
	// andamios_m = andamios_m + andamios;
}
int Equipamiento::Ver_kit_rep(){ return kit_rep_m; 	}
void Equipamiento::Modif_kit_rep(int kit_rep){ kit_rep_m = kit_rep;}
		
int Equipamiento::Ver_motor(){ return motor_m; 	}
void Equipamiento::Modif_motor(int motor){ motor_m = motor;}
int Equipamiento::Ver_taladro(){ return taladro_m; 	}
void Equipamiento::Modif_taladro(int taladro){ taladro_m = taladro;}
int Equipamiento::Ver_tanque_combust(){ return tanque_combust_m; 	}
void Equipamiento::Modif_tanque_combust(int tanque_combust){ tanque_combust_m = tanque_combust;}
int Equipamiento::Ver_refuerzo_estruc(){ return refuerzo_estruc_m; 	}
void Equipamiento::Modif_refuerzo_estruc(int refuerzo_estruc){ refuerzo_estruc_m = refuerzo_estruc;	}
int Equipamiento::VerCant_bombas(){ return bombas_m; 	}
void Equipamiento::ModifCant_bombas(int bombas){ bombas_m = bombas;}

