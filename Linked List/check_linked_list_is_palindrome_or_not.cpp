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

bool isPalindorme(Node *head){
    Node *ptr, *t = head;
    vector<int> v;

    while (ptr->next!=NULL)
    {
        v.push_back(ptr->data);
        ptr = ptr->next;
    } 
    
    if(v.size() == 1){
        return true;
    }
    else{
        for(int i=0, j=v.size()-1; i<v.size() && j>=0; i++, j--){
            if(v[i] != v[j]){
                return false;
            }
        }
        return true;
    }    
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

    Node *l1 = new Node(1);
    Node *l2 = new Node(3);
    Node *l3 = new Node(2);

    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;

    displayList(l1);

    if(isPalindorme(l1)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }

    return 0;
}


