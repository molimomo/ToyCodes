#include<iostream>
#include<vector>
using namespace std;

/*
    Check a target's existence in Table, which
    
    Table[i][j]<=Table[i][j+1], Table[i][j]<=Table[i+1][j]

    Complexity: O(n^log3)
*/


bool searchHelp(vector<vector<int>>& matrix, int target, int beginX, int beginY, int endX, int endY){

    if(beginX>endX || beginY>endY || (beginX==endX && beginY==endY && matrix[beginX][beginY]!=target))
        return false;

    int midX = (beginX + endX)>>1;
    int midY = (beginY + endY)>>1;

    // found target
    if(matrix[midX][midY]==target)
        return true;

    if(matrix[midX][midY]>target){
            // search north-west side
        return searchHelp(matrix, target, beginX, beginY, midX, midY)
            // search north-east side
            ||  searchHelp(matrix, target, beginX, midY+1, midX-1, endY)
            // search south-west side
            ||  searchHelp(matrix, target, midX+1, beginY, endX, midY);
    }
    else{
            // search north-east side
        return searchHelp(matrix, target, beginX, midY+1, midX, endY)
            // search south-west side
            ||  searchHelp(matrix, target, midX+1, beginY, endX, midY)
            // search south-east side
            ||  searchHelp(matrix, target, midX+1, midY+1, endX, endY);
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    return searchHelp(matrix,target,0,0,matrix.size()-1, matrix[0].size()-1);
}
