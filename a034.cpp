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
string tenCarry2twoCarry(int intput) {
	int output;
	if(intput==1)
		return "1";
	else
		return tenCarry2twoCarry(intput / 2)+ int2str(intput % 2);

}
int main() {
	string output=("");
	int intput, business;
	while (cin >> intput)
	{
		cout << tenCarry2twoCarry(intput) << endl;
	}
	//system("PAUSE");
	return 0;
}