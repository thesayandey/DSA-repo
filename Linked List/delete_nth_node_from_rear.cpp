#include<iostream>
#include<alloca.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node* deleteNthFromRear(struct Node *head, int pos){
    struct Node *ptr;
    ptr = head;
    int counter = 1;
    while(ptr->next!=NULL){
        ptr = ptr->next;
        counter++;
    }
    //cout<<counter;
    
    if(counter == pos){
        struct Node *k;
        k = head;
        head = head->next;
        delete(k);
        return head;
    }
    else{
        int key = counter-pos;
        //cout<<key;
        int newcounter = 1;
        struct Node *del;   //Dummy pointer for deleting the node
        del = head;
        while(newcounter<key){
            del = del->next;
            newcounter++;
        }
        struct Node *node_to_be_deleted;
        node_to_be_deleted = del->next;
        del->next = del->next->next;
        delete(node_to_be_deleted);
        return head;
    }
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
    n5->data = 6;

    temp->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    displayList(head);
    cout<<"\n";
    head = deleteNthFromRear(head, 4);
    displayList(head);

    return 0;
    
}