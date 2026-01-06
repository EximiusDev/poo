#include <iostream>
#include <tuple>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

//b)

tuple<int,int> procesa_secuencia(vector <int>&x){
	//i)
	if (x.size()%2 !=0)
		x.erase(x.begin()+x.size()/2);     //no le sumo 1 porque empieza de 0
	//ii)
	sort(x.begin(),x.begin()+x.size()/2);
	sort(x.begin()+x.size()/2,x.end());
	reverse(x.begin()+x.size()/2,x.end());
	//iii
	int s1=accumulate(x.begin(),x.begin()+x.size()/2,0);
	int s2=accumulate(x.begin()+x.size()/2,x.end(),0);
	return make_tuple(s1,s2);
}


int main(int argc, char *argv[]) {
	//a)
	vector<int> v;
	int d;
	fstream ar("data20211104.txt",ios::in);
	while(ar>>d)
		v.push_back(d);
	ar.close();

	//c)
	int suma1,suma2;
	tie(suma1,suma2)=procesa_secuencia(v);
	cout<<"promedio primer mitad: "<<suma1/(v.size()/2)<<endl;
	cout<<"promedio segunda mitad: "<<suma2/(v.size()/2)<<endl;
	cout<<"\nListado:\n";
	ar.open("data20211104.txt",ios::out|ios::trunc);
	for (int d:v)
	    cout<<d<<"  ";
		ar<<d<<endl;
	ar.close();
	
	return 0;
}

