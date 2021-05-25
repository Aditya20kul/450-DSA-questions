#include<bits/stdc++.h>
using namespace std;
int main(){
    // Below Code if for Undirected Unweighted graph
    int n, m, u, v;
    cout<<"Enter number of nodes in a graph\n";
    cin>>n;
    cout<<"Enter number of edges in a graph\n";
    cin>>m;
    vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

/* Below Code if for directed weighted graph

    int n, m, u, v, wt;
    cout<<"Enter number of nodes in a graph\n";
    cin>>n;
    cout<<"Enter number of edges in a graph\n";
    cin>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0; i<m; i++){
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

*/