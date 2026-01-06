#include <iostream>
#include <vector>
using namespace std;

class Tecla{
	string nota;
	bool presionada;
public:
	Tecla(string t):nota(t),presionada(false){};
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
	virtual string VerTipo(){return "sin nombre";}
};

class Piano: public Instrumento{
	vector<Tecla> t;
	Pedal pe;
public:
	Piano();
	string VerTipo(){return "Piano";}
	string ApretarTecla(int x){t[x].Apretar(); return t[x].VerNota();}
	void SoltarTecla(int x){t[x].Soltar();}
	void ApretarPedal(float x){pe.Presionar(x);}
	float VerEstadoPedal(){return pe.VerPresion();}
	bool VerEstadoTecla(int x){return t[x].EstaApretada();}
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
	cout<<"tipo de instrumento: "<<piano.VerTipo()<<endl;
	
	cout<<"Estado original de las techas y el pedal:\n";
	for(int i=0;i<7;i++) { 
		cout<<piano.VerEstadoTecla(i)<<"    ";
	}
	cout<<"pedal:  "<<piano.VerEstadoPedal()<<endl<<endl;
	
	// aprieto algunas teclas y presiono el pedal devuelve el nombre de las teclas que se presionan
	cout<<"\nTeclas presionadas:\n";
	cout<<piano.ApretarTecla(2)<<"   ";
	cout<<piano.ApretarTecla(5)<<"   ";
	cout<<piano.ApretarTecla(1)<<"   ";
	cout<<piano.ApretarTecla(0)<<"   ";
	cout<<piano.ApretarTecla(3)<<"   ";
	cout<<piano.ApretarTecla(2)<<endl;
	piano.ApretarPedal(3.5);
	
	cout<<"\nEstado de las techas y el pedal despues de presionar teclas:\n";
		for(int i=0;i<7;i++) { 
		cout<<piano.VerEstadoTecla(i)<<"    ";
	}
	cout<<"pedal: "<<piano.VerEstadoPedal()<<endl;
	
	// suelto algunas teclas y cambio la presion del pedal 
	piano.SoltarTecla(0);
	piano.SoltarTecla(1);
	piano.SoltarTecla(2);
	piano.ApretarPedal(9.1);
	cout<<"\nEstado de las techas y el pedal despues de soltar teclas:\n";
	for(int i=0;i<7;i++) { 
		cout<<piano.VerEstadoTecla(i)<<"    ";
	}
	cout<<"pedal: "<<piano.VerEstadoPedal()<<endl;
	
	return 0;
}

