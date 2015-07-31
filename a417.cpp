#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int extent,length,times,turn,number;
	int output[100][100] = {0};
	scanf("%d", &times);
	while (times--){
		scanf("%d %d", &extent, &turn)==2;
		number = 0;
		for (int circle = 0; circle <= extent/2; circle++){
			length = extent - circle-1 ;
			if (turn==1)
			{
				for (int right = circle; right <= length; right++)
					output[circle][right] = ++number;
				for (int down = circle + 1; down <= length; down++)
					output[down][length] = ++number;
				for (int left = length - 1; left >= circle; left--)
					output[length][left] = ++number;
				for (int up = length - 1; up > circle; up--)
					output[up][circle] = ++number;
			}
			else if(turn == 2) {
				for (int down = circle; down <= length; down++)
					output[down][circle] = ++number;
				for (int right = circle+1; right <= length; right++)
					output[length][right] = ++number;
				for (int up = length - 1; up > circle; up--)
					output[up][length] = ++number;
				for (int left = length; left > circle; left--)
					output[circle][left] = ++number;
			}

		}
		turn = 0;
		for (int i = 0; i < extent; i++){
			for (int y = 0; y < extent; y++){
				printf("%5d", output[i][y]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}