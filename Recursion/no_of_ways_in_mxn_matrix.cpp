#include<bits/stdc++.h>
using namespace std;

int count(int m,int n){
    if(n==1 || m==1){
        return 1;
    }
    return count(m,n-1) + count(m-1,n);
}

int main(){
    int ans = count(2,4);
    cout<<ans;
    return 0;
}