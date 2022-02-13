#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;

//find() finds the absoloute parent of a given node in the graph
int find(int v){
    if(v == -1){
        return v;
    }
    else{
        return find(parent[v]);
    }
}

//unionOprs() is used to perform the union operation in disjoint set
void unionOpr(int fromP, int toP){
    int from = find(fromP);
    int to = find(toP);
    parent[from] = to;
}

bool isCyclic(vector<pair<int, int>> &edge_list){
    for(auto it : edge_list){
        int fromP = find(it.first);
        int toP = find(it.second);

        if(fromP == toP){
            return true;//contains cycle
        }
        //Union operation
        unionOpr(fromP, toP);
    }
    return false;
}

int main(){
    int e; //no of edges
    int v; //no of nodes
    cin>>e>>v;

    parent.resize(v,-1);
    vector<pair<int, int>> edge_list;
    for(int i=0; i<e; i++){
        int from, to;
        cin>>from>>to;
        edge_list.push_back({from, to});
    }

    if(isCyclic(edge_list)){
        cout<<"TRUE\n";
    }
    else{
        cout<<"FALSE\n";
    }

    return 0;
}