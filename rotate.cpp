#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
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

/*
    Print out the elements in matrix
 */

void printMatrix(vector<vector<string> > &matrix){
	for(int i=0;i<matrix.size();i++){
    		for(int j=0;j<matrix.size();j++){
    			cout<<matrix[i][j]<<" ";
    		}
    		cout<<endl;
    	}
	cout<<endl;
}

void rotateHelp(vector<vector<string> > &matrix, int begin, int bound){
	if(begin==bound)
		return;
	// left to right
	string tmpLR = matrix[begin][bound-1];
	//cout<<"LR: "<<tmpLR<<endl;
	for(int i=bound-1;i>begin;i--){
		matrix[begin][i] = matrix[begin][i-1];
	}
	//printMatrix(matrix);

	// up to down
	string tmpUD = matrix[bound-1][bound-1];
	//cout<<"UD: "<<tmpUD<<endl;
	for(int i=bound-1;i>begin;i--){
		matrix[i][bound-1] = matrix[i-1][bound-1];
	}
	matrix[begin+1][bound-1] = tmpLR;
	//printMatrix(matrix);
	
	// right to left
	string tmpRL = matrix[bound-1][begin];
	//cout<<"RL: "<<tmpRL<<endl;
	for(int i=begin;i<bound-1;i++){
		matrix[bound-1][i] = matrix[bound-1][i+1];
	}
	matrix[bound-1][bound-2] = tmpUD;
	//printMatrix(matrix);
	
	// down to up
	string tmpDU = matrix[begin][begin];
	//cout<<"DU: "<<tmpDU<<endl;
	for(int i=begin;i<bound-1;i++){
		matrix[i][begin] = matrix[i+1][begin];
	}
	matrix[bound-2][begin] = tmpRL;
	//printMatrix(matrix);
}


void rotate(vector<vector<string> > &matrix){
	// only one element in matrix
    if(matrix.size()==1)
		return;
    // Rotate matrix from outside to inside
	for(int i=0;i<floor(log2(matrix.size()));i++){
		rotateHelp(matrix, i, matrix.size()-(i));
	}
}

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numOfRow = 0;
    int k = 0;
    vector<vector<string> > matrix;
    
    // get # of row.
    cin>>numOfRow;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
    
    // get elements in a row and then generate input matrix.
    for(int i=0;i<numOfRow;i++){
        string str;
        getline(cin, str);
		vector<string> rec = split(str,' ');
        matrix.push_back(rec);
    }
    
    if(matrix.size()!=matrix[0].size()){
        cout<<"ERROR"<<endl;
    }
    else{
    	// rotate
    	rotate(matrix);

    	//output result
    	for(int i=0;i<matrix.size();i++){
    		for(int j=0;j<matrix.size();j++){
    			cout<<matrix[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    }
    return 0;
}
