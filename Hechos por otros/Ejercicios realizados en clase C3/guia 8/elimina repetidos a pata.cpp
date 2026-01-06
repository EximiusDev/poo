#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*bool operator==(int a, int b){
	return a==b;
}
*/
int main(int argc, char *argv[]) {
	vector<int>v= {1, 1, 1, 2, 2, 2, 3, 3, 3, 5, 5, 6, 7, 8, 9, 9, 9, 11, 12, 13, 13};
	
	/*for(size_t i=0;i<v.size()-1;i++) { 
		if(v[i]==v[i+1]){
			v.erase(v.begin()+i);
			i--;
		}
	}
	for(int a:v)
		cout<<a<<" ";
	*/
	auto it=unique(v.begin(),v.end());
	v.erase(it,v.end());
	for(int a:v)
		cout<<a<<" ";
	
	return 0;
}

