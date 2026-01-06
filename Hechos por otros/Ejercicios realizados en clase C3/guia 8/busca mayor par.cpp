#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
bool es_par(int x,int y) {
	return (y%2==1) && (x%2==1);
}
*/


int main() {
	vector<int> v={91,41,37,121,561,457};
	
	auto itmax=max_element(v.begin(),v.end( ));
	while(*itmax%2!=0 && itmax!=v.end()){
		v.erase(itmax);
		itmax=max_element(v.begin(),v.end( ));
	}
	if(itmax!=v.end())
		  cout<<*itmax;
	else cout<<"no hay pares";
	return 0;
	
}
