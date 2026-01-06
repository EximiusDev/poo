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

class Altura
	{
	public:
		float h; //Altura.
		int dni;
		Altura(float H, int DNI) : h(H), dni(DNI)
		{
		}
	};
class Alturas
	{
	public:
		list<Altura>alturasList;
		Alturas(list<Altura>& AlturasList) : alturasList(AlturasList)
		{
		}
		void SaveToDisk()
		{
			list<Altura>::iterator it = alturasList.begin();
			fstream salida("ALTURAS.DAT",ios::binary | ios::out);

			for (it; it != alturasList.end(); it++)
			{
				cout << "Grabando: " << ((Altura)*it).h << " " << ((Altura)*it).dni << endl;
				salida.write((char*)&((Altura)*it).h,sizeof(float));
				salida.write((char*)&((Altura)*it).dni,sizeof(int));
			}
			salida.close();
		}
		void ReadFromDisk()
		{
			fstream entrada("ALTURAS.DAT",ios::binary | ios::in);
			
			float h; int dni;
			while (!entrada.eof())
			{
				entrada.read((char*)&h,sizeof(float));
				entrada.read((char*)&dni,sizeof(int));
				cout << h << " - " << dni << endl;
			}
			
			entrada.close();
		}
	};

int main(int argc, char *argv[]) {	
	Altura alt1(10,10);
	Altura alt2(11,11);
	
	list<Altura>altus;
	altus.push_front(alt1);
	altus.push_front(alt2);
	
	Alturas alturas(altus);
	
	alturas.SaveToDisk();
	alturas.ReadFromDisk();
	
	return 0;
}

