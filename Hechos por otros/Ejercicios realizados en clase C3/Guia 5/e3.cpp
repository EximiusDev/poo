#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;



int main(int argc, char *argv[]) {
	vector<string>alumnos;
    int alMaxPorComision=5;
	ifstream t("listado0.txt");
	string al;
	while(getline(t,al))
		alumnos.push_back(al);
	
	for(int i=0;i<alumnos.size();i++) { 
		cout<<setw(10)<<left<<alumnos[i]<<"  ";
	}
	int ncom=alumnos.size()/alMaxPorComision;
	if((alumnos.size() % alMaxPorComision)!=0) ncom++;
	cout<<endl;
	cout<<ncom<<endl;
	int alPorCom= alumnos.size()/ncom;
	int restoAlPorCom= alumnos.size()%ncom;
	
	cout<<alPorCom<<"----"<<restoAlPorCom<<endl;
	int a=0;
	for(int i=0;i<ncom;i++) {
		
		ofstream sal("comision"+to_string(i+1)+".txt",ios::trunc);
		for(int j=0;j<alPorCom;j++) {
			sal<<alumnos[a]<<endl; a++;
		}
		if(restoAlPorCom>0){
			sal<<alumnos[a]<<endl; a++;
		    restoAlPorCom--;
		}
		sal.close();
	}
	
	t.close();
}
