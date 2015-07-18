#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
using namespace std;

int main() {
	string intput;
	int bit;
	char tmp;
	while (cin >> intput)
	{
		for (int i = intput.size() - 1; i > 0; i--)
		{
			if (intput[i] == '0')
				intput = intput.assign(intput, 0, i);
			else
				break;
		}
		bit = (int)intput.size() / 2;
		for (int i = 0; i <bit; i++)
		{
			tmp = intput[i];
			intput[i] = intput[intput.size() - i - 1];
			intput[intput.size() - i - 1] = tmp;
		}
		cout << intput << endl;
	}
	//system("PAUSE");
	return 0;
}