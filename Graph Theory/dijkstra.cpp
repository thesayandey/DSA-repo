#include<bits/stdc++.h>
using namespace std;

#define V 6

int selectMinVertex(vector<int>& value,vector<bool>& processed){
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++){
        if(processed[i] == false && value[i]<minimum){
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex; //returning the vertex with min weight and that is not visited
}
void dijkstra(int graph[V][V]){
    vector<int> parent(V);
    vector<int> value(V,INT_MAX);
    vector<bool> processed(V,false);

    int src = 0; //source node
    value[src] = 0;
    parent[src] = -1; //Source dont have any parent

    for(int i=0;i<V-1;i++){
        int u = selectMinVertex(value,processed);
        processed[u] = true;

        for(int j=0;j<V;j++){
            /* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
            if(graph[u][j]!=0 && processed[j] == false && value[u]!=INT_MAX && (value[u]+graph[u][j]<value[j])){
                value[j] = value[u]+graph[u][j];
				parent[j] = u;
            }
        }
    }

    for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";

}

int main(){

    int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

    dijkstra(graph);                    
    return 0;
}