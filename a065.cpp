#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
#include <math.h>
using namespace std;

int main() {
	string intput;
	while (cin >> intput)
	{
		for (int i = 0; i <intput.size()-1; i++)
		{
			cout << abs((intput[i+1] - '0') - (intput[i] - '0')) ;
		}
		cout << endl;
	}
	return 0;
}
