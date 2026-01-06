#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
struct par{
	int n;
	string s;
};

bool parmenor(par a, par b){
	return a.n<b.n;
}

bool parigual(par a, par b){
	return a.n==b.n && a.s==b.s;
}
		

template <typename T>
vector <T> ListAVector(list<T> l){
	vector <T> v(l.begin(),l.end());
	sort(v.begin(),v.end());
	auto it=unique(v.begin(),v.end());
	v.erase(it,v.end());
	//cout<<"apunta it a "<<distance(v.begin(),it)<<endl;
	return v;
}
	
vector<par> ListAVector(list<par> l){
	vector <par> v(l.begin(),l.end());
	sort(v.begin(),v.end(),parmenor);
	auto it=unique(v.begin(),v.end(),parigual);
	//cout<<"apunta it a "<<distance(v.begin(),it)<<endl;
    v.erase(it,v.end());
	return v;
}

 

int main(int argc, char *argv[]) {
	list<int>l1={2,3,4,5,6,5,1,4,7,5,8,9,4,2};
	list<float>l2={1.2,2.3,3.4,5.6,1.2,1.2,3.4,7.8};
	list<par>l3={{10,"ana"},{15,"juan"},{14,"luis"},{10,"ana"},{14,"luis"},};
	list<string>l4={"ana","juan","luis","ana","luis","carlos"};
	vector<int>v1=ListAVector(l1);
	vector<float>v2=ListAVector(l2);
	vector<par>v3=ListAVector(l3);
	vector<string>v4=ListAVector(l4);
	
	for(auto x:v1) 
		cout<<x<<"  ";
	cout<<endl<<endl;
	for(auto x:v2) 
		cout<<x<<"  ";
	cout<<endl<<endl;
	for(auto x:v3) 
		cout<<x.n<<"  "<<x.s<<endl;
	cout<<endl<<endl;
	for(auto x:v4)
		cout<<x<<"  ";
	cout<<endl<<endl;
	
	return 0;
}

