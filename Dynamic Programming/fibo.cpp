//recursion using memoization
#include <bits/stdc++.h>
using namespace std;



int fibonacci(int n, vector<int> &memo_table){
    if(n == 1 || n==0){
        return n;
    }
    if(memo_table[n] != -1){
        return memo_table[n];
    }
    memo_table[n] = fibonacci(n-1, memo_table) + fibonacci(n-2, memo_table);
    return memo_table[n];
}

int main(){
    vector<int> memo_table(100, -1);
    int f;
    cout<<"Enter a number\n";
    cin>>f;
    int ans = fibonacci(f, memo_table);
    cout<<"\n"<<ans;

    return 0;
}