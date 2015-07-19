#include<iostream>
#include<string>

using namespace std;

int main() {
	int start, max;
	int sum;
	int count;
	while (cin >> start && cin >> max) {
		sum = 0;
		count = 0;
		while (1)
		{
			count++;
			sum += start++;
			if (sum > max)
			{
				cout << count << endl;
				break;
			}
			
		}
	}
	return 0;
}
