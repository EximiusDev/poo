#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

int pares(){
	return 2*rand()%100;
}


int main(int argc, char *argv[]) {
	list<int> l(10,0);  
	
	/*
	for(auto it=l.begin();it!=l.end();++it)
		*it=rand()%100;
	*/
	
	//generate(l.begin(),l.end(),rand);
	
	generate(l.begin(),l.end(),pares);
	
	
	for(int x:l)
		cout<<x<<" - ";
	cout<<endl;
	
	int v=42, p=5;
	
	
	list<int>::iterator it5=l.begin();
	//
	advance(it5,p);
	
	//for(int i=0;i<p;i++) it5++;   //no es la mas conveniente
	
	//ó 
	
	// auto it5=next(l.begin(),p);  //avanzo a la posicion de p
	
	
	l.insert(it5,v);
	
	for(int x:l)
		cout<<x<<" - ";
	cout<<endl;
	
	
	return 0;
}

