#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
	int times;
	int start;
	int end;
	int sum;
	int tmp;
	while (cin >> times)
	{
		for (int i = 1; i <= times; i++)
		{
			sum = 0;
			cin >> start;
			cin >> end;
			for (int y = (int)sqrt(start); y < end; y++)
			{
				tmp = y*y;
				if (tmp>=start && tmp<=end)
				{
					sum += tmp;
				}
				else if(tmp>end)
				{
					cout << "Case " << i << ": " << sum << endl;
					break;
				}
				
			}
		}
	
	}
	return 0;
}
