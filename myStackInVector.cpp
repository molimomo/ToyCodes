/*
 *  Implement a stack with STL vector.
 */

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class myStack{
    public:
        myStack(){
        }

        bool empty(){
            return elements.size()==0;
        }

        void push(int val){
            elements.insert(elements.begin(),val);
        }

        void pop(){
            if(empty()){
                cout<<"empty stack!"<<endl;
                exit(EXIT_FAILURE);
            }
            elements.erase(elements.begin());
        }

        int top(){
            if(empty()){
                cout<<"empty stack!"<<endl;
                exit(EXIT_FAILURE);
            }
            return elements[0];
        }

        int capacity(){
            return elements.size();
        }
    private:
        vector<int> elements;

};

int main(){
    myStack *testStack = new myStack();
    testStack->push(1); 
    testStack->push(2); 
    testStack->push(3);
    cout<<"top:"<<testStack->top()<<endl;
    testStack->pop(); 
    cout<<"top:"<<testStack->top()<<endl;
    testStack->push(5); 
    testStack->pop(); 
    cout<<"top:"<<testStack->top()<<endl;
    testStack->pop(); 
    cout<<"top:"<<testStack->top()<<endl;
    return 0;
}
