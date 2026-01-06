#include <iostream>
using namespace std;

class VectorDinamico{
private:
	int *_v;
	int _t;
public:
	VectorDinamico(int x){
		_v = new int [x];
		_t = x;
		for(int i=0;i<x;i++) { 
			_v[i]=rand()%100+500;
		}
	}
	
	~VectorDinamico(){
		delete []_v;
	}
		
	void Duplicar(){
		_t=2*_t;
		int *aux= new int [_t];
		for(int i=0;i<_t/2;i++) { 
			aux[i]=_v[i];
		}
		for(int i=_t/2;i<_t;i++) { 
			aux[i]=rand()%100+500;
		}
		delete []_v;
		_v=aux;
		// aux=nullptr;
		
		
	}
	int VerElemento(int num){
		return _v[num];
	};
	void vervector(){
		for(int i=0;i<_t;i++) { 
			cout<<_v[i]<<"\n";
		}
	}
};

int main() {
	
	VectorDinamico V1(3);
	V1.vervector();
	V1.Duplicar();
	V1.vervector();
	
	return 0;
}

