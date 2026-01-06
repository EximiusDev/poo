#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char *argv[]) {
	vector <int> v;
	vector<int>::iterator p;
	srand(time(0));
	for(int i=0;i<11;i++) {
		v.push_back(rand()%100);
	}
	
	for(size_t i=0;i<v.size();i++) { 
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for (vector<int>::iterator it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	
	cout<<endl;

	for(int x:v)
		cout<<x<<" ";        //no sirve cuando quiero saber la posición
	
	cout<<"\nmayor: "<<*max_element(v.begin(),v.end());
	cout<<"\nmenor: "<<*min_element(v.begin(),v.end());
	cout<<"\nsuma: "<<accumulate(v.begin(),v.end(),0);
	cout<<"\npromedio: "<<accumulate(v.begin(),v.end(),0)/(1.0*v.size());
	
	sort(v.begin(),v.end());
	cout<<endl;
	for(int x:v)
		cout<<x<<" ";
	cout<<"\nmediana: "<<v[v.size()/2];
	
	int n;
	cout<<"\ningrese valor: ";
	cin>>n;
	
	p=find(v.begin(),v.end(),n);
	
	
	if (p!=v.end())
		{cout<<"el valor esta en la posicion "<<
			distance(v.begin(),p);
			//p-v.begin();
		}
	else cout<<"valor no encontrado";
	return 0;
}

