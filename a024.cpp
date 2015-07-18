#include <iostream>

using namespace std;

int gcd(int m, int n) {
	while (n != 0) {
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int main() {
	int intput1, intput2;
	while (cin >> intput1 && cin >>intput2){
		cout << gcd(intput1, intput2)<<endl;
	}
	//system("PAUSE");
	return 0;
}