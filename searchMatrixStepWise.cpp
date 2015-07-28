#include<iostream>
#include<vector>

using namespace std;
// Find a value in a col/row-wise sorted matrix


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int beginX = 0;
    int beginY = matrix[0].size()-1;
    while(beginX<matrix.size() && beginY >=0){
        if(matrix[beginX][beginY]==target){
            return true;
        }
        else if(matrix[beginX][beginY]>target){
            beginY--;
        }
        else{
            beginX++;
        }
    }
    return false;
}
