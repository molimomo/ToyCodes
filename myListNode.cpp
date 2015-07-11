#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

class myListNode{
	public:
		// member variables
        int val;
		myListNode* next;

        // constructor
		myListNode(int val){
			this->val = val;
			this->next = NULL;
		}
};

myListNode* generateList(int size, bool random){
    myListNode* head = NULL; 
    myListNode* ptr = NULL; 
    srand(time(NULL));
    for(int i=0;i<size;i++){
        int val = random?rand()%100:i;
        if(!head){
            head = new myListNode(val);
            ptr = head;
        }
        else{
            ptr->next = new myListNode(val);
            ptr = ptr->next;
        }
    }
    return head;
}

void printList(myListNode* head){
    myListNode* ptr = head;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    cout<<"Random list"<<endl;
    myListNode* head = generateList(5,true);
    printList(head);
    
    cout<<"Ordered list"<<endl;
    head = generateList(5,false);
    printList(head);
    return 0;
}
