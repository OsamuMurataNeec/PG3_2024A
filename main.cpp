#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
	
	list<const char*>rosen =
	   {"komagome","tabata","nippori"};

	for (auto itr = rosen.begin();
		itr != rosen.end();
		itr++)
	{
		cout << *itr << endl;
	}

	cout << endl;


	for (list<const char*>::iterator itr = rosen.begin();
		itr != rosen.end(); itr++) {
		if (strcmp(*itr, "nippori") == 0) {
			itr = rosen.insert(itr, "nishi_nippori");
			++itr;
		}
	}
	
	for (list<const char*>::iterator itr = rosen.begin();
		itr != rosen.end();
		itr++)
	{
		cout << *itr << endl;
	}


return 0;
}


