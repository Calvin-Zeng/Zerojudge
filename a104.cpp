#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int number, intput[1000],tmp;
	while (cin >> number) {
		for (int i = 0; i < number; i++)
		{
			cin >> intput[i];
			for (int y = 0; y < i; y++)
			{
				if (intput[i]<intput[y])
				{
					tmp = intput[y];
					intput[y] = intput[i];
					intput[i] = tmp;
				}
			}
		}
		for (int i = 0; i < number; i++)
		{
			cout << intput[i]<<" ";
		}
		cout << endl;
	}
	return 0;
}