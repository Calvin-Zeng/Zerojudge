#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
#include <math.h>
using namespace std;

string int2str(int i) { //intÂàstring
	stringstream ss;
	string convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}

int main() {
	int input1, input2,sum, number;
	string tmp;
	while (cin >> input1 && cin >> input2)
	{
		number = 0;
		for (int i = input1; i <= input2; i++)
		{
			//cout <<"i:" <<i<<"-"<<input1 << "-" << input2 << endl;
			tmp = int2str(i);
			sum = 0;
			for (int x = 0; x < tmp.size(); x++)
			{
				sum += pow(tmp[x] - '0', tmp.size());
			}
			if (sum==i)
			{
				number++;
				cout << sum <<" ";
			}
		}
		if (number ==0)
			cout << "none"<<endl;
		else
			cout<< endl;
	}
	//system("PAUSE");
	return 0;
}