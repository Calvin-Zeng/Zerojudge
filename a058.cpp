#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <string.h> 
using namespace std;

int main() {
	int times;
	int number[100];
	int output[3] = {0};
	while (cin >> times)
	{
		for (int i = 0; i < times; i++)
		{
			cin >> number[i];
			output[number[i] % 3]++;
		}
		cout << output[0] << " " << output[1] << " " << output[2] << endl;
	
	}
	return 0;
}
