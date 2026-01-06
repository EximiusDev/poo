//GUIA 8 - EJERCICIO 3.
/*Cree una lista de 15 enteros aleatorios entre 0 y 10. 
Muestre la lista antes y después de quitar los elementos repetidos. 
Haga una búsqueda bibliográfica sobre la clase ostream_iterator y utilice 
el algoritmo copy para mostrar la lista en pantalla y luego guardarla en un archivo.
*/
#include<iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;
int main( )
{
vector <float> v(15),v2(15);//crea un vector de 15 elem.
vector<float>::iterator p;
int i;
// asignamos valores flotantes
for (i=0; i<15; i++){
v[i]= ((float)(rand()%10));
//Muestro por pantalla
cout<<setw(2)<<v[i];
};
cout<<"\nordeno el arreglo"<<endl;
sort (v.begin(),v.end());
//Muestro con copy por pantalla
copy(v.begin(),v.end(),ostream_iterator<int,char>(cout," ")); 
cout << endl<<endl;

cout<<"Reeplazo con 0 los repetidos"<<endl;
unique_copy(v.begin(),v.end(),v2.begin());
v = v2;
//Muestro con copy por pantalla
copy(v.begin(),v.end(),ostream_iterator<int,char>(cout," ")); 
cout << endl<<endl;

cout<<"Elimino los 0 del vector"<<endl;
for(p=v.end();p!=v.begin();p--)
	if (*p==0) v.pop_back();
//Muestro con copy por pantalla
copy(v.begin(),v.end(),ostream_iterator<int,char>(cout," ")); 
cout << endl;
return 0;
}
