#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int * Max_element(int *ini,int *fin){
	int Size=fin-ini;           //no van asteriscos
	int mayor=0,*dirmayor=nullptr;
	for(int i=0;i<Size;i++) { 
		if(*(ini+i)>mayor){
			mayor=*(ini+i);
			dirmayor=ini+i;
		}
	}
	return dirmayor;
}
int main() {
	int *p=new int[10];
	srand(time((0)));
	for(int i=0;i<10;i++) { 
		*(p+i)=rand()%1000;
		cout<<*(p+i)<<endl;
	}
	int  *Mayor = Max_element(p,p+10);
	cout<<"\nmayor: "<<*Mayor<<endl;
	delete[]p;
	return 0;
}
	
