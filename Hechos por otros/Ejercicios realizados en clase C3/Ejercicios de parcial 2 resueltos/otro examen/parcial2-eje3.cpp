#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
using namespace std;

struct Ficha{
	int dni;
	string apellido, nombres;
};

bool operator==(Ficha a, Ficha b){
	return a.dni==b.dni && a.apellido==b.apellido && a.nombres==b.nombres;
}

template <typename T>
T mas_repetido(list<T> lis){
	T mas;
	int cant=0;
	for(T x:lis){
		int c=count(lis.begin(),lis.end(),x);
		if (cant < c){
			cant=c;
			mas=x;
		}
	}
	return mas;	
}


int main(int argc, char *argv[]) {
    list<string> ls;
	list<int> li;
	list<Ficha> lf;
	string s;
	int n;
	Ficha r;
	for(int i=0;i<10;i++) { 
		cin>>s;
		ls.push_back(s);
	}
	for(int i=0;i<10;i++) { 
		n=rand()%5;
		li.push_back(n);
	}
	
	ifstream ar("lista.txt");
	
	while(ar>>r.dni && ar.ignore() && getline(ar,r.apellido,',') && ar.ignore() && getline(ar,r.nombres))
		lf.push_back(r);
	
	//ó	
/*	
	while(ar>>r.dni && ar.ignore() && getline(ar,s)){
		r.apellido=s.substr(0,s.find(","));
		r.nombres=s.substr(s.find(",")+2,s.length());                    //sumo 2 por el espacio en blanco
		lf.push_back(r);
	}
	ar.close();
	*/
	
	for(string x:ls)
		cout<<x<<"  ";
	cout<<endl;
	for(int x:li)
		cout<<x<<"  ";
	cout<<endl;
	for(Ficha x:lf)
	   cout<<x.dni<<" "<<x.apellido<<" "<<x.nombres<<endl;
	cout<<endl;
	
	
	cout<<"se repite mas el string: "<<mas_repetido(ls)<<endl;
	cout<<"se repite mas el numero: "<<mas_repetido(li)<<endl;
	r=mas_repetido(lf);
	cout<<"se repite mas la ficha : "<<r.dni<<" "<<r.apellido<<" "<<r.nombres<<endl;
	return 0;
}

