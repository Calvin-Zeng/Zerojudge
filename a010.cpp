#include<iostream>
#include <string>
#include <string.h>

using namespace std;

char rome_simbool[7] = { 'I','V','X','L','C','D','M' };
int rome_number[7] = { 1,5,10,50,100,500,1000 };

int model_in(char *intput) {
	int tmp = 0, lenth = strlen(intput);
	//cout << lenth;
	for (int y = 0;y <= lenth;y++) {
		switch (intput[y]) {
		case 'I':
			tmp++;
			break;
		case 'V':
			tmp += 5;
			if (intput[y - 1] == 'I')
				tmp -= 2;
			break;
		case 'X':
			tmp += 10;
			if (intput[y - 1] == 'I')
				tmp -= 2;
			break;
		case 'L':
			tmp += 50;
			if (intput[y - 1] == 'X')
				tmp -= 20;
			break;
		case 'C':
			tmp += 100;
			if (intput[y - 1] == 'X')
				tmp -= 20;
			break;
		case 'D':
			tmp += 500;
			if (intput[y - 1] == 'C')
				tmp -= 200;
			break;
		case 'M':
			tmp += 1000;
			if (intput[y - 1] == 'C')
				tmp -= 200;
			break;
		}
	}
	return tmp;
}

string model_out(int intput) {
	string output = "";
	//sprintf(tmp, "%d",intput);
	if (intput == 0) {
		return (output = "ZERO");
	}
	while (intput>0) {
		if (intput >= 1000) {
			intput -= 1000;
			output += "M";
		}
		else if (intput >= 900) {
			intput -= 900;
			output += "CM";
		}
		else if (intput >= 500) {
			intput -= 500;
			output += "D";
		}
		else if (intput >= 400) {
			intput -= 400;
			output += "CD";
		}
		else if (intput >= 100)
		{
			intput -= 100;
			output += "C";
		}
		else if (intput >= 90)
		{
			intput -= 90;
			output += "XC";
		}
		else if (intput >= 50)
		{
			intput -= 50;
			output += "L";
		}
		else if (intput >= 40)
		{
			intput -= 40;
			output += "XL";
		}
		else if (intput >= 10)
		{
			intput -= 10;
			output += "X";
		}
		else if (intput >= 9)
		{
			intput -= 9;
			output += "IX";
		}
		else if (intput >= 5)
		{
			intput -= 5;
			output += "V";
		}
		else if (intput >= 4)
		{
			intput -= 4;
			output += "IV";
		}
		else
		{
			intput -= 1;
			output += "I";
		}
	}
	return output;
}
// int intput_Decode(char *intput){
// char *pch,*pch1[5];
// int x=0;
// pch = strtok(intput," ");
// while (pch != NULL){
// pch1[x++]=pch;
// pch = strtok (NULL, " ");
// }
// cout << model_in(pch1[0])-model_in(pch1[1]);
// return abs(model_in(pch1[0])-model_in(pch1[1]));

// }

// int main(){
// char intput[10];
// int number;
// while (scanf("%[^\n]",&intput)){
// if(intput[0]=='#')
// break;
// number=intput_Decode(intput);
// cout << model_out(number) << endl;
// }
// return 0;
// }
int main(){
	string num1,num2;
	char result_char1[20], result_char2[20];
	while (cin >> num1) {
		if (num1 == "#")
			break;
		cin >> num2;
		strcpy_s(result_char1, num1.c_str());   //丟進zerojudge請更改成strcpy(......);
		strcpy_s(result_char2, num2.c_str());
		//cout << abs(model_in(result_char1)-model_in(result_char2)) << endl;
		cout << model_out(abs(model_in(result_char1) - model_in(result_char2))) << endl;
	}
	return 0;
}
