#include <iostream>
#include <string.h> 
using namespace std;


int main() {
	int num1, num2;
	while (cin >> num1 >> num2) {
		int x = 0, y = 0;
		int input[10][10];  //int input[num1][num2];    //zerojudge上執行沒有問題，但Visual Studio 2015中會有問題
		for (x = 0;x<num1;x++) {
			for (y = 0;y<num2;y++) {
				cin >> input[x][y];
			}
		}
		for (x = 0;x<num2;x++) {
			for (y = 0;y<num1;y++) {
				cout << input[y][x] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
