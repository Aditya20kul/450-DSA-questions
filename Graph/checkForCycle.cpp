#include<bits/stdc++.h>
using namespace std;

// void printVisited(vector<int>vis){
//     cout<<"\nvisited - ";
//     for(int i=0; i<vis.size(); i++){
//         cout<<vis[i]<<" ";
//     }
//     cout<<"\n";
// }

bool checkCycle(int node, vector<int>adj[], vector<int>&visited, int v){
    queue<pair<int, int>>q;
    q.push({node, -1});
    visited[node]=1;
    while(!q.empty()){
        int curr = q.front().first;
        int prev = q.front().second;
        
        q.pop();
        for(auto it: adj[curr]){
            if(!visited[it]){
                
                visited[it] = 1;
                q.push({it, curr});
            }
            else if(prev!=it){
                cout<<"In here - "<<prev<<" "<<curr<<" "<<it;
                return true;
            }
            //printVisited(visited);
        }
    }
    return false;
}

bool isCycle(vector<int>adj[], int v){
    vector<int>visited(v+1, 0);
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            if(checkCycle(i, adj, visited, v)){
                //cout<<i;
                return true;
            }
        }
    }
    return false;
}

int main()
{
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
    for(int i=1; i<n+1; i++){
        cout<<i<<" - ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    isCycle(adj, v) ? cout<<"\nCycle Exists" : cout<<"Cycle does not exist";
    return 0;
}