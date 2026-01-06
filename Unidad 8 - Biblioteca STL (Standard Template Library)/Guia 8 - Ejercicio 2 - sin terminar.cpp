#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <list>
#include <numeric>
using namespace std;

int azar(){
	return rand()%25 ;
}

int main() {
	
	///int *v = new int[30];
	
	
	
	
	//// vector<int>v[15];
	vector<int>v;
	vector<int>v_copia;
	list<int>l;
	
	/*
	for(int i=0;i<15;i++) {
		v.push_back(rand()%99);
	}
	*/
	
	
	///generate(v.begin(),v.end(),rand()%99);
	generate(v.begin(),v.end(),azar());
	
	for(int aux:v){
		cout<<aux<<"  ";
	}
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<v.size();i++) { 
		
		v_copia.push_back(v[i]);
	}
	
	///cout<<*min_element(v.begin(),v.end())<<endl;
	auto minim = min_element(v.begin(),v.end());
	cout<<*minim<<endl;
	cout<<*max_element(v.begin(),v.end())<<endl;
	
	cout<<endl;
	cout<<endl;
	
	auto suma = accumulate(v.begin(),v.end(),0);
	
	cout<<suma<<endl;
	
	float prom = suma /(v.size()*1.0);
	cout<<prom<<endl;
	
	sort(v_copia.begin(),v_copia.end());
	
	for(int aux:v_copia){
		cout<<aux<<"  ";
	}
	cout<<endl;
	int mediana = v_copia[v_copia.size()/2];
	cout<<mediana<<endl;
	
	/// acululate sirve para acumular los elementos de una lista
	
	
	/// generate
	
	///delete []v;
	
	return 0;
}

