#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//a)
struct Producto{
	int codigo;
	float precio;
	char descrip[30];
	int stock;
};

struct Detalle{
	int fecha;
	int codCli;
	int codProd;
	int cant;
};


//b)
void ActualizarVentas(int dni, int f, vector<int>codpro, vector<int>cantpro){
	fstream fven("ventas.dat",ios::binary|ios::in|ios::out);
	fstream fpro("productos.dat",ios::binary|ios::in|ios::out|ios::ate);
	int cantproductos=fpro.tellg()/sizeof(Producto);
	for(size_t i=0;i<codpro.size();i++){
	    //actualizar producto	
		Producto rp;
		fpro.seekg(0);
		for (int j=0;j<cantproductos;j++){ //actualizo stock
			fpro.read(reinterpret_cast<char*>(&rp),sizeof(Producto));
			if (codpro[i]==rp.codigo){
				rp.stock-= cantpro[i];
				fpro.seekp(j*sizeof(Producto));
				fpro.write(reinterpret_cast<char*>(&rp),sizeof(Producto));
				break;
			}
		}	
		//actualizar ventas
		/*
		Detalle rd;
		rd.fecha=f;
		rd.codCli=dni;
		rd.codProd=codpro[i];
		rd.cant=cantpro[i];
		*/
		
		Detalle rd={ f,dni,codpro[i],cantpro[i] };
			
		
		fven.seekp(0,ios::end);   
		fven.write(reinterpret_cast<char*>(&rp),sizeof(Producto));
	}
	fpro.close();
	fven.close();
}
	
	
int main(int argc, char *argv[]) {
	
	return 0;
}

