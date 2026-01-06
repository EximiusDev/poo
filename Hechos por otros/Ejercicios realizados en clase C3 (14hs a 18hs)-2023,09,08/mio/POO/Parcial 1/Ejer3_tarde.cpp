#include <iostream>
#include <vector>
using namespace std;
class Butaca{
private:
	int m_precio;
	string m_estado;
public:
	Butaca(int precio);
	void ModificarEstado(string estado);
	string ConsultarEstado(){return m_estado;}
	int VerPrecio(){return m_precio;} ///Agregué la funcion VerPrecio para usarla mas adelante al calcular la recaudacion
};

Butaca::Butaca(int precio){
	m_precio = precio;
}

void Butaca::ModificarEstado(string estado){
	m_estado=estado;
}

class Sala{
private:
	string m_nombre_sala;
	vector<Butaca>m_butacas;
public:
	Sala(string nombre_sala);
	void CargarButacas(vector<Butaca>butacas);
	int RegistrarCompra(int num);
	int Recaudacion();
	int PorcentajeOcupado();
};

Sala::Sala(string nombre_sala){
	m_nombre_sala = nombre_sala;
}

void Sala::CargarButacas(vector<Butaca>butacas){  ///Esta funcion asigna los valores del vector que se le pasa como parametro al vector en el private
	for(size_t i=0;i<butacas.size();i++) { 
		m_butacas[i] = butacas[i];
	}
}

int Sala::RegistrarCompra(int num){
	int butaca_asignada;
	int precio;
	for(size_t i=0;i<m_butacas.size();i++) { 
		if(m_butacas[i].ConsultarEstado() == "libre"){ ///Si la butaca esta libre (usando la funcion ConsultarEstado) asigna el numero de butaca y guarda el precio con VerPrecio
			butaca_asignada = i;	
			precio = m_butacas[i].VerPrecio();
		}else{											///Si no está libre
			for(size_t i=i;i<m_butacas.size();i++) { 
				if(m_butacas[i].ConsultarEstado() == "libre" && m_butacas[i].VerPrecio()==precio){ ///Va a buscar el asiento libre mas cercano con el mejor precio
					butaca_asignada = i;
				}else{
					return -1; ///Si esta todo ocupado, devuelve -1
				}
			}
		}
	}
	return butaca_asignada;
}

int Sala::Recaudacion(){
	int suma=0;
	for(size_t i=0;i<m_butacas.size();i++) { 
		if(m_butacas[i].ConsultarEstado() == "ocupada"){ 
			suma+=m_butacas[i].VerPrecio();///Se calcula la recaudacion llamando a la funcion VerPrecio y sumandolo
		}
	}
	return suma;
}

int Sala::PorcentajeOcupado(){
	int ocupado=0;
	for(size_t i=0;i<m_butacas.size();i++) { 
		if(m_butacas[i].ConsultarEstado() == "ocupada"){
			ocupado++;
		}
	}
	
	ocupado = (ocupado*100)/m_butacas.size(); /// Regla de tres para calcular el porcentaje ocupado
	return ocupado;
}

int main() {
	
	Sala s("Sala 1");
	
	vector<Butaca>butacas;
	
	for(int i=0;i<101;i++) { 
		Butaca b(600);			///de la 0 a la 100 el precio es 600
		butacas.push_back(b);
	}
	for(int i=101; i<301;i++){
		Butaca b(450);			///de la 101 a la 300 el precio es 450
		butacas.push_back(b);
	}
	for(int i=301; i<502; i++){
		Butaca b(300);			///de la 301 a la 501 el precio es 300
		butacas.push_back(b);
	}
	
	int ventas;
	cout<<"Cuanta ventas se realizaron"<<endl; ///Pregunto cuantas ventas se realizaron
	cin>>ventas;
	
	s.CargarButacas(butacas); ///Cargo el vector de butacas
	
	int n;
	for(int i=0;i<ventas;i++) { 
		cout<<"Ingrese el numero de butaca que desea comprar"<<endl;
		cin>>n;
		int b = s.RegistrarCompra(n); ///Registro la compra
		if(b!=-1){
			cout<<"La butaca fue comprada con exito"<<endl; ///Si esta libre, la compra
			butacas[i].ModificarEstado("ocupado"); ///Y cambia el estado
		}else{
			cout<<"No hay ninguna butaca libre con el mismo precio"<<endl;
		}
	}
	
	int recaudacion = s.Recaudacion();
	cout<<"La recaudacion fue de: "<<recaudacion<<endl;
	
	int ocupado = s.PorcentajeOcupado();
	cout<<"La sala esta un "<<ocupado<<"% ocupada"<<endl;
	
	
	return 0;
}

