#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	srand(time(0));
	vector<int>v(20);
	vector<int>::iterator it;
	
	/*  //si no reserve espacio
	for(int i=0;i<20;i++) { 
		v.push_back(rand()%20);
	}
	*/
	/*for(int i=0;i<20;i++) { 
		v[i]=rand()%20;
	}
	*/
		
	
	//  for(/*vector<int>::iterator*/ auto it=v.begin();it!=v.end();it++)
	//	   *it=rand()%20;
			
	 //solo sirve para recorrer TODO el arreglo
	for(int &x:v)
		x=rand()%20;
	
	
	
	it=v.begin()+5;
	cout<<*it<<endl;
	it=v.insert(it,99);  //si no asigno queda apuntando a v.begin()+6
	cout<<*it<<endl;
	
	for(auto p:v)
		cout<<p<<"  ";
	
	cout<<endl<<endl;
	it=v.erase(it);
	v.erase(it,it+2);
	cout<<*it<<endl;
	
	for(auto p:v)
		cout<<p<<"  ";
	
	
	cout<<endl<<endl;
	it=v.begin()+7;
	cout<<*it<<endl;
	advance(it,-4);
	cout<<*it<<endl;
	advance(it,2);
	cout<<*it<<endl;
	auto it0= next(it,10);
	cout<<*it0<<endl;
	auto it1= next(it);
	cout<<*it1<<endl;
	auto it2= prev(it,3);
	cout<<*it2<<endl;
	auto it3= prev(it);
	cout<<*it3<<endl;
	
	
	cout<<endl;
	for(auto p:v)
		cout<<p<<"  ";
	
	
	int n;
	cout<<"\n\ningrese valor a eliminar: ";
	cin>>n;
	
	
	vector<int>::iterator itb;
	itb=remove(v.begin(),v.end(),n);
	
	v.erase(itb,v.end());
	
	
	
	cout<<endl;
	for(auto p:v)
		cout<<p<<"  ";
	cout<<endl;
	
	
	return 0;
}

