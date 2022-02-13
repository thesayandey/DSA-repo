#include<bits/stdc++.h>
using namespace std;


int binarySearchFirstOccurence(vector<int> v, int start, int end, int key){
    int index = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(v[mid] == key){
            index = mid;
            end = mid-1;
        }
        else if(key<v[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return index;
}

int binarySearchLastOccurence(vector<int> v, int start, int end, int key){
    int index = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(v[mid] == key){
            index = mid;
            start = mid+1;
        }
        else if(key<v[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return index;
}

int main(){
    //count no of 7 in the vector
    vector<int> v = {1,2,3,5,7,7,7,10,11,25,63};
    int ans = (binarySearchLastOccurence(v,0,10,7)-binarySearchFirstOccurence(v,0,10,7))+1;
    cout<<ans;
    
    return 0;
}