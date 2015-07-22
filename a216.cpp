#include <iostream>

using namespace std;
long long fibonacci_f(int n){
    long long output=0;
    for(int i=1;i<=n;i++){
        output+=(i*(i+1)/2);
    }
    return output;
}

int main() {
	long long int intput;
	while (cin >> intput) {
		cout <<(intput*(intput+1)/2)<<" "<<fibonacci_f(intput)<<endl;;
	}
	return 0;
}
