//Subset sum problem using tabulation
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;//no of elements in the input array
    int *arr;
    arr = new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int tar;
    cin>>tar;

    vector<vector<bool>> dp;
    
    dp.resize(n+1);
    for(int i=0; i<n+1; i++){
        dp[i].resize(tar+1);
    }

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(i==0){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else{
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }
                else{
                    int val = arr[i-1];
                    if(val<=j){
                        if(dp[i-1][j-val] == true){
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    if(dp[n][tar]){
        cout<<"\nPossilble";
    }
    else{
        cout<<"\nNot Possible";
    }

    return 0;
}