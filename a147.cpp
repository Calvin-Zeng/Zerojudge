#include<iostream>

using namespace std;

int main() {
	int intput1;
	while (cin >> intput1) {
		for (int i = 0; i < intput1; i++)
		{
			if (i != 0 && i % 7 != 0)
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
