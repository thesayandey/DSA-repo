//BFS graph traversal
//we are going to use queue

#include<iostream>
#include<vector>
#include<queue>
using namespace std; 

class solution{
    public:
        vector<int> getBfsOfGrapg(int v, vector<int> adj[]){
            //v is no of nodes
            vector<int> bfs;
            vector<int> vis(v+1, 0);    //initializing all the elements of the visited vector with 0

            for(int i=1; i<=v; i++){
                if(!vis[i]){

                    //queue<int
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;

                    while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        for(auto it : adj[node]){
                            if(!vis[it]){
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
            }
            return bfs;
        }
};