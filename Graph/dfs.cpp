#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>&visited, vector<int>adj[], vector<int>&dfsPath){
    dfsPath.push_back(node);
    visited[node]=1;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, dfsPath);
        }
    }
}


vector<int> dfsOfGraph(vector<int>adj[], int v){
    vector<int>dfsPath;
    vector<int>visited(v+1, 0);
    for(int i=1; i<=v; i++){
        if(visited[i]!=1){
            dfs(i, visited, adj, dfsPath);
        }
    }
    return dfsPath;
}



int main(){
    int n, m, u, v;
    cout<<"Enter number of nodes in a graph (node numbers will start from 1)\n";
    cin>>n;
    cout<<"Enter number of edges in a graph\n";
    cin>>m;
    vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // bfs
    cout<<"DFS traversal of graph - \n";
    vector<int>ans = dfsOfGraph(adj, n);
    for(auto x: ans){
        cout<<x<<" ";
    }
    
    return 0;
}