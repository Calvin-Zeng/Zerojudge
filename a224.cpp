#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sstream>
using namespace std;


int main() {
	string intput;
	int count[26] = {0},sum;
	while (getline(cin, intput, '\n')) {
		
		for (int i = 0; i < intput.size(); i++)
		{
			
			if (intput[i]>='a'&&intput[i] <= 'z')
				count[intput[i]-'a']++;
			else if (intput[i] >= 'A'&&intput[i] <= 'Z')
				count[intput[i] - 'A']++;

		}
		sum = 0;
		for (int i = 0; i < 26; i++)
		{
			//cout << count[i] << "..";
			if (count[i] % 2==1)
				sum++;
		}
		if (sum > 1)
			cout << "no..." << endl;
		else
			cout << "yes !" << endl;
		memset(count, 0, sizeof(count));
	}
	return 0;
}