#include <iostream>
#include <string.h> 
using namespace std;

void out(int sudoku[10][10]) {
	int check = 1;
	int check_index = 0;
	int carry_1 = 0;
	int add_velue = 0;
	int index = 0;
	int carry_2 = 0;
	int small_3X3[10][10] = { 0 };

	for (int x = 0;x<9;x++) {
		for (int y = 0;y<9;y++) {
			//cin >> intput;
			//sudoku[x][y]=intput;
			sudoku[x][9] += sudoku[x][y];
			sudoku[9][x] += sudoku[x][y];
			index++;
			//cout << "順序" << carry_1+add_velue <<endl;
			small_3X3[0][carry_1 + add_velue] += sudoku[x][y];
			small_3X3[carry_1 + add_velue + 1][sudoku[x][y]]++;
			if (index == 3) {
				index = 0;
				carry_1++;
			}
			if (carry_1 == 3) {
				carry_1 = 0;
				check_index++;
			}
			if (check_index == 3) {
				add_velue += 3;
				check_index = 0;
			}

		}
	}

	for (int x = 0;x<9;x++) {
		for (int y = 0;y<9;y++) {
			//cout << "第" << x <<"的"<< y<<"="<<small_3X3[x][y] << endl;
			if (small_3X3[x + 1][y + 1] == 0)
				check = 0;
		}
		if (sudoku[9][x] == 45 || sudoku[x][9] == 45 || small_3X3[0][x] == 45) {

		}
		else {
			check = 0;
		}
		//cout <<small_3X3[x] <<endl;
	}

	if (check == 1)
		cout << "yes\n";
	else
		cout << "no\n";

	/*for(int x=0;x<10;x++){
	for(int y=0;y<10;y++){
	cout << sudoku[x][y] <<" ";
	}
	cout << endl;
	}*/
}
int main() {
	//這題輸入相當煩人~凸.凸
	int intput, sudoku[10][10] = { 0 };
	while (cin >> sudoku[0][0]) {
		for (int x = 1;x<9;x++) {
			cin >> sudoku[0][x];
		}
		for (int x = 1;x<9;x++) {
			for (int y = 0;y<9;y++) {
				cin >> sudoku[x][y];
			}
		}
		out(sudoku);
		if (cin.eof())
			break;


	}
	return 0;
}
