#include<iostream>
#include<alloca.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int x){
            data = x;
            next = NULL;
        }
        Node(int x, Node *n){
            data = x;
            next = n;
        }
};

Node* addTwoNumbers(Node *p1, Node *p2){
    Node *dummy = new Node(); //Creating a dummy node, initialized with 0
    /*
    [dummy, data = 0] -> n1 -> n2 -> n3 -> n4 ............
    the actual list will begin from n1 i.e. dummy->next
    so, dummy->next is the head
    */
    Node *temp = dummy;
    int carry = 0;
    while(p1!=NULL  || p2!=NULL || carry
    !=0){
        int sum = 0;
        if(p1 != NULL){
            sum = sum+p1->data;
            p1 = p1->next; 
        }
        if(p2 != NULL){
            sum = sum+p2->data;
            p2 = p2->next;
        }
        sum = sum + carry;
        carry = sum/10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        /*
        initially temp was pointing to dummy
        after temp->next = node
        temp points to n1
        */
        temp = temp->next;

    }
    return dummy->next;
}

void displayList(Node *head){
    Node *p;
    p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    Node *l1 = new Node(0);
    Node *l2 = new Node(0);
    Node *l3 = new Node(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;
    displayList(l1);

    cout<<endl;
    Node *p1 = new Node(0);
    Node *p2 = new Node(0);
    Node *p3 = new Node(2);
    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;
    displayList(p1);

    Node *ans;
    ans = addTwoNumbers(l1, p1);
    cout<<endl;
    displayList(ans);

    return 0;
    
}
