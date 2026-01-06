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

int main(int argc, char *argv[]) {
	
	ofstream of("grupo.dat",ios::binary);
	for (int i = 0; i < 200; i++)
	{
		int i = rand()%100;
		float f = rand();
		
		of.write((char*)&i,sizeof(i));
		of.write((char*)&f,sizeof(f));
	}
	of.close();
	
	ifstream iif("grupo.dat",ios::binary);
	for (int i = 0; i < 200; i++)
	{
//		int i;
//		float f;
		iif.read((char*)&i,sizeof(i)); //sizeof(int): Lo mismo que poner 4 directamente
		iif.read((char*)&f,sizeof(f)); //sizeof(float): Lo mismo que poner 8 directamente
		
		cout << "Entero: " << i << endl << "Float: " << f << endl;
	}
	iif.close();
	
	return 0;
}

