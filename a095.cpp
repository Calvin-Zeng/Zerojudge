#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int intput1, intput2;
	while (cin >> intput1 >> intput2) {
		cout << (intput1 == intput2 ? intput2 : intput2 + 1) << endl;
	}
	return 0;
}