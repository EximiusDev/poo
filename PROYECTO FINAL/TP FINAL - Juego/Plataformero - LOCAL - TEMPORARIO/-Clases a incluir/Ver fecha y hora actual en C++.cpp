
#include <time.h>
#include <stdlib.h> ///
#include <stdio.h>  ///
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	char fecha[25];//ctime devuelve 26 caracteres pero tambien se podría usar un puntero de char
	time_t current_time; /// current_time es una clase de tipo time_t
	current_time = time(NULL); 
	
	cout<<endl;
	//cout<< time(NULL)<<endl;
	
	
	ctime(&current_time);
	strcpy(fecha, ctime(&current_time));
	
	string date = ctime(&current_time); /// pone un \n al final
	
	//printf("%s", fecha); /// Elimina el \n del final // printf("%s", fecha); == cout<<fecha<<endl;
	//cout<<fecha<<endl;
	cout<<ctime(&current_time)<<endl;
	cout<<date<<endl;
	
	
	
	return 0;
}

/*
	misString= misString.replaceFirst("\n", "");
	misString= misString.replaceAll("\\n\\r", "");
*/



/*
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;
	
int main(){
	
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;
	
	string s1 = (&tm, "%d-%m-%Y %H-%M-%S") ;
	
	cout<<endl;
	cout<<s1<<endl;
	cout<<t<<endl;
	/*
	printf(GetLocalTime);
	printf(GetTimeFormat);
	*/
	/*
	return 0;
}
*/

