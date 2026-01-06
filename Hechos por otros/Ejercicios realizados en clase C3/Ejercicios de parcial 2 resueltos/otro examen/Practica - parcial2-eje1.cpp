#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Par{
	int val1;
	int val2;
};

Par procesa_secuencia(vector<int> &v){
	
	int mediana = v.size()/2;
	vector<int>::iterator it_med = v.begin()+ mediana;
	//auto it_med = v.begin()+ mediana;
	
	if(v.size()%2==1) 	it_med = v.erase(it_med);
	
	///for(int &x:v)cout<<x<<"  ";
	//cout<<endl;
	
	sort(v.begin(), it_med);
	sort(it_med, v.end());
	reverse(it_med, v.end());
	
	///for(int &x:v)cout<<x<<"  ";
	
	Par suma;
	suma.val1 = accumulate(v.begin(), it_med,0);
	suma.val2 = accumulate(it_med, v.end(),0);
	
	/* me equivoque, no era el mayor, era la suma
	Par max;
	auto max1 = max_element(v.begin(), it_med);
	auto max2 = max_element(it_med, v.end());
	max.val1 = *max1;
	max.val2 = *max2;
	*/
	return suma;
}


int main() {
	
	int aux;
	vector<int>datos;
	
	ifstream archi("data20211104 - copia.txt");
	if(archi.is_open()){
		while(archi>>aux) datos.push_back(aux);
		archi.close();
	}
	
	for(int x:datos)cout<<x<<"  ";
	cout<<endl;
	
	Par suma = procesa_secuencia(datos);
	//cout<<endl;
	cout<<suma.val1<<"  "<<suma.val2<<endl;
	
	float prom1 = suma.val1/(datos.size()/2);
	float prom2 = suma.val2/(datos.size()/2);
	
	//cout<<endl;
	cout<<prom1<<"  "<<prom2<<endl;
	//cout<<endl;
	for(int x:datos) cout<<x<<"  ";
	
	ofstream escrib("data20211104 - copia(1).txt");
	if(escrib.is_open()){
		for(int x:datos) escrib<<x<<endl;
	}
	return 0;
}

