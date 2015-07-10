#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
        // Step 1: shift right until encounter 1
        while((n&1) != 1){
		n>>=1;
        }
        // Step 2: check result is 0 or not
        return n==1;
}

int main(){
	if(isPowerOfTwo(4))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}

