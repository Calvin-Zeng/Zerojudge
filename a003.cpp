#include<iostream>
using namespace std;

int main() {
	int intput_mounth, intput_day;
	while (cin >> intput_mounth && cin >> intput_day) {
		switch ((intput_mounth * 2 + intput_day) % 3) {
		case 0:
			cout << "´¶³q" << endl;
			break;
		case 1:
			cout << "¦N" << endl;
			break;
		case 2:
			cout << "¤j¦N" << endl;
			break;
		}
	}
	return 0;
}
