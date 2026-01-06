/*Ejercicio 3 (30 pts) a) Escriba una clase Promocion para representar una promoción 
de una tienda virtual. La clase debe poder guardar una descripción de la promoción,
 y tener además un método virtual Aplicar(...) que reciba un struct de tipo Compra 
como el del recuadro y retorne un float con el monto que el cliente se ahorra gracias
 a esa promoción, o cero si la promoción no es aplicable a esa compra. 
b) Implemente dos herencias, Promo3x2 y Promo1000. La primera, cuya descripción 
será "3x2 en todas las marcas" aplica cuando un cliente compra 3 o más unidades 
de un mismo producto; y en ese caso por cada 3 unidades, se le descuenta una. 
La segunda, cuya descripción será "5% en compras superiores a $1000" aplica cuando 
la compra es mayor a $1000, y en ese caso se le descuenta un 5%. c) Implemente una 
función que reciba un vector de Compras y dos Promociones, y retorne un vector de 
Descuentos. La función debe intentar aplicar cada promoción a cada compra, 
y generar un vector con todos los descuentos de aquellas que efectivamente apliquen.
*/	

#include <iostream>
#include <vector>
using namespace std;

struct Compra{
	string codigo_producto;
	float precio_unitario;
	int cantidad;
};
struct Descuento{
	string descripcion;
	float monto;
};

class Promocion{
protected:
	string m_descripcion;
public:
	Promocion(string descripcion):m_descripcion(descripcion){}
	virtual float Aplicar(Compra &c)=0;
	string VerPromocion(){return m_descripcion;}
};

class Promo3x2:public Promocion{
public:
	Promo3x2():Promocion("3x2 en todas las marcas"){}
	float Aplicar(Compra &c)override{
		if(c.cantidad>=3)
			return (c.cantidad/3)*c.precio_unitario;    //resto 1 por cada 3 productos
		return 0;
	}
};

class Promo1000:public Promocion{
public:
	Promo1000():Promocion("5% en compras superiores a 1000"){}
	float Aplicar(Compra &b)override{
		if(b.precio_unitario*b.cantidad >=1000)   //la compra es precion * cantidad
			return b.precio_unitario*b.cantidad * 0.05 ;   //al total de 5%
		return 0;
	}
};
	
vector<Descuento> ListaDescuentos (vector<Compra>&x,Promo3x2 &a, Promo1000 &b){
	vector <Descuento>d;
	float aux1,aux2;
	for(size_t i=0;i<x.size();i++) { 
		aux1=a.Aplicar(x[i]);
		aux2=b.Aplicar(x[i]);
		if (aux1>0) 			//guardo las promociones (no acumulaticas, o un a u otra)
			d.push_back(Descuento{a.VerPromocion(),aux1});
		else if (aux2>0)
			d.push_back(Descuento{b.VerPromocion(),aux2});
	}
	return d;
}
		
int main() {
	vector<Compra>v;
	vector<Descuento>Dtos;
	Promo3x2 a;
	Promo1000 b;
//	compra: codigo_producto, precio_unitario, cantidad
	v.push_back(Compra{"P001",10,10});
	v.push_back(Compra{"P203",700,2});
	v.push_back(Compra{"P301",1,2});
	v.push_back(Compra{"P401",800,2});
	v.push_back(Compra{"P051",1,20});
	v.push_back(Compra{"P025",16,2});
	v.push_back(Compra{"P008",11,1});
	v.push_back(Compra{"P038",10,20});
	v.push_back(Compra{"P203",5,3});
	Dtos=ListaDescuentos(v,a,b);
	for(size_t i=0;i<Dtos.size();i++) { 
		cout<<Dtos[i].descripcion<<"    monto:    "<<Dtos[i].monto<<endl;
	}
	
	
	return 0;
}
