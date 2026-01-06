#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

unsigned int Fi(unsigned int n)
{
	if ( (n==1) || (n==2) )
		return 1;
	else
		return (Fi(n-1)*Fi(n-2));
}

int main(int argc, char *argv[]) {
	vector<unsigned int>Vec();
	for (int i = 3; i <= 10; i++)
	{
		cout << "Valor :" << i << " Fi(i) devuelve: " << Fi(i) << endl;
	}
	return 0;
}

