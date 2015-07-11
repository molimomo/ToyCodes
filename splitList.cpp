/*
 * This program implements splitList function that divide a single linked-list (in-place). 
 */


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

void splitList(myListNode* &head, myListNode* &sec){
    if(head == NULL)
        return;
    sec = head;
    myListNode* fast = head->next;
    while(fast && fast->next){
        sec = sec->next;
        fast = fast->next->next;
    }
    myListNode* tmp = sec;
    sec = sec->next;
    tmp->next = NULL;
}

int main(){
    myListNode* head = generateList(9, false);
    myListNode* first = NULL;
    myListNode* sec = NULL;

    cout<<"original list: ";
    printList(head);
    splitList(head, sec);
    cout<<"first: ";
    printList(head);
    cout<<"sec: ";
    printList(sec);
    return 0;
}
