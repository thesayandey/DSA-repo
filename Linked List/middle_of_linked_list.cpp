#include<iostream>
#include<alloca.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node* middleOfLinkedList(struct Node *head){
    int count = 1;
    struct Node *ptr;
    ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
        count++;
    }
    int key = count/2;
    int counter = 1;
    struct Node *t;
    t = head;
    while(counter < key){  
        counter++;
        t = t->next;
    }
    return(t->next);
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
    struct Node *temp, *head;
    temp = (struct Node*)malloc(sizeof(struct Node));
    head = temp;
    temp->data = 1;
    struct Node *n1, *n2, *n3, *n4, *n5;
    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    n5 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 2;
    n2->data = 3;
    n3->data = 4;
    n4->data = 5;
    //n5->data = 6;

    temp->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    //n5->next = NULL;

    displayList(head);
    cout<<endl;
    struct Node *n;
    n = middleOfLinkedList(head);
    cout<<n->data;
    return 0;
    
}



//----------------------------OPTIMIZED SOLUTION------------------------------------------