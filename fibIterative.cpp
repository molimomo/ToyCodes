#include<iostream>

using namespace std;

unsigned int fibIterative(int n){
    if(n<=2)
        return 1;
    int cache[2];
    cache[0] = 1;
    cache[1] = 1;
    int res = 0;
    for(int i=2;i<n;i++){
        res = cache[0] + cache[1];
        cache[0] = cache[1];
        cache[1] = res;
    } 
    return cache[1];
}



int main(){
    int n = 50;
    cout<<fibIterative(n)<<endl;
    return 0;
}
