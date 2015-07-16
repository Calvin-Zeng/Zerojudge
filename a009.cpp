#include<iostream>
#include <string> 

using namespace std;

string Decode(string intput) {
	int tmp;
	//cout << intput.size() << endl;
	for (int i = 0;i<intput.size();i++) {
		tmp = (int)intput[i];
		tmp -= 7;
		intput[i] = (char)tmp;
	}
	return intput;
}

int main() {
	string intput;
	while (cin >> intput) {
		cout << Decode(intput) << endl;
	}
	return 0;
}
