#include <iostream>
#include <vector>
using namespace std;

class Tecla{
	string nota;
	bool presionada;
public:
	Tecla(string t):nota(t),presionada(false){}
	string VerNota(){return nota;}
	void Apretar(){presionada=true;}
	void Soltar(){presionada=false;}
	bool EstaApretada(){return presionada;}	
	
};

class Pedal{
	float presion;
public:
	Pedal():presion(0){}
	void Presionar(float p){presion=p;}
	float VerPresion(){return presion;}
};

class Instrumento{
public:
	virtual string VerTipo() { return "sin_nombre"; }
	virtual ~Instrumento(){}
};

class Piano:public Instrumento{
   Pedal pe;
   vector<Tecla> t;
public:
	Piano();
	string VerTipo(){return "piano";}
	string ApretarTecla(int x){t[x].Apretar();return t[x].VerNota();}
	void SoltarTecla(int x){t[x].Soltar();}
	bool VerEstadoTecla(int x){ return t[x].EstaApretada(); }
	void ApretarPedal(float x){pe.Presionar(x); }
	float VerEstadoPedal(){return pe.VerPresion();}
};

Piano::Piano(){
	t.push_back(Tecla("do"));
	t.push_back(Tecla("re"));
	t.push_back(Tecla("mi"));
	t.push_back(Tecla("fa"));
	t.push_back(Tecla("sol"));
	t.push_back(Tecla("la"));
	t.push_back(Tecla("si"));
}

int main(int argc, char *argv[]) {
	Piano piano;
	cout<<"Tipo de Instrumento: "<<piano.VerTipo()<<endl;
	cout<<"\nestado original de las teclas:\n";
	for(int i=0;i<7;i++) { 
		cout<<piano.VerEstadoTecla(i)<<endl;
	}
	cout<<piano.VerEstadoPedal()<<endl;
	
	cout<<piano.ApretarTecla(4)<<"   ";
	cout<<piano.ApretarTecla(1)<<"   ";
	cout<<piano.ApretarTecla(2)<<"   ";
	cout<<piano.ApretarTecla(0)<<"   ";
	cout<<piano.ApretarTecla(6)<<"   ";
	cout<<piano.ApretarTecla(5)<<"   ";
	cout<<piano.ApretarTecla(0)<<"   ";
	cout<<piano.ApretarTecla(1)<<"   ";
	cout<<piano.ApretarTecla(4)<<"   ";
	piano.ApretarPedal(3.5);
	
	cout<<"\n\nestado final de las teclas:\n";
	for(int i=0;i<7;i++) { 
		cout<<piano.VerEstadoTecla(i)<<endl;
	}
	cout<<piano.VerEstadoPedal()<<endl;
	
	
    piano.SoltarTecla(0);
    piano.SoltarTecla(1);
    piano.SoltarTecla(2);
    
	cout<<"\n\nestado final de las teclas despues de soltar:\n";
	for(int i=0;i<7;i++) { 
		cout<<piano.VerEstadoTecla(i)<<endl;
	}
	
	
	
	return 0;
}

