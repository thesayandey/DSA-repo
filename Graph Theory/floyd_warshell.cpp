#include<iostream>
#include<vector>
using namespace std;

void floydWarshell(int graph[v][v]){
    int dist[v][v];     //Distance matrix
    
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //Finding all pair shortest paths
    for(int k=0; k<v; ++k){
        for(int i=0; i<v; ++i){
            for(int j=0; j<v; ++j){
                if(dist[i][k] == INT8_MAX || dist[k][j] == INT8_MAX){
                    continue;   //skip if k isnt reachable from i ot j
                }
                else if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    //Checking negative edge weight cycles
    for(int i=0; i<v; i++){
        if(dist[i][i] < 0){
            cout<<"\nNegative edge weight is present\n";
        }
    }

    //Displaying the shortest path matrix
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int graph[20][20];
    floydWarshell(graph);

    return 0;
}