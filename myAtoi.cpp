#include <iostream>
#include <limits.h>
using namespace std;

int myAtoi(string str){
	if(str.length()==0 || str[0]=='0')
		return 0;
	bool neg = (str[0]=='-');
	int idx = neg?1:0;
	int result = 0;

	for(int i=idx;i<str.length();i++){
		if(result!=0 && result>=((INT_MAX-(str[i]-'0'))/(result*10))){
			cout<<"Overflow!!!"<<endl;
			return -1;
		}
		result = result * 10 + (str[i]-'0');
	}

	return neg?-1*result:result;	
}


int main(){
	cout<<myAtoi("123")<<endl;
	cout<<myAtoi("0")<<endl;
	cout<<myAtoi("-12")<<endl;
	cout<<myAtoi("1111111111111111111111111")<<endl;
	return 0;
}
