#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
using namespace std;

#define sub_10 10

void supplement(int x, int pos, string *intput) { //��Ʀ줸�ɻ�
	string &yy = *intput;
	for (int y = 0;y < x;y++) {
		yy.insert(pos, "0");
	}
	//cout << *intput;
}
string int2str(int i) { //int��string
	stringstream ss;
	string convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}
char int2char(int i) { //int��char
	stringstream ss;
	char convert_str;
	ss << i;
	ss >> convert_str;
	return convert_str;
}
void borrow(int x, string *intput) { //��k�ɦ�
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
string add(char status, string intput_1, string intput_2) { //�[/��/���k�B��
	string output = ("");
	int n1, n2;
	int bit, sum;
	int tmp_sub[500];
	char tmp1, tmp2;
	//�u���b�[�k�B��ɤ~�P�_�O�_��Ʀ줸�O�_�@�P
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
	//�����ƭӧO�줸�ۥ[�A���k��2�Ӽƪ��׳���1
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
				//cout << "������";
				continue;
			}
			sum = sum + (tmp1 - '0')*(tmp2 - '0');
		}
		else if (status == '-') {
			tmp1 = intput_1[x];
			tmp2 = intput_2[x];
			//cout <<"�`��:" <<intput_1[x] <<"�`��2:" <<intput_2[x] <<endl;
			if (tmp1 - '0'>tmp2 - '0') {
				sum = (tmp1 - '0') - (tmp2 - '0');
				//cout << sum;
			}
			else if (tmp1 - '0' == tmp2 - '0') {
				sum = 0;
			}
			else {
				borrow(x - 1, &intput_1);
				sum = tmp1 + '0' - tmp2 - '0' + sub_10;
			}

			output.insert(0, int2str(sum));
			sum = 0;

			if (x == 0) {
				while (1) {
					int count = 0;
					count++;
					if (output[0] == '0') {
						output = output.assign(output, count, output.size());

					}
					else
						break;
				}
				if (output.empty())
					output = "0";
			}
		}
		//cout <<"�ȡG" <<sum <<"-" <<tmp1<<"-"<<tmp2<< endl;
		//�P�_�O�_���i��
		if (status == '+' || status == '*') {
			if (sum>9) {
				output.insert(0, int2str(sum % 10));
				sum /= 10;
				//cout << "���i��" <<sum<< endl;
			}
			else {
				//cout << "�L�i��:" << sum << endl;
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
�ѻ��G
���]1111 * 67 �N�|����(1111 * 7)+(11110*6) �ҥH�i�H�ϥΥ[�k�B�⧹�����k�B��I
(�쥻6���Ӧ��0�Q�ڲ���1111����h�F)
*/
string mult(string intput_1, string intput_2) { //���k�B��줸���ʡA�A�ϥΥ[�k�C
	string output = (""), tmp;
	for (int y = 0;y<intput_2.size();y++) {
		if (y != 0)
			supplement(1, intput_1.size(), &intput_1);  //�N��1�Ӽƪ���1bit��0
		tmp = tmp.assign(intput_2, intput_2.size() - y - 1, intput_2.size() - y);  //�N��2�Ӽƪ���1bit�R��
																				   //cout <<"��:"<< tmp<<"-"<<intput_1<<endl;
		output = add('+', output, add('*', intput_1, tmp));     //�ϥΥ[�k�������k�B��
	}
	return output;
}

int bit_size_swap(int x, string *intput_1, string *intput_2) {  //��J��ơA����j�Ʃ�Ĥ@��
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

// string exc(string intput_1,string intput_2){
// string output=("");
// int bit=intput_1.size()-intput_2.size();
// if(bit==0){
// if(intput_1[0]-'0'>intput_1[0]-'0'){
// }
// }else{
// supplement(bit,intput_2);
// }
// return output;
// }

int main() {
	string intput;
	string intput_1, intput_2;
	int find = 0, bit;
	while (getline(cin, intput, '\n')) {
		find = intput.find(" ", 0);
		intput_1 = intput_1.assign(intput, 0, find);
		intput_2 = intput_2.assign(intput, find + 3, intput.size());
		//cout <<intput_1<<"  "<<intput_2<<endl;
		bit = intput_1.size() - intput_2.size();
		bit = bit_size_swap(bit, &intput_1, &intput_2);
		intput = intput[find + 1];
		//cout <<intput[0]<<"\n-----------"<<endl;
		switch (intput[0]) {
		case '*':
			cout << mult(intput_1, intput_2) << endl;
			break;
		case '+':
			cout << add('+', intput_1, intput_2) << endl;
			break;
		case '-':
			if (bit == 1)
				cout << "-" << add('-', intput_1, intput_2) << endl;
			else
				cout << add('-', intput_1, intput_2) << endl;
			break;
		}
		if (cin.eof())
			break;
	}
	return 0;
}
