#include<iostream>
#include<alloca.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node *head)
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

void displayList(struct Node *head){
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    
}

int main(){
    struct Node *temp, *head, *temp1, *temp2, *temp3;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp3 = (struct Node*)malloc(sizeof(struct Node));
    head = temp;
    temp->data = 1;
    temp->next = temp1;
    temp1->data = 2;
    temp1->next = temp2;
    temp2->data = 3;
    temp2->next = temp3;
    temp3->data = 4;
    temp3->next = NULL;

    //Before reversal 
    // 1->2->3->4->NULL

    struct Node *newHead;
    displayList(head);
    newHead = reverseList(head);
    displayList(newHead);

    return 0;

}




/*
void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
 */