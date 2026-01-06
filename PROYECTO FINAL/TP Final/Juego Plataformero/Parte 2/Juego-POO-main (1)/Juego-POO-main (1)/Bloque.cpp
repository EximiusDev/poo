#include <iostream>
using namespace std;


	///Bloque///
class Bloque{
private:
public:	
	virtual int verdureza(){		///Muestra la dureza
		return dureza;
	};
	virtual int verpuntos(){		///Muestra los puntos
		return puntos;
		};
	
		
	
};


	///BloquePiedraDureza1///
class BloquePiedraDureza1:public Bloque{
private:
		int dureza = 2;
		int puntos = 10;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
		return puntos;
	};
		
};

	///BloquePiedraDureza2///
class BloquePiedraDureza2:public Bloque{
private:
		int dureza = 3;
		int puntos = 15;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};
		
};

	///BloquePiedraDureza3///
class BloquePiedraDureza3:public Bloque{
	
	
private:
	int dureza = 4;
	int puntos = 20;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};
};

	///Tierra///

class Tierra:public Bloque{
	
private:
	int dureza = 1;
	int puntos = 5;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};
	
};
	///MineralDiam///
class MineralDiam:public Bloque{
private:
	int dureza = 7;
	int puntos = 50;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};
};


	///MineralOro///
class MineralOro:public Bloque{
private:
	int dureza = 6;
	int puntos = 30;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};
		
};
	///MineralHierro///
class MineralHierro:public Bloque{
private:
	int dureza = 5;
	int puntos = 25;
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};	
};

	///Fosil///
class Fosil:public Bloque{
private:
		int dureza = 3;
		int puntos = 100;
		
public:	
	int verdureza(){
		return dureza;
	};
	int verpuntos(){		
			return puntos;
	};
		
};


int main(int argc, char *argv[]) {
	

	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

