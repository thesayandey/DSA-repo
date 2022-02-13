/*
416. Partition Equal Subset Sum
platform: Leetcode
topic: Dynamic Programming
Link: https://leetcode.com/problems/partition-equal-subset-sum/
*/

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum = sum + nums[i];
    }   
    if(sum % 2 != 0){
        return false;
    }
    int tar = sum/2;
    int len = nums.size();

    vector<vector<bool>> dp;
    dp.resize(len+1);
    for(int i=0; i<len+1; i++){
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
                    int val = nums[i-1];
                    if(val<=j){
                        if(dp[i-1][j-val] == true){
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    return dp[len][tar];

}

int main(){
   
}