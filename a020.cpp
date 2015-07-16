#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <string.h> 
using namespace std;

int main() {
	string intput;
	int sum = 0;
	int tmp = 0;
	int city[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 };
	while (cin >> intput)
	{
		tmp = city[intput[0] - 65];
		//cout << tmp<<endl;
		sum = (tmp % 10) * 9 + tmp / 10 + intput[9] - '0';
		//cout << sum<<endl;
		for (int x = 8;x>0;x--) {
			sum = sum + (intput[abs(x - 9)] - '0')*(x);
			//cout << sum<<endl;
		}
		//cout << sum << endl;
		if (sum % 10 == 0)
			cout << "real" << endl;
		else
			cout << "fake" << endl;
		if (intput == "")
			break;
	}
	return 0;
}
