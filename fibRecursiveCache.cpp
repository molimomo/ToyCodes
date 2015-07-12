#include <iostream>

using namespace std;

int cache[10000];

double  fibRecursiveCache(int n){
    if(cache[n]==0){
        cache[n] = fibRecursiveCache(n-1)+fibRecursiveCache(n-2);
    }
    return cache[n];
}

int main(){
    int n = 50;
    cache[1] = 1;
    cache[2] = 1;
    cout<<fibRecursiveCache(n)<<endl;
    return 0;
}
