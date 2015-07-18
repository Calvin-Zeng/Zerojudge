#include <iostream>
#include <string.h> 
#include <sstream>
using namespace std;

int main() {
	string intput;
	int bit,check;
	while (getline(cin, intput, '\n')) {
		check = 0;
		bit = (int)intput.size() / 2;
		for (int i = 0; i <bit; i++)
		{
			if (intput[i]!= intput[intput.size() -i-1])
			{
				check++;
				break;
			}
		}
		if (check==0)
			cout << "yes"<<endl;
		else
			cout << "no" << endl;
	}
	//system("PAUSE");
	return 0;
}