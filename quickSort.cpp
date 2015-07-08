#include <iostream>
#include <vector>

using namespace std;

void quickHelp(int *arr, int begin, int end){
	int left = begin;
	int right = end;
	int pivot = arr[begin];
	
	while(left<=right){
		while(arr[left] < pivot) left++;
		while(arr[right] > pivot) right--;
		if(left<=right){
			swap(arr[left],arr[right]);
			left++;
			right--;
		}	
	}
	
	if(begin < right)
		quickHelp(arr, begin, right);
	if(left < end)
		quickHelp(arr, left, end);
}


void quickSort(int *arr){
	cout<<"Before: "<<endl;
	for(int i=0;i<10;i++){
		cout<<arr[i]<<", ";
	}
	cout<<endl;
	quickHelp(arr, 0, 9);
}


int main(){
	int test[10] = {8,3,25,6,10,17,1,2,18,5};
	quickSort(test);
	cout<<"After: "<<endl;
	for(int i=0;i<10;i++){
		cout<<test[i]<<", ";
	}
	cout<<endl; 
	return 0;
}
