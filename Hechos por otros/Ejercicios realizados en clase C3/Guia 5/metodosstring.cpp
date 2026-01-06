#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {

	string c("01234567890123456789012345678901234567890");
	string s("universidad nacional del litoral");
	string a("juan"),b("carlos");
	//string::size_type p;
	//getline(cin,s);
	cout<<c<<endl;
	cout<<s<<endl;

	
//out<<s.length()<<endl;
//cout<<s.size()<<endl;



/*0	
	cout<<s[9]<<endl;
	cout<<s.at(9)<<endl;

//	
	s=a+" "+b+" perez";
	cout<<s<<endl;

 //

	cout<<string::npos<<endl;
 cout<<s.find("lx")<<endl;
	cout<<s.find("acio");
*/
   //s.erase(s.find("a"),s.rfind("a")-s.find("a")+1);
	   
	//cout<<b<<endl;
	//cout<<s<<endl;
//s.insert(2,a);
//cout<<s;
	//cout<<s.erase(4,10);
	//cout<<s.erase(4);
	cout<<s.replace(6,10,"-----");
	
//	string sn="16.3";
//	float  n;
//	n=atof(sn.c_str());             //atoi o atol
//	cout<<3*n;
	
//	char letra;
//	string sm;
//	letra=toupper(s.at(4));
//	sm=letra;
//	s.replace(4,1,sm);
//	cout<<s<<endl;
	
	
		return 0;
}

//	cout<<char('a' ^ 0x20); ó+32
