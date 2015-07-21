#include "myListNode.h"

using namespace std;

void deleteNodeRef(myListNode* node){
    myListNode* next = node->next;
    *node = *next;
    delete next;
}

void deleteNode(myListNode* &head, int idx){
    myListNode* ptr = head;
    for(int i=0;i<idx;i++){
        ptr = ptr->next;
    }
    deleteNodeRef(ptr);
}

int main(){
    myListNode* head = generateList(4, false);
    printList(head);
    deleteNode(head, 2);
    printList(head);   
    return 0;
} 
