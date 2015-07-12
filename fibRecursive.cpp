#include <iostream>
#include <limits.h>

using namespace std;

double fibRecursive(int n){
    if(n<=2)
       return 1;
   return fibRecursive(n-1) + fibRecursive(n-2); 
}

int main(){
    int n = 50;
    cout<<fibRecursive(n)<<endl;    
    return 0;
}
