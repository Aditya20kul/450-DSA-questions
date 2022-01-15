#include<bits/stdc++.h>
using namespace std;

int findMinNode(int V, bool mstSet[], int value[])
    {
	    int mini=INT_MAX, node;
	    for(int i=0; i<V; i++){
	        if(value[i]<mini && mstSet[i]==false){
	            mini = value[i];
	            node = i;
	        }
	    }
	    return node;
	}
    int spanningTree(int V, vector<vector<int>>adj)
    {
        bool mstSet[V];
        int parent[V];
        int value[V];
        for(int i=0; i<V; i++){
            mstSet[i]=false;
        }
        for(int i=0; i<V; i++){
            value[i]=INT_MAX;
        }
        value[0]=0;
        parent[0]=-1;
        //mstSet[0]=true;
        for(int i=0; i<V; i++){
            int u = findMinNode(V, mstSet, value);
            mstSet[u]=true;
            for(int j=0; j<V; j++){
                if(mstSet[j]==false && adj[u][j]!=0 && adj[u][j]<value[j]){
                    value[j]=adj[u][j];
                    parent[j]=u;
                }
            }
        }
        int result = 0;
        
        for(int i=0; i<V; i++){
            result += value[i];
        }
        return result;
    }

int main(){
    int t,i,cnt=0,n,ans;
    string s;
    vector<vector<int>>adj{
        {0, 5, 1},
        {5, 0, 3},
        {1, 3, 0}
    };
    cout<<spanningTree(3, adj);
    return 0;
}