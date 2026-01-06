#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream archi("lista.txt");
	vector<string> v;
	string palabra;
	while( archi>>palabra){
		v.push_back(palabra);
		cout<<palabra<<"  "; 
	}
	archi.close();
	cout<<"\nCant palabras: "<<v.size()<<endl;
	cout<<endl;
	
	sort(v.begin(),v.end());
	for(unsigned int i=0;i<v.size();i++) { 
		cout<<v[i]<<"  "; 
	}
	
	ofstream sal("lista.txt",ios::trunc);
	for(string s:v)
       sal<<s<<endl; 
	sal.close();
	
	return 0;
}

