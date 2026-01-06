#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
void elimina_repetidos(list <T> &v){
	for(typename list<T>::iterator it_i=v.begin(), it_f=v.end() ; it_i != it_f; ++it_i){
		it_f = remove( next(it_i), it_f, *it_i);   //acordarse de incluir algorithm
		it_f = v.erase(it_f,v.end());      //debo asignarlo porque si no queda corrompido   it_f...
	}
}


int main(int argc, char *argv[]) {
	list <int>x={1,2,3,4,1,2,3,4,7,9,67,4,3,6,8,3,5};
	elimina_repetidos(x);
	for(auto a:x)
		cout<<a<<"   ";
	return 0;
}


/*
{1,2,3,4,2,3,4,7,9,67,4,3,6,8,3,5,5}
^                                ^
{1,2,3,4,3,4,7,9,67,4,3,6,8,3,5,5,5}
^                            ^
{1,2,3,4,4,7,9,67,4,6,8,5,5,5,5,5,5}
^                  ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^            ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^          ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^        ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^      ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^   ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^ ^
{1,2,3,4,7,9,67,6,8,5,5,5,5,5,5,5,5}
^

*/


