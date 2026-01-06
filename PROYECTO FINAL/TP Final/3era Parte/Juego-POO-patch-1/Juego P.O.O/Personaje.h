#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje : public Equipamiento  {

	int vida_m;
	int combustible_m;
	int dinero_m;
	
	Equipamiento equipo_pj; // composicion de clases
	///mejoras, equipamiento, inventario
public:
	Personaje(int vida, int combustible, int dinero,Equipamiento equipo_p):vida_m(vida),combustible_m(combustible),dinero_m(dinero),equipo_pj(equipo_p){}
	/* Personaje(int vida, int combustible, int dinero, Equipamiento equipo_p(int kit_rep, int radar, int andamios)){  //mal hecho
	vida_m = vida;
	combustible_m = combustible;
	dinero_m = dinero;
	equipo_pj = equipo_p;
	}*/
	/// moverse
	/// usar 
	///void Moverse(int tecla){
	int Moverse(int tecla){
		/*
		if (tecla == ('a'||'A')){
		
	}
		if (tecla == ('d'||'D')){
		
	}
		if (tecla == ('s'||'S')){  ///abajo
		
	}
		*/
		if (tecla == ('w'||'W')){
			if (equipo_pj.VerCant_andamios() > 0){
				equipo_pj.ModifCant_andamios(equipo_pj.VerCant_andamios()-1);
			}
			else{
				return -1;
				///return null;
			}
		}
	}
		
		///	equipo_pj.VerCant_andamios();  // llamo a un metodo de la clase Equipamiento
		/// void Usar
};


#endif

