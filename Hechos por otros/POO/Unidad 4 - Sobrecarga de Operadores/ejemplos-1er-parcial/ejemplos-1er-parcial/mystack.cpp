// Ej 1 (30pts) Proponga una clase mystack que opere como una lista enlazada
// de tipo pila. Los elementos enlazados deben ser objetos de la clase node,
// cuyos atributos son el DNI y el nombre de una persona.
// Proponga las clases node y mystack completas, pero solo implemente los 
// métodos push y pop_until para agregar un nodo y eliminar nodos 
// respectivamente. El método pop_until elimina nodos de la pila hasta encontrar
// un nodo con un DNI que se le pasa como parametro (se elimina tambien ese 
// nodo). El metodo devuelve un entero con la cantidad de nodos eliminados.

struct dato {
	int dni;
	char nom[50];
};
	
struct node {
	node *sig;
	dato d;
	node(dato _d, node *s) { d=_d; sig=s; }
};
	
class mystack {
	node *tope;
	dato pop() {
		node *aux=tope;
		tope=tope->sig;
		dato aux2=aux->d;
		delete aux;
		return aux2;
	}
public:
	mystack() { tope=NULL; }
	~mystack() { clear(); }
	void push(dato d) {
		tope=new node(d,tope);
	}
	int pop_until(int dni) {
		int n=1;
		while (!empty() && pop().dni!=dni) n++;
		return n;
	}
	bool empty() { return tope==NULL; }
	void clear() { while (!empty()) pop(); }
};
