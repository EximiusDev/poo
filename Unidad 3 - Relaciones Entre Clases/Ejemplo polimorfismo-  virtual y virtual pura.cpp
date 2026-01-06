#include <iostream>
using namespace std;

class base{
public:
	virtual void ver(){cout<<"base\n";}    //SI SACO EL VIRTUAL ME MOSTRARIA MAL LA ULTIMA LINEA DEL MAIN (se ejecuta la base y no la hija en el puntero pp)
	void Mostrar(){cout<<"muestro base\n";}    
	void mostrar(){cout<<"muestro base\n";}    
	void Hablar_base(){cout<<"Hablo base\n";}
	
	/// Puedo crear una clase virtual pura al igualar a 0, ej:
	///virtual void ver() = 0; /// es clase virtual pura (no se puede llamar la funciom si se usa un metodo virtual puro)
};

class hija:public base{
public:
	void ver(){cout<<"hija\n";}
	void Mostrar(){cout<<"muestro hija\n";}
	void Hablar_hija(){cout<<"Hablo hija\n";}
};


int main(int argc, char *argv[]) {
	cout<<"Objetos estaticos:	"<<endl;
	
	base b;
	b.ver();
	b.Mostrar();
	b.Hablar_base();
	//b.Hablar_hija(); Por obvias razones no se puede usar un metodo de la hija
	cout<<endl;
	
	hija h;
	h.ver(); // Metodo virtual (uso de la hija)
	h.Mostrar(); /// polimorfismo usa el metodo mostrar de la hija en vez de la base
	//h.mostrar(); /// metodo de base [no usa override] (mal escrito) puede generar problemas 
	h.Hablar_hija(); /// metodo de la hija
	h.Hablar_base(); /// puedo usar un metodo de la base desde la hija con polimorfismo
	cout<<endl;
	
	///////////// punteros ////////
	cout<<"Punteros:	"<<endl;
	
	base *pb=new base; /// Creo un puntero de tipo base (objeto) y libero memoria dinamica de tipo base(objeto)
	// pb->ver(); //  eso el operador -> para señalizar un metodo del puntero del objeto
	pb->ver(); /// se ejecuta [ver] de la base
	pb->Mostrar(); 
	pb->Hablar_base(); 
	//pb->Hablar_hija(); Por obvias razones no se puede usar un metodo de la hija
	cout<<endl;
	
	hija *ph=new hija;  /// Creo un puntero de tipo hija (objeto) y libero memoria dinamica de tipo hija(objeto)
	ph->ver(); /// se ejecuta [ver] de la hija
	ph->Mostrar(); //hija [cuidado con no usar el override, puede generar problemas si el metodo esta mal escrito]
	ph->mostrar(); 
	ph->Hablar_base(); // es metodo de la base, lo hereda la hija
	ph->Hablar_hija(); //hija
	cout<<endl;
	
	base *pp=new hija;  /// Creo un puntero de tipo base (objeto) y libero memoria dinamica de tipo hija(objeto)
	pp->ver();  /// se ejecuta [ver] se la hija
	pp->Mostrar(); // se ejecuta la base
	pp->Hablar_base(); // es metodo de la base
	//pp->Hablar_hija(); // no se puede usar porque es de hija y el puntero es de clase base
	///En este puntero solo se puede usar polimorfismo, no herencia
	

	
	return 0;
}

