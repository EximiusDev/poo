#include <iostream>
using namespace std;
/*Ejercicio 2
Implemente una función Clamp(...) que reciba como parámetros una variable (por
referencia) y dos valores indicando los límites superior e inferior para el valor de
dicha variable. Si el valor de la variable supera su máximo, este debe ajustarse al
máximo valor permitido. De la misma forma si el valor es inferior al mínimo. Pruebe
la función templatizada desde un programa cliente.
*/

template<typename T> // template<typename T, typename Q> /// para 2 variables genericas de distinto tipo
void Clamp(T &dato, T min, T max){
	if(dato < min) dato = min;
	if(dato > max) dato = max;
}

int main() {
	int val = 11;
	double d = 12.3;
	string palabra = "hola";
	Clamp(val,10, 20);
	cout<<val<<endl;
	Clamp<double>(d,10, 20);
	cout<<d<<endl;
	Clamp<string>(palabra,"abc", "def");
	cout<<palabra<<endl;
	
	int aux;
	for(int i=0;i<10;i++) { 
		aux = rand()%30;
		cout<<aux<<"  ";
		Clamp(aux,10, 20);
		cout<<aux<<endl;
	}
	
	
	
	return 0;
}

