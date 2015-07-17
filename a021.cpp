#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
using namespace std;

#define sub_10 10

void supplement(int x, int pos, string *intput) { //�줸�ɻ�
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
int str2int(string i) { //str��int
	stringstream ss;
	int convert_str;
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
int comparison_of_bit_size(string intput_1, string intput_2) {  //���k�B��ɡA�����Ƥj�p(�줸/���)
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
string exc(string intput_1,string intput_2){  //���k�B��
	string output=("");
	string tmp, surplus;
	char tmp1, tmp2;
	int bit = intput_1.size() - intput_2.size();
	int check;
	string ori = intput_2;
	if (comparison_of_bit_size(intput_1, intput_2)==1)	//�|��:  1234 / 12  ��1��Ƥj���2��Ʈɶi�J
	{
		if (bit == 0) {	//�|��:  1234 / 1111  ���ƬۦP�A����2��Ƹ��j�ɶi�J
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
		else {	//�|��:  1234 / 11  ���Ƥ��ۦP�A����1��Ƹ��j�ɶi�J
			supplement(bit, intput_2.size(), &intput_2);	//�|��:  1234 / 11 �������0�i�h�A����:1234/1100
			//cout << "intput_2:" << intput_2 <<endl;
			if (intput_1.size()== intput_2.size() && (intput_1[0]-'0')<(intput_2[0] - '0'))	//�|��:  1234/1400  ��2��Ʀ]����0��j�L��1��ơA�ҥH�R���@��0�A�ܦ� 1234/140
				intput_2 = intput_2.assign(intput_2, 0, intput_2.size() - 1);
			if (comparison_of_bit_size(intput_1, intput_2)==1)	//�|��: 1234/140  �}�l�i�氣�k�B��
			{
				
				for (int i = 0; i <= bit; i++)
				{
					check = 1;
					for (int y = 10; y > 0; y--)		//�|��: 1234/140  y=10  140*y=1400(���X)�Ay=9  140*y=1260(���X)�Ay=8  140*y=1120(�X)  1234-1120=114  �N�Ĥ@�ӼƧאּ114�~��B��U�h�C
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
							//cout << "�Ѿl:" << intput_1 << "��:" << output <<"-"<<y <<endl;
							break;
						}
						//else if(comparison_of_bit_size(tmp, intput_1) == 0)  //�[�t�B��A���L�S���ϥ�
						//{
						//	cout << "OK:";
						//	supplement(bit-i, output.size(), &output);
						//	return int2str(y) + output;
						//}
					}
					if(check==1)	//�]����2�ӼƦ���0���L�A�ҥH�B�⧹��n�ɨ쵲�G�h
						output = output +"0";
					intput_2 = intput_2.assign(intput_2, 0, intput_2.size() - 1);
				}
				return output;
			}
			else if(comparison_of_bit_size(intput_1, intput_2) == 0){	//�|��:  1100 / 11  �ɨ��0�� ��n�M1100�ۦP�A�ҥH�����L�X���G
				supplement(bit, output.size(), &output);
				return "1" + output;
			}
		}
	}
	else if (comparison_of_bit_size(intput_1, intput_2) == 2)	//�|��: 1234/9999  ���G�Ӭ�0
	{
		return "0";
	}
	else {	//�|��: 9999/9999  ���G�Ӭ�1
		return "1";
	}
 }
//�D�{��

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

//���եε{��
 /*
int main() {

	for (int i =0 ; i <2147483647; i++)
	{
		if (str2int(exc( int2str(i), int2str(10)))== (int)(i / 10))
		{
			cout << "���`" <<i<<"-"<< exc(int2str(i), int2str(10)) <<"-"<< (int)(i / 10) <<endl;
		}
		else {
			cout << "���`:" << i << "-" << exc(int2str(i), int2str(10)) << "-" << (int)(i / 10) << endl;
			break;
		}
		
	}

	system("PAUSE");
	return 0;
}
*/