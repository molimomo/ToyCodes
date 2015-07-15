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

int funBetter(int* arr, int begin, int end){
    if(begin>end)
        return -1;

    if(begin==end)
        return begin;

    int mid  = (begin+end)/2;

    if(mid%2==0){
        // target is before mid
        if(arr[mid+1]!=arr[mid]){
            return funBetter(arr, begin, mid);
        }
        // target is after mid
        else{
            return funBetter(arr, mid+2, end);
        }
    }
    else{
        // target is before mid
        if(arr[mid-1]==arr[mid]){
            return funBetter(arr, mid+2,end);
        }
        else{
            return funBetter(arr, begin, mid-1);
        }
    }
}


int main(){
    int arr[] = {1, 3, 3, 4, 4,5, 5, 7, 7, 8, 8};
    cout<<arr[fun(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1)]<<endl;    
    cout<<arr[funBetter(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1)]<<endl;    
    return 0;
}
