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

void reverseList(myListNode* &head){
    if(head==NULL || head->next==NULL)
        return;
    myListNode *cur = NULL;
    myListNode *ptr = NULL;
    while(head){
        ptr = head->next;
        head->next = cur;
        cur = head;
        head = ptr;
    }
    head = cur;
}

int main(){
    cout<<"Original list"<<endl;
    myListNode* head = generateList(3,false);
    printList(head);
    
    cout<<"Reversed list"<<endl;
    reverseList(head);
    printList(head);
    return 0;
}
