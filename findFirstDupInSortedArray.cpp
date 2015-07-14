/*
 * This program return the index of the first occurence of target. 
 * If targe does not exist in array, return -1.
 */
#include<iostream>

using namespace std;

// Iterative
int findFirstDup(int* arr, int begin, int end, int target){
    while(begin<=end){
        int mid = (begin+end)>>1;
        if(arr[mid]>target){
            end = mid-1;
        }
        else if(arr[mid] < target){
            begin = mid+1;
        }
        else{
            if(mid!=0 && (arr[mid-1] == arr[mid])){
                end = mid - 1;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}

// Recursive
int findFirstDupRec(int* arr, int begin, int end, int target){
    if(begin>end)
        return -1;
    int mid = (begin+end)>>1;
    if(arr[mid]>target)
        return findFirstDupRec(arr, begin, mid-1, target);
    else if(arr[mid]<target)
        return findFirstDupRec(arr, mid+1, end, target);
    else{
        if(mid!=0 && (arr[mid-1] == arr[mid]))
            return findFirstDupRec(arr, begin, mid-1,target);
        else
            return mid;
    }
}

int main(){
    int arr[12] = {1,1,2,3,3,3,3,4,5,6,6,6};
    int target;
    cin>>target;
    cout<<findFirstDup(arr, 0, 11, target)<<endl; 
    cout<<findFirstDupRec(arr, 0, 11, target)<<endl; 
    return 0;
}
