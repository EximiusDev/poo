#include <iostream>
#include <vector>
using namespace std;

class animal{
	string tipo, especie;
public:
	animal(string t, string e):tipo(t), especie(e){}
	string vertipo(){return tipo;}
	string verespecie(){return especie;}
	virtual string desplazarse()=0;
    virtual ~animal(){}
};
class mamifero:public animal{
public:
	mamifero(string t):animal(t,"mamifero"){}
	string desplazarse(){return "camina";}
};
class ave:public animal{
public:
	ave(string t):animal(t,"ave"){}
	string desplazarse(){return "vuela";}
};
class pez:public animal{
public:
	pez(string t):animal(t,"pez"){}
	string desplazarse(){return "nada";}
};

int main(int argc, char *argv[]) {
	vector<animal*> parque;
	parque.push_back(new pez("dorado"));
	parque.push_back(new pez("bagre"));
	parque.push_back(new mamifero("oso"));
	parque.push_back(new ave("aguila"));
	parque.push_back(new pez("vieja del agua"));
	parque.push_back(new pez("tiburon"));
	parque.push_back(new mamifero("perro"));
	parque.push_back(new ave("paloma"));
	parque.push_back(new mamifero("foca"));
	
	for(int i=0;i<parque.size();i++) { 
		cout<<(*parque[i]).vertipo()<<"   "<<
			parque[i]->verespecie()<<"   "<<
			parque[i]->desplazarse()<<endl;}
	
	for(int i=0;i<parque.size();i++) 
		delete parque[i];
		
	
	return 0;
}

