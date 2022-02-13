#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m,n;    //n = no of nodes, m = no of edges
    vector<int> adj_list[n+1];

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        //For an undirected graph, without weights
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    return 0;
}