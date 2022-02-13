#include<bits/stdc++.h>
using namespace std;

struct node{
    int parent;
    int rank;
};

struct Edge{
    int src;
    int dst;
    int wt;
};

vector<node> dsuf;
vector<Edge> mst;

int find(int v){
    if(dsuf[v].parent == -1){
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);   //Path Compression
}

void unionOpr(int fromP, int toP){
    if(dsuf[fromP].rank > dsuf[toP].rank){
        dsuf[toP].parent = fromP;
    }
    else if(dsuf[fromP].rank < dsuf[toP].rank){
        dsuf[fromP].parent = toP;
    }
    else{
        dsuf[fromP].parent = toP;
        dsuf[toP].rank = dsuf[toP].rank + 1;
    }
}

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}

void kruskalsMst(vector<Edge> &edge_list, int v, int e){
    sort(edge_list.begin(),edge_list.end(),comparator);

    int i=0, j=0;
    while (i<v-1 && j<e){
        int from = find(edge_list[j].src);
        int to = find(edge_list[j].dst);

        if(from == to){
            j++;
            continue;
        }

        unionOpr(from, to);
        mst.push_back(edge_list[j]);
        i++;
    }      
}

void printMST(vector<Edge>& mst)
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
}

int main(){
    int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

    dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i=0;i<V;++i)	//Mark all nodes as independent set
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

    vector<Edge> edge_list;
    Edge obj;
    int src, dst, wt;

    for(int i=0; i<E; i++){
        cin>>src>>dst>>wt;
        obj.src = src;
        obj.dst = dst;
        obj.wt = wt;

        edge_list.push_back(obj);
    }

    kruskalsMst(edge_list, V, E);
    printMST(mst);
    return 0;
}