#include<bits/stdc++.h>
using namespace std;


void dist(vector<int>adj[], int v, int src){
    vector<int>distance(v, 1000000);
    distance[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto it: adj[x]){
            if(distance[x]+1 < distance[it]){
                distance[it] = distance[x]+1;
                q.push(it);
            }
        }
    
    }
    for(int dis : distance){
        cout<<dis<<" ";
    }
    
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
    dist(adj, n, 0);
    //cout<<"Shortest Distance - "<<dist(adj, n, 0);
    return 0;

}