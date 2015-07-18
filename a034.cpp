#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
using namespace std;

string int2str(int i) { //intÂàstring
	stringstream ss;
	string convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}

int main() {
	string output=("");
	int intput, business;
	while (cin >> intput)
	{
		output = ("");
		business = intput;

		while (1)
		{
			if (intput == 1)
			{
				output = "1";
				break;
			}
			output = int2str(business % 2) + output;
			business = (int)business / 2;
			
			if (business ==1)
			{
				output = int2str(business % 2) + output;
				break;
			}
		}		
		cout << output << endl;
	}
	//system("PAUSE");
	return 0;
}