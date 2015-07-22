#include<stdio.h>
#include <iostream>
using namespace std;

int main() {
	int times, intput1;
	long long int intput2, intput3;
	while (cin >> times) {
		for (int i = 0; i < times; i++)
		{
			cin >> intput1 >> intput2>> intput3;
			switch (intput1)
			{
			case 1:
				cout << intput2 + intput3<<endl;
				break;
			case 2:
				cout << intput2 - intput3 << endl;
				break;
			case 3:
				cout << intput2 * intput3 << endl;
				break;
			case 4:
				cout << intput2 / intput3 << endl;
				break;
			}
		}
	}
	return 0;
}