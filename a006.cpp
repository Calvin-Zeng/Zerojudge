#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int intput_1, intput_2, intput_3, de;
	while (cin >> intput_1 >> intput_2 >> intput_3) {
		de = intput_2*intput_2 - 4 * intput_1*intput_3;
		if (de>0) {
			cout << "Two different roots x1=" << (-intput_2 + pow(de, 0.5)) / (2 * intput_1) << " , " << "x2=" << (-intput_2 - pow(de, 0.5)) / (2 * intput_1) << endl;
		}
		else if (de == 0) {
			cout << "Two same roots x=" << -intput_2 / (2 * intput_1) << endl;
		}
		else {
			cout << "No real root" << endl;
		}
	}
	return 0;
}
