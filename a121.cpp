#include<iostream>
#include<math.h>

using namespace std;

int prime[5150] = { 0 };
int m = 0;
void findPrime() {
	char judge[50000] = { 0 };
	for (int a = 2; a <= 50000; a++) {
		if (judge[a] == 0) {
			prime[m++] = a;
			for (int b = 2; b*a <= 50000; b++) {
				judge[b*a] = 1;
			}
		}
	}
}
int is_prime(int num) {
	if (num == 1) return 0;
	int num_sqrt = sqrt(num);
	for (int i = 0; i<m && prime[i] <= num_sqrt;i++) {
		if (num%prime[i] == 0 && num / prime[i] != 1)
			return 0;
	}
	return 1;
}

int main() {
	findPrime();
	int intput1,intput2;
	int count;
	while (cin >> intput1>> intput2) {
		count = 0;
		for (int i = intput1; i <= intput2; i++)
		{
			if (i != 2 && i != 3 && i % 2 == 0 && i % 3 == 0)
				continue;
			count += is_prime(i);

		}
		cout << count<<endl;
	}
	return 0;
}
