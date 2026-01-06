// Implemente una clase Fraccion para representar una fracción a partir de un  
// numerador y un denominador, con un método ConvertirADouble() para obtener el 
// real que representa, y los demÃ¡s métodos que considere necesarios. Implemente 
// una clase NumeroMixto para representar un número formado por una parte entera 
// y una fracción impropia (fracción menor a 1). Reutilice la clase Fraccion al 
// implementar la clase NumeroMixto. La clase NumeroMixto debe también poseer 
// un método ConvertirADouble(). ¿Qué relación entre clases puede utilizar en este 
// caso?

// Creo que la relación entre clases que mejor modela la relación "real" entre
// numero mixmo y fracción es la composición (como en ejer6.cpp). Pero en este
// caso alguien podría plantear la duda y hacerlo por herencia. Más aún, al 
// hacerlo por herencia el código queda todavía más simple que por composición.
// Entonces, para reutilizar y ahorrar código, se podría llegar a justificar la
// herencia, y por eso esta solución alternativa.
	
	
#include <iostream>
using namespace std;

class Fraccion {
	int m_num, m_den;
public:
	Fraccion(int n, int d) { m_num=n; m_den=d; }
	void CargarNumerador(int n) { m_num=n; }
	void CargarDenominador(int d) { m_den=d; }
	int VerNumerador() { return m_num; }
	int VerDenominador() { return m_den; }
	double ConvertirADouble() { return float(m_num)/m_den; }
};

class NumeroMixto : public Fraccion {
	int m_pe;
public:
	NumeroMixto(int pe, int num, int den) : Fraccion(num,den) , m_pe(pe) { }
	int VerParteEntera() { return m_pe; }
	double ConvertirADouble() {	return m_pe + Fraccion::ConvertirADouble(); }
};

int main(int argc, char *argv[]) {
	NumeroMixto tres_y_medio(3,1,2);
	cout << "Parte entera: " << tres_y_medio.VerParteEntera() << endl;
	cout << "Numerador: " << tres_y_medio.VerNumerador() << endl;
	cout << "Denominador: " << tres_y_medio.VerDenominador() << endl;
	cout << "Como double:" << tres_y_medio.ConvertirADouble();
}
