#include<iostream>
using namespace std;


int main(void)
{
	int intput;
	while (cin >> intput) {
		if (intput >=0 && intput<=10)
		{
			cout << intput * 6 << endl;
		}
		else if (intput >= 11 && intput <= 20)
		{
			intput = intput - 10;
			cout << 60 + intput * 2 << endl;
		}
		else if(intput >= 21 && intput <= 39)
		{
			intput = intput - 20;
			cout << 80 + intput * 1 << endl;
		}
		else if (intput>=40)
		{
			cout << "100" << endl;
		}
	}
	return 0;
}