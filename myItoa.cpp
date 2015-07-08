#include <iostream>

using namespace std;

string myItoa(int val){
	
	if(val==0)
		return "0";
	bool neg = (val<0);
	int num = neg? -1*val:val;
	string result = "";
	while(num!=0){
		int r = num%10;
		result.insert(result.begin(),r+'0');
		num/=10;
	}
	return neg?"-"+result:result;
}


int main(){
	cout<<myItoa(123)<<endl;
	cout<<myItoa(-12)<<endl;
	cout<<myItoa(0)<<endl;
	return 0;
}
