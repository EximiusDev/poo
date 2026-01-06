#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[]) {
	vector<string> s;
	string aux;
	ifstream archi("palabras11.txt");
	cout<<(char*)archi;
	if (archi){
		while (archi>>aux){
			s.push_back(aux);
		}
		archi.close();
	} else{
		cout<<"no se pudo abrir el archivo\n";
		return 1;
	}
	cout<<"Cantidad de palabras: "<< s.size()<<endl;
	cout<<"Lista leida:\n";
	for(string palabra:s)
		cout<< palabra <<" - ";

	sort(s.begin(), s.end());
	
	cout<<"\nLista ordenada:\n";
	for(string palabra:s)
		cout<< palabra <<" - ";
	
	ofstream archi2("palabras.txt",ios::trunc);
	for(string palabra:s)
		archi2<< palabra <<endl;
	archi2.close();
	
	
	
	
	
	return 0;
}

