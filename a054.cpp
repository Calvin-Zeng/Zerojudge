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
	int check;
	char city_26[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int city[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 };
	while (cin >> intput)
	{
		sum = 0;
		for (int x = 8;x>0;x--) {
			sum = sum + (intput[abs(x - 8)] - '0')*(x);
		}
		tmp = intput[intput.size()-1]-'0';
		if (tmp == 0)
			tmp = 10;
		for (int x = 0; x < 26; x++){
			check=(sum + ((city[x] % 10) * 9 + city[x] / 10));
			if (10-(check%10)==tmp)
					cout << city_26[x];
		}
		cout << endl;
		if (intput == "")
			break;
	}
	return 0;
}
