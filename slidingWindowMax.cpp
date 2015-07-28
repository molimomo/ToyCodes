#include<iostream>
#include<queue>
#include<vector>
#include<time.h>

using namespace std;

void findWindowMax(vector<int> &a, int size, vector<int> &result){
     // store indices of elements
    deque<int> dq;
    
    // traverse vector
    for(int i=0;i<a.size();i++){
        while(!dq.empty() && dq.front()<i-size+1){
            dq.pop_front();
        }
        while(!dq.empty() && a[i] > a[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
        if(i>=size-1){
            result.push_back(a[dq.front()]);
        }
    }    
}

int main(){
    const int num = 10; 
    const int size = 3; 
    vector<int> nums(num, 0);
    vector<int> result;
        
    // generate random vector
    cout<<"origin:"<<endl;
    srand(time(NULL));    
    for(int i = 0;i<num;i++){
        int tmp = rand()%10;
        nums[i] = tmp;
        cout<<nums[i]<<", ";
    }
    cout<<endl;

    // find maximum in each window 
    findWindowMax(nums, size, result);

    // output result
    cout<<"result:"<<endl;
    for(auto it = result.begin();it!=result.end();it++){
        cout<<*it<<", ";
    }
    cout<<endl;

    return 0;
}
