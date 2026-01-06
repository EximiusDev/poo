#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Hago un struct con la información que necesito porque es mas cómodo devolverla luego además de accederla y escribirla en disco.
struct versionData
	{
		string nombre_del_software;
		string ruta_del_archivo;
		float version;
		string codigo_empresa;
		int mes,anio;
	};
class file_jxg
	{
	protected:
		// Esto es equivalente a declarar las propiedades acá adentro.
		versionData ver;
	public:
		file_jxg(string ruta)
		{
			//Abro el archivo binario que me enviaron como parametro.
			ver.ruta_del_archivo = ruta;
			fstream in(ruta.c_str(), ios::binary | ios::in);
			//Solo por las dudas establezco el puntero get en el principio
			in.seekg(ios::beg);
			//Cargo las propiedades que necesito.
			in.read((char*)&ver.nombre_del_software,30);
			in.read((char*)&ver.version,sizeof(int));
			in.read((char*)&ver.codigo_empresa,12);
			
			//Como los últimos dos datos están al final del archivo necesito ir hasta el final y volver 8 bytes.
			in.seekg(-sizeof(int)*2,ios::end);
			//Estoy al (casi) final, puedo leer lo que me queda.
			in.read((char*)&ver.mes,sizeof(int));
			in.read((char*)&ver.anio,sizeof(int));
			in.close();
		}
		
		versionData newversion_data()
		{
			//Epic win! Como usé un struct no necesito estar escribiendo un método para devolver cada una de las propiedades
			//Directamente devuelvo el objeto que las contiene todas y el usuario puede accederlas like a boss
			return ver;
		}
		
		void converter(string nuevo_nombre, float nueva_version, string nuevo_codigo_empresa, int nuevo_mes, int nuevo_anio)
		{
			//Lo mismo que en el constructor, pero en vez de leer escribo las propiedades modificadas luego de actualizar
			//el estado de la instancia actual de esta misma clase.
			ver.nombre_del_software = nuevo_nombre;
			ver.version = nueva_version;
			ver.codigo_empresa = nuevo_codigo_empresa;
			ver.mes = nuevo_mes;
			ver.anio = nuevo_anio;
			
			fstream out(ver.ruta_del_archivo.c_str(),ios::binary | ios::out);
			out.seekp(ios::beg);
			out.write((char*)&ver.nombre_del_software,30);
			out.write((char*)&ver.version,sizeof(int));
			out.write((char*)&ver.codigo_empresa,12);
			
			out.seekp(-sizeof(int)*2,ios::end);
			out.write((char*)&ver.mes,sizeof(int));
			out.write((char*)&ver.anio,sizeof(int));
			out.close();
		}
	};

int main(int argc, char *argv[]) {
	
	return 0;
}

