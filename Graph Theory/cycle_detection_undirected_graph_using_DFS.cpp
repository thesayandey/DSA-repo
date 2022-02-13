#include<iostream>
#include<vector>
using namespace std;

bool dfs(int src, int par, vector<int> adj[], vector<bool> &vis){
    vis[src] = true;
    for(auto x : adj[src]){
        if(!vis[x]){
            if(dfs(x, src, adj, vis)){
                return true;
            }
            else if(x!=par){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]){
    vector<bool> vis(v, false);
    for(int i=0; i<v; i++){
        bool check = dfs(i, -1, adj, vis);
        if(check == true){
            return true;
        }    
    }
    return false;
}