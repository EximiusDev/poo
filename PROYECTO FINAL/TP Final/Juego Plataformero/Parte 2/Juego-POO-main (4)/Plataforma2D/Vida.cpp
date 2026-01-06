#include "Vida.h"

Vida::Vida() {
	
}

bool Vida::pierdeVida(){ bool Perdio; cantVida--; if(cantVida<=0){Perdio=true;return Perdio;}else{Perdio = false; return Perdio;}}

void Vida::Reinicio(){cantVida =3;}
