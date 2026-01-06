#ifndef EQUIPAMIENTO_H
#define EQUIPAMIENTO_H

class Equipamiento {
	
	int kit_rep_m;
	int radar_m;
	int andamios_m;
	int motor_m;
	int taladro_m;
	int tanque_combust_m;
	int refuerzo_estruc_m;
	int bombas_m;
public:
	Equipamiento(int kit_rep, int radar, int andamios, int motor, int taladro, int tanque_combust, int refuerzo_estruc, int bombas){ /// Constructor
		kit_rep_m = kit_rep;
		radar_m = radar;
		andamios_m = andamios;
		motor_m = motor;
		taladro_m  =  taladro;
		tanque_combust_m = tanque_combust;
		refuerzo_estruc_m = refuerzo_estruc;
		bombas = bombas;
	}
	
	int VerCant_andamios(){ return andamios_m; 	}
	void ModifCant_andamios(int andamios){
		andamios_m = andamios;
		// andamios_m = andamios_m + andamios;
	}
		int Ver_kit_rep(){ return kit_rep_m; 	}
		void Modif_kit_rep(int kit_rep){ kit_rep_m = kit_rep;}
		
		int Ver_motor(){ return motor_m; 	}
		void Modif_motor(int motor){ motor_m = motor;}
		int Ver_taladro(){ return taladro_m; 	}
		void Modif_taladro(int taladro){ taladro_m = taladro;}
		int Ver_tanque_combust(){ return tanque_combust_m; 	}
		void Modif_tanque_combust(int tanque_combust){ tanque_combust_m = tanque_combust;}
		int Ver_refuerzo_estruc(){ return refuerzo_estruc_m; 	}
		void Modif_refuerzo_estruc(int refuerzo_estruc){ refuerzo_estruc_m = refuerzo_estruc;	}
		int VerCant_bombas(){ return bombas_m; 	}
		void ModifCant_bombas(int bombas){ bombas_m = bombas;}
};

#endif

