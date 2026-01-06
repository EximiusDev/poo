#include <iostream>
using namespace std;

template<typename T>
void clamp(T &x, T li, T ls){
    if (x<li) x=li;
	if (x>ls) x=ls;
}

int main(int argc, char *argv[]) {
		int m; 
		cin>>m;
		//string a="dado",b="mesa";
		clamp(m,5,12);
	    cout<<"m: "<<m<<endl;
		
		string h; 
		cin>>h;
		clamp(h,"mesa"s,"silla"s);  //  la letra 's' a continuacion del las constantes de caracter, se coloca para indicar que dicha constante es un string y no un cstring
		cout<<"h: "<<h<<endl;
		
	return 0;
}

      
