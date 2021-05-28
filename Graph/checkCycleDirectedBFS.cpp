

#include<bits/stdc++.h>
using namespace std;

bool topoSort(vector<int>adj[], int v){
    vector<int>ans;
    queue<int>topo;
    vector<int>indegree(v,0);
    for(int i=0; i<v; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            topo.push(i);
        }
    }
    int cnt=0;
    while(!topo.empty()){
        int x = topo.front();
        ans.push_back(x);
        topo.pop();
        cnt++;
        for(auto it: adj[x]){
            indegree[it]--;
            if(indegree[it]==0){
                topo.push(it);
            }
        }
    }
    if(cnt==v){
        return false;
    }
    else{
        return true;
    }

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
    topoSort(adj, n) ? cout<<"Cycle exists" : cout<<"Cycle does not exists";
    // cout<<"Printing Topological Sort - \n";
    // for(auto it: res){
    //     cout<<it<<" "; 
    // } 

    return 0;
}
/*
Sample input -> 
6
6
2 3
3 1
4 0
4 1
5 0
5 2


*/