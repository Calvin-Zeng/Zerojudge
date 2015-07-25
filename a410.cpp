#include<stdio.h>

int main()
{
	double a1,b1,c1,a2,b2,c2,tmp,x,y;
	while (scanf_s("%lf %lf %lf %lf %lf %lf", &a1,&b1,&c1,&a2,&b2,&c2) == 6){
		tmp = (a1 * b2) - (b1 * a2);
		if (tmp == 0) {
			if (a2 * c1 == a1 * c2)
				printf("Too many\n");
			else
				printf("No answer\n");
		}
		else{
			x = (c1*b2-b1*c2)/tmp;
			y = (c1*a2-a1*c2)/-tmp;
			printf("x=%.2lf\n", x);
			printf("y=%.2lf\n", y);
		}			
	}
	return 0;
}