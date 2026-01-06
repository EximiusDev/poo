#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Vector{
	int *m_data;
	int m_n;
public:
	Vector (int n){
		m_n=n;
		m_data=new int[m_n];
		srand(time(0));
		for(int i=0;i<m_n;i++) { 
			m_data[i]=rand()%10;
		}
	}
	
	Vector (const Vector &v2){
		m_n = v2.m_n;
		m_data= new int [m_n];
		for(int i=0;i<m_n;i++) { 
			*(m_data+i)=*(v2.m_data+i);
		}
	}
	
	Vector (Vector &&v2){
		m_n = v2.m_n;
		m_data = v2.m_data;
		// dejar a v2 en un estado válido
		v2.m_data = nullptr;
		v2.m_n = 0;
	}
	
	~Vector(){if (m_data!=nullptr) delete[]m_data;}
		
	int VerN(){return m_n;}
	int VerElem(int x){return *(m_data+x);}
};

int main(int argc, char *argv[]) {
	Vector a(10);
	cout<<"\n\na: ";
	for(int i=0;i<a.VerN();i++) { 
		cout<<" "<<a.VerElem(i);
	}
	
	Vector v = a;
	cout<<"\n\nv: ";
	for(int i=0;i<v.VerN();i++) { 
		cout<<" "<<v.VerElem(i);
	}
	
	cout<<"\n\na: ";
	for(int i=0;i<a.VerN();i++) { 
		cout<<" "<<a.VerElem(i);
	}
	
	cout<<"\n\nw: ";
	Vector w = move(a);
	for(int i=0;i<w.VerN();i++) { 
		cout<<" "<<w.VerElem(i);
	}
	
	cout<<"\n\na: ";
	for(int i=0;i<a.VerN();i++) { 
		cout<<" "<<a.VerElem(i);
	}
	cout<<endl;
	
	
	
	
	return 0;
}

