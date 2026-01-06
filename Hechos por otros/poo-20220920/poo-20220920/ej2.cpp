/// Parcial 1 2020 - Ej 2

#include <iostream>
using namespace std;

class ProgressIndicator {
public:
	virtual void comenzar(int n) = 0;
	virtual void paso() = 0;
	virtual void finalizar() = 0;
	virtual ~ProgressIndicator() { }
};

class PorcentualIndicator : public ProgressIndicator {
public:
	void comenzar(int n) override { cant = n; i = 0; paso(); }
	void paso() override { cout << "Progreso: " << 100*i/cant << "%" << endl; }
	void finalizar() override { cout << "Proceso completado con exito" << endl; }
private:
	int cant, i;
};

class TextualProgress : public ProgressIndicator {
public:
	void comenzar(int n) override { cant = n; i=0; paso(); }
	void paso() override { cout << "Ejecutando paso " << ++i << " de " << cant << endl; }
	void finalizar() override { cout << "Ejecucion finalizada" << endl; }
private:
	int cant, i;
};

void obtenerBeneficiarios(int n, ProgressIndicator &p); 

int main() {
	int cual;
	cin >> cual;
	ProgressIndicator *p;
	if (cual==1) {
		p = new PorcentualIndicator();
	} else {
		p = new TextualProgress();
	}
	obtenerBeneficiarios(5,*p); // al compilar va a dar undefined reference porque no esta la implentacion de esta fun
	delete p;
	return 0;
}

