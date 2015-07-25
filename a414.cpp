#include <stdio.h>
#include <string.h>

void tenCarry2twoCarry(int intput,char *output) {
	for (int i = 0; intput!=0; i++)
	{
		if (intput % 2 == 0) {
			output[i] = '0';
			output[i+1] = '\0';
			break;
		}
		 //sprintf(&output[i], "%d", intput%2);
		output[i] = '1';
		intput=intput >> 1;
	}
}
int main()
{
	int intput,carry_sum,len;
	char twoCarry[100];
	while (scanf("%d",&intput) == 1){
		if (intput == 0)
			break;
		//_itoa_s(intput, twoCarry, 2); non-use in linux
		tenCarry2twoCarry(intput,twoCarry);
		//printf("%s:%d\n", twoCarry, strlen(twoCarry));
		len = strlen(twoCarry);
		carry_sum = 0;
		if ((twoCarry[0] - '0') == 1) {
			for (int i =0 ; i <len; i++){
				if ((twoCarry[i] - '0') == 1) 
					carry_sum++;
				else
					break;
			}
			printf("%d\n", carry_sum);
		}else
			printf("0\n");
	}
	return 0;
}