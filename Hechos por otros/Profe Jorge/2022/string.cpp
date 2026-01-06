#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	//        01234567890123456789012345678901
	string s="programacion orientada a objetos";
	//cout<<"="<<s.erase(12,10)<<"=";
	
	/*string a="orientada";
	string r="lanzada";
	cout<<s.replace(s.find(a),a.length(),r);
	*/
	int p=0;
	string ree="..";
	p=s.find_first_not_of("aeiou");
	while( p != string::npos){
		s.replace(p,1,ree);
		p=s.find_first_not_of("aeiou",p+ree.length());
	}
		
	//cout<<s;
	
	//cout<< s.find_first_of("aeiou",3);

	s="materia=programacion orientadaa objetos";
	string pp, sp;
	pp=s.substr(0,s.find("=",0));
	sp=s.substr(s.find("=",0)+1);
	cout<<pp<<endl;
	cout<<sp<<endl;
	
	
	
	return 0;
}

