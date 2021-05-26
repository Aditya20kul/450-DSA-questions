// A bipartite graph is possible if the graph coloring is possible using two colors such that 
// vertices in a set are colored with the same color.
// Note that it is possible to color a cycle graph with even cycle using two colors.


#include<bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int node, vector<int>adj[], vector<int>&color){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){

        int curr = q.front();
        //cout<<"curr - "<<curr<<endl;
        q.pop();
        for(auto x: adj[curr]){
            //cout<<"\ncurr - "<<color[curr]<<" x - "<<color[x]<<"\n";
            if(color[x]==-1){
                color[x] = 1 - color[curr];
                q.push(x);
            }
            else if(color[x]==color[curr]){
                return false;
            }
            //cout<<"\ncurr - "<<color[curr]<<" x - "<<color[x]<<"\n-----------\n";
        }
    }
    return true;

}


bool isBipartite(vector<int>adj[], int v){
    vector<int>color(v, -1);
    // Assume that we will put value 0 as one color
    // 1 as another color
    for(int i=0; i<v; i++){
        if(color[i]==-1){
            if(!bipartiteBfs(i, adj, color)){
                return false;
            }
        }
    }
    return true;
}

int main()
{
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

    isBipartite(adj, n) ? cout<<"Bipartite Graph" : cout<<"Not a Bipartite Graph";
    return 0;
}