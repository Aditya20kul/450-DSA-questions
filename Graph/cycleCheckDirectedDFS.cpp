#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int>adj[], vector<int>&visited, vector<int>currDFS, int v){
    visited[node]=1;
    currDFS[node]=1;
    for(auto it : adj[node]){
        if(!visited[it]){
            if(checkCycle(it, adj, visited, currDFS, v))
            return true;
        }
        else if(currDFS[it]){
            cout<<it;
            return true;
        }
    }
    currDFS[node]=0;
    return false;
}


bool isCycle(vector<int>adj[], int v){
    vector<int>visited(v+1, 0);
    vector<int>currDFS(v+1, 0);
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            if(checkCycle(i, adj, visited, currDFS, v)){
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
    }

    // Printing Adjecency List
    //
    // for(int i=1; i<n+1; i++){
    //     cout<<i<<" - ";
    //     for(int j=0; j<adj[i].size(); j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    isCycle(adj, n) ? cout<<"\nCycle Exists" : cout<<"Cycle does not exist";
    return 0;
}