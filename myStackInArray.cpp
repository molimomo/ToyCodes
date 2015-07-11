/*
 *  Implement a stack with STL vector.
 */

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class myStack{
    public:
        myStack(int capacity){
            elements = new int[capacity];
            this->capacity = capacity;
            this->topIdx = -1;
        }
    
        ~myStack(){
            delete[] elements;
        }

        bool empty(){
            return (topIdx == -1);
        }

        void push(int val){
            if(capacity == topIdx+1){
                throw string("Stack is full!\n");
                exit(EXIT_FAILURE);
            }
            elements[++topIdx]=val;
        }

        void pop(){
            if(empty()){
                cout<<"empty stack!"<<endl;
                exit(EXIT_FAILURE);
            }
            topIdx--;
        }

        int top(){
            if(empty()){
                cout<<"empty stack!"<<endl;
                exit(EXIT_FAILURE);
            }
            return elements[topIdx];
        }

        int size(){
            return topIdx+1;
        }

    private:
        int *elements;
        int capacity;
        int topIdx;

};

int main(){
    myStack *testStack = new myStack(5);
    testStack->push(1); 
    testStack->push(2); 
    testStack->push(3);
    cout<<"stack size: "<<testStack->size()<<endl;;
    cout<<"top:"<<testStack->top()<<endl;
    testStack->pop(); 
    cout<<"stack size: "<<testStack->size()<<endl;;
    cout<<"top:"<<testStack->top()<<endl;
    testStack->push(5); 
    testStack->pop(); 
    cout<<"top:"<<testStack->top()<<endl;
    testStack->pop(); 
    cout<<"top:"<<testStack->top()<<endl;
    return 0;
}
