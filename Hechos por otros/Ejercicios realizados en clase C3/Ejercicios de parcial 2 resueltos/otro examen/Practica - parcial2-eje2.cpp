#include <iostream>
#include <vector>
#include <fstream>
using namespace std;




///NO TERMINADO




struct Producto{ //"productos.dat"
	int codigo_prod;
	float precio;
	string descripcion;
	int stock;
};
struct Detalle{ // "ventas.dat" 
	int fecha, dni_cliente, codigo_producto, cantidad;
};

void Vender(int dni, int fecha, vector<int> cod_productos, vector<int> cant_vendidas){
	ofstream Archi_ventas("ventas.dat", ios::binary|ios::app);
	vector<Detalle>Ventas;
	for(unsigned int i=0;i<cant_vendidas.size();i++) { 
		Detalle aux_det;
		aux_det.fecha = fecha;
		aux_det.codigo_producto = cod_productos[i];
		aux_det.dni_cliente = dni;
		aux_det.cantidad = cant_vendidas[i];
		Ventas.push_back(aux_det);
		Archi_ventas.write(reinterpret_cast<char*>(&aux_det),sizeof(Detalle));
	}
	fstream Archi_prod("productos.dat", ios::binary|ios::ate|ios::in|ios::out);
	
}


int main() {
	
	return 0;
}

