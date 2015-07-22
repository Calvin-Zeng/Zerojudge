#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int times,tmp;
	int intput[1000];
	while (cin >> times) {
		for(int i=0;i<times;i++){
			cin >>intput[i];
			for (int y = 0; y < i; y++)
			{
				if (intput[i]>intput[y])
				{
					tmp = intput[y];
					intput[y] = intput[i];
					intput[i] = tmp;
				}
				if (intput[i]%10<intput[y]%10)
				{
					tmp = intput[y];
					intput[y] = intput[i];
					intput[i] = tmp;
				}
			}
		}
		for (int i = 0; i < times; i++)
		{
			cout << intput[i]<<" ";
		}
		cout << endl;
	}
	return 0;
}
