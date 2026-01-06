/*Ej 3 (30pts) Escriba una función genérica llamada dosmin_down() que reciba un 
arreglo como parámetro. La función debe devolver los 2 menores. Además, la función 
debe ubicar el primer menor al comienzo del arreglo. Escriba la porción de código 
del programa cliente donde realiza la llamada a la función utilizando un vector de 
float, de strings y con un struct producto {string nombre; float precio;} y muestra 
los valores en la pantalla
*/

// si bien el enunciado lo no especifica, en esta solucion consideraré que no se debe 
// alterar el orden de los elementos


#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct producto{
	string nombre; 
	float precio;
};

bool operator<(producto x, producto y){       //sobrecargo el < para poder obtener el minimo de acuerdo al nombre
	return x.nombre<y.nombre;
}

template<typename T>
tuple <T,T> dosmin_down(vector<T> &x){
	auto it=min_element(x.begin(),x.end());     //obtengo el iterador al primer menor
	T aux1= *it;								//primer menor	
	x.erase(it); 								//elimino el menor de donde estaba
	x.insert(x.begin(),aux1);					//lo inserto al comienzo
	it=min_element(x.begin()+1,x.end());    	//obtengo el iterador al 2do menor salteando el primero menor que se encuentra al comienzo
	T aux2= *it;								//segundo menor
	return make_tuple(aux1,aux2);				//retorno los 2 menores
}

int main(int argc, char *argv[]) {
	vector<float> vf={6.5, 8.3, 3.2, 2.3, 3.4, 6.7, 5.4, 6.8, 3.1};
	vector<string> vs={"leon", "foca", "canario", "rana", "perro", "gato", "conejo","liebre"};
	vector<producto> vp={{"soda",120},{"azucar", 232},{"leche",187},{"choclate",400},{"alfajor",80},{"yogurt",130},{"jugo",60}};
	//pruebo y muestro con float
	float mf1,mf2;
	cout<<"original: ";
	for(float x:vf)
		cout<<x<<"  ";
	cout<<"\n";
	tie(mf1,mf2)= dosmin_down(vf);
	cout<<"menor1: "<<mf1<<"   menor2: "<<mf2<<endl;
	cout<<"modificado: ";
	for(float x:vf)
		cout<<x<<"  ";
	cout<<"\n\n";
	
	//pruebo y muestro con string
	string ms1,ms2;
	cout<<"original: ";
	for(string x:vs)
		cout<<x<<"  ";
	cout<<"\n";
	tie(ms1,ms2)= dosmin_down(vs);
	cout<<"menor1: "<<ms1<<"   menor2: "<<ms2<<endl;
	cout<<"modificado: ";
	for(string x:vs)
		cout<<x<<"  ";
	cout<<"\n\n";
	
	//pruebo y muestro con struct producto
	producto mp1,mp2;
	cout<<"original:\n";
	for(producto x:vp)
		cout<<x.nombre<<"    "<<x.precio<<endl;
	cout<<"\n";
	tie(mp1,mp2)= dosmin_down(vp);
	cout<<"menor1: "<<mp1.nombre<<"  "<<mp1.precio<<"       menor2: "<<mp2.nombre<<"  "<<mp2.precio<<endl;
	cout<<"modificado:\n";
	for(producto x:vp)
		cout<<x.nombre<<"    "<<x.precio<<endl;
	cout<<"\n\n";
	
	return 0;
}

