#include<iostream>
#include<alloca.h>
#include <bits/stdc++.h>
#include<algorithm>
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

void displayList(Node *head){
    Node *p;
    p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}



bool hasCycle(Node *head){
    Node *p;
    p = head;
    vector<Node*> v(0);
    int flag = 0;
    while(p!=NULL){
        Node *check = p;
        for(int i=0; i<v.size(); i++){
            if(v[i] == check){
                return true;
            }
        }
        v.push_back(check);
        p = p->next;
    }
    return false;
}



int main(){

    Node *l1 = new Node(0);
    Node *l2 = new Node(0);
    Node *l3 = new Node(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;


    //displayList(l1);
    if(hasCycle(l1)){
        cout<<"Cycle detected :(";
    }
    else{
        cout<<"Cycle not found";
    }

    return 0;
}


