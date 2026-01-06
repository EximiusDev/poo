// Proponga una clase Lista_Ligada la cual permite modelar una lista enlazada 
// de objetos tipo Nodo. La clase Nodo contiene un entero, un flotante y un 
// puntero. La clase Lista_Ligada debe poseer los métodos: 
// a) agregar() para incorporar un nodo al final de la lista, 
// b) eliminar(int x) para quitar un nodo conociendo el miembro de tipo entero del nodo a eliminar, 
// c) eliminar() para eliminar el primer nodo. 
// Agregue otros metodos que crea convenientes para esta clase.

struct Nodo {
	int i;
	float f;
	Nodo *sig;
	Nodo(int _i, float _f, Nodo *_sig) { i=_i; f=_f; sig=_sig; }
};

class ListaLigada {
	Nodo *pri; // primero en la secuencia de enlaces (ultimo agregado)
	Nodo *ult; // ultimo en la secuencia de enlaces (primero agregado)
public:
	ListaLigada() { pri=ult=NULL; }
	void agregar(int i, float f) { // insertar al final
		Nodo *aux=ult; // este va a ser despues el anteultimo
		ult = new Nodo(i,f,NULL);
		if (aux!=NULL)
			aux->sig=ult;
		else
			pri=ult; // si estaba vacia, el nuevo es primero y ultimo
	}
	void ver_primero(int &i, float &f) { // para poder ver el contenido
		f=pri->f; i=pri->i;
	}
	void eliminar() { // eliminar el primer nodo
		Nodo *aux=pri;
		pri=pri->sig;
		delete aux;
		if (!pri) ult=NULL; // si no quedan mas nodos, ult tambien se pone en NULL
	}
	void eliminar(int x) { // eliminar el nodo que tiene el entero x
		if (!pri) return; // si esta vacia, no hace nada
		if (pri->i==x) { eliminar(); return; } // si es el primero, usa el eliminar comun
		Nodo *aux=pri;
		while (aux->sig && aux->sig->i!=x) aux=aux->sig; // busca el nodo a eliminar (que va a quedar en aux->sig)
		if (!aux->sig) return; // si se acabo la lista y no lo encontro
		Nodo *sigsig=aux->sig->sig; // el que le sigue al que se elimina
		delete aux->sig;
		aux->sig=sigsig;
		if (!sigsig) ult=aux; // si se elimino el ultimo, actualizar ult
	}
	bool esta_vacia() { return pri==NULL; } // pregunta si esta vacia
	void limpiar() { while(!esta_vacia()) eliminar(); } // vacia la lista
	~ListaLigada() { limpiar(); }
};
