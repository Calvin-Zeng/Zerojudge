#include<iostream>
#include<string>

using namespace std;

int main() {
	int times;
	int sum[100];
	string intput;
	while (cin >> times) {
		for (int i = 0; i < times; i++)
		{
			cin >> intput;
			sum[i] = 1;
			for (int y = 0; y < intput.size(); y++)
			{
				
				sum[i] *= (intput[y]-'0');
				//cout << "i:" << i << "-" << "intput[y]:"<< intput[y] - '0' <<"Á`©M"<<sum[i] << endl;
			}
		}
		for (int i = 0; i < times; i++)
		{
			cout << sum[i] << endl;
		}
		
	}
	return 0;
}
