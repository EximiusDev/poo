#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    vector<string>v;
	ifstream archi("palabras.txt");
	string s;
	if(!archi.is_open()){
		cout<<"error de apertura\n";
		return 1;
	}
	while(archi>>s){
		v.push_back(s);
	}
	archi.close();
	
	for(string x:v)
		cout<<x<<"\n";
	
	sort(v.begin(),v.end());

	cout<<"\nlista ordenada\n";
	ofstream archi2("palabras.txt",ios::trunc);
	for(size_t i=0;i<v.size();i++) 
		archi2<<v[i]<<"\n";
	
	archi2.close();
	
	return 0;
}

