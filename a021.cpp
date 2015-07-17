#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
using namespace std;

#define sub_10 10

void supplement(int x, int pos, string *intput) { //位元補齊
	string &yy = *intput;
	for (int y = 0;y < x;y++) {
		yy.insert(pos, "0");
	}
	//cout << *intput;
}
string int2str(int i) { //int轉string
	stringstream ss;
	string convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}
char int2char(int i) { //int轉char
	stringstream ss;
	char convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}
int str2int(string i) { //str轉int
	stringstream ss;
	int convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}
void borrow(int x, string *intput) { //減法借位
	string &tmp = *intput;
	for (int y = x;y >= 0;y--) {
		if (tmp[y] != '0') {
			tmp[y] = int2char(tmp[y] - '0' - 1);
			break;
		}
		else if (tmp[y] == '0') {
			tmp[y] = '9';//int2char(9); 
		}

	}
}
string add(char status, string intput_1, string intput_2) { //加/減/乘法運算
	string output = ("");
	int n1, n2;
	int bit, sum;
	char tmp1, tmp2;
	//只有在加法運算時才判斷是否兩數位元是否一致
	if (status == '+' || status == '-') {
		n1 = intput_1.size();
		n2 = intput_2.size();
		bit = abs(n1 - n2);
		//bit=abs(intput_1.size()-intput_2.size());
		if (intput_1.size() > intput_2.size())
			supplement(bit, 0, &intput_2);
		else if (intput_1.size() < intput_2.size())
			supplement(bit, 0, &intput_1);
	}
	bit = intput_1.size();
	//cout <<"bit:" <<intput_1.size()<<"-"<<intput_2.size() <<"-" << intput_1 <<"-"<<intput_2<<endl;
	sum = 0;
	//執行兩數個別位元相加，乘法第2個數長度都為1
	for (int x = bit - 1;x >= 0;x--) {
		if (status == '+') {
			tmp1 = intput_1[x];
			tmp2 = intput_2[x];
			if (tmp1 - '0' == 0 && sum == 0) {
				output.insert(0, int2str(tmp2 - '0'));
				continue;
			}
			if (tmp2 - '0' == 0 && sum == 0) {
				output.insert(0, int2str(tmp1 - '0'));
				continue;
			}
			sum = sum + tmp1 - '0' + tmp2 - '0';
		}
		else if (status == '*') {
			tmp1 = intput_1[x];
			tmp2 = intput_2[0];
			if (tmp1 - '0' == 0) {
				output.insert(0, "0");
				//cout << "有執行";
				continue;
			}
			sum = sum + (tmp1 - '0')*(tmp2 - '0');
		}
		else if (status == '-') {
			tmp1 = intput_1[x];
			tmp2 = intput_2[x];
			//cout <<"總值:" <<intput_1[x] <<"總值2:" <<intput_2[x] <<endl;
			if (tmp1 - '0'>tmp2 - '0') {
				sum = (tmp1 - '0') - (tmp2 - '0');
				//cout << sum;
			}
			else if (tmp1 - '0' == tmp2 - '0') {
				sum = 0;
			}
			else {
				borrow(x - 1, &intput_1);
				sum = (tmp1 - '0') - (tmp2 - '0') + sub_10;
			}

			output.insert(0, int2str(sum));
			sum = 0;
			int count = 0;
			if (x == 0) {
				while (1) {
					if (output[count] == '0')
						count++;
					else
						break;
				}
				if(count!=0)
					output = output.assign(output, count, output.size());
				if (output.empty())
					output = "0";
			}
		}
		//cout <<"值：" <<sum <<"-" <<tmp1<<"-"<<tmp2<< endl;
		//判斷是否有進位
		if (status == '+' || status == '*') {
			if (sum>9) {
				output.insert(0, int2str(sum % 10));
				sum /= 10;
				//cout << "有進位" <<sum<< endl;
			}
			else {
				//cout << "無進位:" << sum << endl;
				output.insert(0, int2str(sum));
				sum = 0;
			}
		}
	}
	if (sum) {
		output.insert(0, int2str(sum));
	}
	return output;
}
/*
解說：
假設1111 * 67 就會等於(1111 * 7)+(11110*6) 所以可以使用加法運算完成乘法運算！
(原本6的個位數0被我移到1111那邊去了)
*/
string mult(string intput_1, string intput_2) { //乘法運算位元移動，再使用加法。
	string output = (""), tmp;
	for (int y = 0;y<intput_2.size();y++) {
		if (y != 0)
			supplement(1, intput_1.size(), &intput_1);  //將第1個數的第1bit補0
		tmp = tmp.assign(intput_2, intput_2.size() - y - 1, intput_2.size() - y);  //將第2個數的第1bit刪除
		//cout <<"值:"<< tmp<<"-"<<intput_1<<endl;
		output = add('+', output, add('*', intput_1, tmp));     //使用加法完成乘法運算
	}
	return output;
}

int bit_size_swap(int x, string *intput_1, string *intput_2) {  //輸入兩數，把較大數放第一個
	string tmp, &intput1 = *intput_1, &intput2 = *intput_2;
	if (x<0) {
		tmp = *intput_1;
		*intput_1 = *intput_2;
		*intput_2 = tmp;
		return 0;
	}
	else if (x == 0) {
		if (intput2[0] - '0'>intput1[0] - '0') {
			tmp = *intput_1;
			*intput_1 = *intput_2;
			*intput_2 = tmp;
			return 1;
		}
	}
	return 0;
}
int comparison_of_bit_size(string intput_1, string intput_2) {  //除法運算時，比較兩數大小(位元/位數)
	if (intput_1.size()>intput_2.size()){
		return 1;
	}
	else if (intput_1.size()<intput_2.size()){
		return 2;
	}
	else {
		for (int i = 0; i < intput_1.size(); i++){
			if ((intput_1[i] - '0')>(intput_2[i] - '0')){
				return 1;
			}
			else if ((intput_1[i] - '0') < (intput_2[i] - '0')) {
				return 2;
			}
			else {
				if (i== intput_1.size()-1){
					return 0;
				}
			}
		}
	}

}
string exc(string intput_1,string intput_2){  //除法運算
	string output=("");
	string tmp, surplus;
	char tmp1, tmp2;
	int bit = intput_1.size() - intput_2.size();
	int check;
	string ori = intput_2;
	if (comparison_of_bit_size(intput_1, intput_2)==1)	//舉例:  1234 / 12  第1位數大於第2位數時進入
	{
		if (bit == 0) {	//舉例:  1234 / 1111  兩位數相同，但第2位數較大時進入
			for (int i = 9; i > 0; i--) {
				if (i == 1) {
					tmp = add('-', intput_1, intput_2);
					bit = tmp.size();
					if (tmp[0] == '0')
						return "1";
					if (bit<intput_2.size())
						return "1";
					if (bit == intput_2.size() && (intput_2[0] - '0')>(tmp[0] - '0'))
						return "1";
				}
				else {
					tmp = mult(intput_2, int2str(i));
					if (comparison_of_bit_size(tmp, intput_1)==0)
						return int2str(i);
					else if (comparison_of_bit_size(tmp, intput_1) == 1)
						continue;
					else if (comparison_of_bit_size(tmp, intput_1) == 2)
						return int2str(i);

				}
			}
		}
		else {	//舉例:  1234 / 11  兩位數不相同，但第1位數較大時進入
			supplement(bit, intput_2.size(), &intput_2);	//舉例:  1234 / 11 ←捕兩個0進去，等於:1234/1100
			//cout << "intput_2:" << intput_2 <<endl;
			if (intput_1.size()== intput_2.size() && (intput_1[0]-'0')<(intput_2[0] - '0'))	//舉例:  1234/1400  第2位數因為補0後大過第1位數，所以刪除一個0，變成 1234/140
				intput_2 = intput_2.assign(intput_2, 0, intput_2.size() - 1);
			if (comparison_of_bit_size(intput_1, intput_2)==1)	//舉例: 1234/140  開始進行除法運算
			{
				
				for (int i = 0; i <= bit; i++)
				{
					check = 1;
					for (int y = 10; y > 0; y--)		//舉例: 1234/140  y=10  140*y=1400(不合)，y=9  140*y=1260(不合)，y=8  140*y=1120(合)  1234-1120=114  將第一個數改為114繼續運算下去。
					{
						tmp = mult(intput_2, int2str(y));
						//cout <<"value:"<< tmp <<"y:"<<y<< endl;
						if (comparison_of_bit_size(tmp, intput_1)==1)
						{
							if (intput_1.size()== ori.size() && comparison_of_bit_size(intput_1, ori) == 2) {
								supplement(bit-i-1, output.size(), &output);
								return output;
								break;
							}
							continue;
						}
						else// 
						{

							intput_1 = add('-', intput_1, tmp);
							output = output + int2str(y);
							check = 0;
							//cout << "剩餘:" << intput_1 << "商:" << output <<"-"<<y <<endl;
							break;
						}
						//else if(comparison_of_bit_size(tmp, intput_1) == 0)  //加速運算，不過沒有使用
						//{
						//	cout << "OK:";
						//	supplement(bit-i, output.size(), &output);
						//	return int2str(y) + output;
						//}
					}
					if(check==1)	//因為第2個數有借0給他，所以運算完後要補到結果去
						output = output +"0";
					intput_2 = intput_2.assign(intput_2, 0, intput_2.size() - 1);
				}
				return output;
			}
			else if(comparison_of_bit_size(intput_1, intput_2) == 0){	//舉例:  1100 / 11  補兩個0後 剛好和1100相同，所以直接印出結果
				supplement(bit, output.size(), &output);
				return "1" + output;
			}
		}
	}
	else if (comparison_of_bit_size(intput_1, intput_2) == 2)	//舉例: 1234/9999  結果商為0
	{
		return "0";
	}
	else {	//舉例: 9999/9999  結果商為1
		return "1";
	}
 }
//主程式

int main() {
	string intput;
	string intput_1, intput_2;
	int find = 0, bit;
	int check_sub;
	while (getline(cin, intput, '\n')) {
		find = intput.find(" ", 0);
		intput_1 = intput_1.assign(intput, 0, find);
		intput_2 = intput_2.assign(intput, find + 3, intput.size());
		check_sub = comparison_of_bit_size(intput_1, intput_2);
		//cout <<intput_1<<"  "<<intput_2<<endl;
		intput = intput[find + 1];
		if(intput[0]!='/')
			bit = bit_size_swap(intput_1.size() - intput_2.size(), &intput_1, &intput_2);
		
		//cout <<intput[0]<<"\n-----------"<<endl;
		switch (intput[0]) {
		case '*':
			cout << mult(intput_1, intput_2) << endl;
			break;
		case '+':
			cout << add('+', intput_1, intput_2) << endl;
			break;
		case '-':
			//cout << intput_1 << ":" << intput_2 << endl;
			if (check_sub == 2)
				cout << "-" << add('-', intput_1, intput_2) << endl;
			else
				cout << add('-', intput_1, intput_2) << endl;
			break;
		case '/':
			cout << exc(intput_1, intput_2) << endl;
			break;
		}
		if (cin.eof())
			break;
	}
	//system("PAUSE");
	return 0;
}

//測試用程式
 /*
int main() {

	for (int i =0 ; i <2147483647; i++)
	{
		if (str2int(exc( int2str(i), int2str(10)))== (int)(i / 10))
		{
			cout << "正常" <<i<<"-"<< exc(int2str(i), int2str(10)) <<"-"<< (int)(i / 10) <<endl;
		}
		else {
			cout << "異常:" << i << "-" << exc(int2str(i), int2str(10)) << "-" << (int)(i / 10) << endl;
			break;
		}
		
	}

	system("PAUSE");
	return 0;
}
*/