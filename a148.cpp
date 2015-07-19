#include<iostream>

using namespace std;

int main() {
	int number;
	int intput[100];
	double sum;
	double avg;
	while (cin >> number) {
		sum = 0;
		for (int i = 0; i < number; i++)
		{
			cin >> intput[i];
			sum += intput[i];
		}
		avg = sum / number;
		//cout << avg << endl;
		if (sum / number <= 59)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
