#include<iostream>
using namespace std;

int cut(int n)
{
	if (n == 1) return 2;
	else return cut(n - 1) + ((n*n - n + 2) / 2);
}

int main(void)
{
	int n;
	while (cin >> n) {
		cout << cut(n) << endl;
	}
	return 0;
}