#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int doble(int x){
	return 2*x;
}

int main(int argc, char *argv[]) {
	int v[]={2,4,6,8,6,4,1,9,7,5};
	copy(&v[0],&v[0]+10,ostream_iterator<int>(cout," - "));
	cout<<endl;
	replace(&v[0],&v[0]+10,6,100);
	copy(&v[0],&v[0]+10,ostream_iterator<int>(cout," - "));
	cout<<endl;
	fill(&v[0]+3,&v[0]+7,99);
	copy(&v[0],&v[0]+10,ostream_iterator<int>(cout," - "));
	cout<<endl;
	transform(&v[0],&v[0]+10,&v[0],doble);
	copy(&v[0],&v[0]+10,ostream_iterator<int>(cout," - "));
	cout<<endl;
	
	return 0;
}

