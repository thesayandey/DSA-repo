#include<iostream>
using namespace std;

int main(){
    int m,n;
    //n = no of nodes
    //m = no of edges
    cin>>n>>m;

    int adj_mat[n+1][n+1];  //Creating adjacency matrix

    for(int i=0; i<m; i++){
        int p,q;
        cout<<"Enter the edges "<<endl;
        cin>>p>>q;
        adj_mat[p][q] = 1;
        adj_mat[q][p] = 1;
    }
    return 0;
}