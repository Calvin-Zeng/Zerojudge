#include<stdio.h>
int main()
{
	int a, b, i, j, n, ans[4], input[4], check[4];
	while (scanf_s("%d %d %d %d", &ans[0], &ans[1], &ans[2], &ans[3]) == 4)
	{
		scanf_s("%d", &n);
		while (n--)
		{
			a = b = 0;
			for (i = 0; i<4; i++)
			{
				scanf_s("%d", &input[i]);
				if (ans[i] == input[i])
				{
					a++;
					check[i] = 1;
				}
				else
					check[i] = 0;
			}
			for (i = 0; i<4; i++)
				if (check[i] != 1)
					for (j = 0; j<4; j++)
						if (check[j] == 0 && (input[i] == ans[j]) && j != i)
						{
							b++;
							check[j] = 2;
							break;
						}
			printf("%dA%dB\n", a, b);
		}
	}
	return 0;
}