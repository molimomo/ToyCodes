/*
 * This program return the unique element in a sorted array.
 * Note: Only one unique element in array and remained elements are occured twice. 
 */

#include<iostream>

using namespace std;

bool isUnique(int* arr, int idx){
    return (idx==0)?(arr[idx]!=arr[idx+1]):(arr[idx] != arr[idx+1]) && (arr[idx] != arr[idx-1]);
}

int fun(int *arr, int begin, int end){
    if(begin>end)
        return -1;
    
    int mid = (begin+end)>>1;
    
    if(isUnique(arr, mid)){
        return mid;
    }
    else{
        int left = fun(arr, begin, mid-1);
        int right = fun(arr, mid+1, end);
        if(left ==-1 && right==-1)
            return -1;
        else
            return (left==-1)?right:left;
    }
}

int main(){
    int arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    cout<<arr[fun(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1)]<<endl;    
    return 0;
}
