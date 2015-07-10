/*
 *  This program implement a function to split string according to specific delim.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
	Following two functions are extarct token from  user's input string.
	and return a vector of string.	
*/

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


int main(){
	string input;
	getline(cin, input);
	vector<string> elems = split(input,' ');
	for(int i = 0;i<elems.size();i++)
		cout<<elems[i]<<endl;	
	return 0;
}
