#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int azar(){
	return rand()%10+10;
}

int main(int argc, char *argv[]) {
	vector <int> v(30);
	vector<int>::iterator p,q;

	
	generate(v.begin(),v.end(),azar);
	
	
	/*mejor seria
	vector <int> v(15,0);
	for(int i=0;i<30;i++) {
	  v[i] = rand()%100;
	}
	*/
	
	cout<<"Vector Original:\n";
		for (p=v.begin();p!=v.end();p++)
		cout<<*p<<" ";
	
	cout<<endl;
	
	sort(v.begin()+9,v.begin()+20);
	reverse(v.begin()+9,v.begin()+20);
	
	//sort(v.rbegin()+9,v.rbegin()+20);
	
	cout<<"Vector Ordenado entre posicion 10 y 20:\n";
		for(int x:v) cout<<x<<" ";
	cout<<endl;
	
	vector <int> w;
	cout<<"Vector ordenado Extraido:\n";
	copy (v.begin()+9,v.begin()+20,back_inserter(w));
	for(int x:w)
		cout<<x<<" ";
	cout<<endl;
	
	int n;
	cout<<"\ningrese valor: ";
	cin>>n;
	
	cout<<"cantidad a eliminar: "<<count(v.begin(),v.end(),n)<<endl;
	
	q=remove(v.begin(),v.end(),n);
	v.erase(q,v.end());
	for (auto p : v) cout<<p<<" ";

	//rta: no porque no acceden a la estructura interna del contenedor. a lo sumo retornan un iterador
		return 0;
}

