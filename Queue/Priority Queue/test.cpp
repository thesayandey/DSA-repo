/*
Priority Queue in C++ STL
Some important functions of priority queue in stl
size() => returns the size
top() =>returns top

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    //priority_queue<int> q; here we are using default priority

    priority_queue<int, vector<int>, std::greater<int>> q; 
    vector<int> v = {8,1,6,4,0,7,2,9}; 
    for(auto it:v){
        q.push(it);
    }
    
    while (!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    
    return 0;
}
