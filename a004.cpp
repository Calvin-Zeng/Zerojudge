#include<iostream>
using namespace std;

int main() {
	int intput_year;
	while (cin >> intput_year) {
		if (intput_year % 400 == 0) {
			cout << "閏年" << endl;
		}
		else if (intput_year % 4 == 0 & intput_year % 100 != 0) {
			cout << "閏年" << endl;
		}
		else {
			cout << "平年" << endl;
		}
	}
	return 0;
}
