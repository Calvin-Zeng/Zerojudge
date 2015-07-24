#include <stdio.h>

bool isleapyear(int y) {
	return (y % 4 == 0 && y % 100 || y % 400 == 0);
}
int sum(int y, int m, int d) {
	int cnt = y * 365+d;
	int year = y - 1;
	cnt += year / 4 + 1;
	cnt -= year / 100 + 1;
	cnt += year / 400 + 1;
	for (int i = 1; i < m; ++i) {
		if (i == 2)
			cnt += 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			cnt += 30;
		else
			cnt += 31;
	} 
	if (m > 2 && isleapyear(y)) ++cnt;
	return cnt;
}
int Count(int y1, int m1, int d1, int y2, int m2, int d2) {
	return sum(y2, m2, d2) - sum(y1, m1, d1);
}

int main() {
	int y1, m1, d1, y2, m2, d2;
	while (scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2) == 6) {
		if (Count(y1, m1, d1, y2, m2, d2) >= 0)
			printf("%d\n", Count(y1, m1, d1, y2, m2, d2));
		else
			printf("%d\n", -(Count(y1, m1, d1, y2, m2, d2)));
	}
	return 0;
}