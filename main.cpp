#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
	
	list<const char*>rosen = {"田端","日暮里","西日暮里"};

	for (list<const char*>::iterator itr = rosen.begin();
		itr != rosen.end();
		itr++)
	{
		cout << *itr << endl;
	}
		return 0;
}


