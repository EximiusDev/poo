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

class base2{
public:
	virtual void ver2()=0; //{cout<<"base\n";}    //No puedo definir nada en la clase base si es virtual pura
	/// Puedo crear una clase virtual pura al igualar a 0, ej:
	///virtual void ver() = 0; /// es clase virtual pura (no se puede llamar la funciom si se usa un metodo virtual puro)
	void Mostrar2(){cout<<"muestro base2\n";}    
	void Hablar_base2(){cout<<"Hablo base2\n";}
	virtual void virt_no_puro2(){cout<<"virtual_no_puro base2\n";}
};

class hija:public base{
public:
	void ver(){cout<<"hija\n";}
	void Mostrar(){cout<<"muestro hija\n";}
	void Hablar_hija(){cout<<"Hablo hija\n";}
};

class hija2:public base2{
public:
	void ver2() override{ /// el override no es obligatorio pero es una buena practica de programacion evita confusiones al usar un metodo virtual puro
		cout<<"hija2\n";
	}
	//void mostrar2()override{cout<<"muestro hija2 \n";} // tira error porque no exite [mostrar2] en la base, buen uso de override
	void Mostrar2(){cout<<"muestro hija2 \n";}
	void Hablar_hija(){cout<<"Hablo hija2 \n";}
	void virt_no_puro2()override{cout<<"virtual_no_puro hija2\n";} /// no se puede usar el override sin el virtual en la base
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
	
	////////////////////////////////////////////////////////////////
	
	cout<<"\n\n\n";
	cout<<"Base2: \n\n";
	
	/*
	base2 *pb2=new base2; // No se puede usar porque (base2) es virtual pura
	pb2->ver2(); /// NO SE PUEDE USAR POR SE VIRTUAL PURA
	pb2->Mostrar2(); 	// base2 (andaria si no tuviera un virtual puro)
	pb2->Hablar_base2(); //base2 (andaria si no tuviera un virtual puro)
	//pb->Hablar_hija(); Por obvias razones no se puede usar un metodo de la hija de base2 (hija2)
	pb2->virt_no_puro2(); /// base2 (andaria si no tuviera un virtual puro)
	cout<<endl;*/
	
	hija2 *ph2=new hija2; 
	ph2->ver2(); ///veo hija2 (la base (base2) al ser virtual pura no se puede usar)
	ph2->Mostrar2(); // hija2
	ph2->Hablar_base2();  // puede usar el metodo no virtual  puro de base2
	ph2->Hablar_hija();  // hija2
	ph2->virt_no_puro2();  // hija2
	
	cout<<endl;
	
	base2 *pp2=new hija2;  
	pp2->ver2();  /// hija2, es virtual puro, no se puede usar el de la base
	pp2->Mostrar2(); // base2 
	//pp2->Hablar_hija(); // No se puede usar porque es un objeto de clase base2
	pp2->Hablar_base2(); //base2
	pp2->virt_no_puro2();  // hija2
	
	return 0;
}

