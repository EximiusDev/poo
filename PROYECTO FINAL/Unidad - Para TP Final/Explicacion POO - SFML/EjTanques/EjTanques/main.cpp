#include "Juego.h"
#include "Partida.h"

int main(int argc, char *argv[]){
	Juego j(new Partida);
	j.jugar();
	return 0;
}

