#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int>adj[], int v)
{
    vector<int>bfs;
    vector<int>visited(v, 0);
    queue<int>q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it]=1;
            }
        }
    }
    return bfs;
}


int main(){
    int n, m, u, v;
    cout<<"Enter number of nodes in a graph\n";
    cin>>n;
    cout<<"Enter number of edges in a graph\n";
    cin>>m;
    vector<int>adj[n];
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // bfs
    cout<<"BFS traversal of graph - \n";
    vector<int>ans = bfs(adj, n);
    for(auto x: ans){
        cout<<x<<" ";
    }
    
    return 0;
}