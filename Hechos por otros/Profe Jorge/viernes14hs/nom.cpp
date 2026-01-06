#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char s[30];
	strcpy(s,"juanito");
	//cout<<&s;
//	cout<<s<<"   "<<sizeof(s)<<"   "<<strlen(s);
	fstream f("nombres.dat",ios::binary|ios::in|ios::out|ios::trunc);
	f.write((char*)&s,sizeof(s));
	f.close();
	return 0;
}

