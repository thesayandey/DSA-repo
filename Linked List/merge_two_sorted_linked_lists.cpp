#include<iostream>
#include<alloca.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void displayList(struct Node *head){
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    
}

struct Node* createList(struct Node* head1, struct Node *head2){
    int len1, len2;
    struct Node *newhead = NULL;
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    else if(head1 == NULL){
        len1 = 0;
    }
    else if(head2 == NULL){
        len2 = 0;
    }
    else{
        len1 = 1;
        len2 = 1;
        
        struct Node *p1, *p2;
        p1 = head1;
        p2 = head2;

        while(p1->next != NULL){
            p1 = p1->next;
            len1++;
        }
        while(p2->next != NULL){
            p2 = p2->next;
            len2++;
        }
        
        struct Node *temp, *ptr;

        int total = len1 + len2;
        int i = 0;
        while(i<total){
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = 7;
            if(newhead == NULL){
                newhead = temp;
                ptr = temp;
            }
            else{
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        ptr->next = NULL;
        
    }
    return newhead;
}
  

struct Node* mergeSortedLists(struct Node *head1, struct Node *head2){
    struct Node *ptr1;
    struct Node *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    struct Node *temp;  //Node for storing new value

    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    else if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    else{
        struct Node* head;
        head = createList(head1, head2);
        //displayList(head);
        return head;
    }
}

int main(){
    struct Node *head1, *head2, *n1, *n2, *n3, *n4, *n5;
    head1 = (struct Node*)malloc(sizeof(struct Node));
    head2 = (struct Node*)malloc(sizeof(struct Node));

    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    n5 = (struct Node*)malloc(sizeof(struct Node));


    //Linked list 1
    head1->data = 2;
    n1->data = 4;
    n2->data = 6;
    n3->data = 12;

    head1->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    displayList(head1);

    cout<<"\n";
    //Linked list 2
    head2->data = 1;
    n4->data = 8;
    n5->data = 12;

    head2->next = n4;
    n4->next = n5;
    n5->next = NULL;
    displayList(head2);

    struct Node* n = createList(head1, head2);
    displayList(n);

    return 0;
}