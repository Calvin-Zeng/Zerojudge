#include<iostream>
using namespace std;

int main() {
	int intput_row, intput_1, intput_2, intput_3, intput_4;
	while (cin >> intput_row) {
		for (int x = 0;x<intput_row;x++) {
			cin >> intput_1 >> intput_2 >> intput_3 >> intput_4;
			if (intput_2 - intput_1 == intput_3 - intput_2) {
				cout << intput_1 << " " << intput_2 << " " << intput_3 << " " << intput_4 << " " << intput_4 + (intput_3 - intput_2) << endl;

			}
			else {
				cout << intput_1 << " " << intput_2 << " " << intput_3 << " " << intput_4 << " " << intput_4*(intput_3 / intput_2) << endl;
			}
		}

		return 0;
	}
}
