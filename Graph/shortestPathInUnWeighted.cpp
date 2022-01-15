#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    vector<int>adj[n+1];
    for(int i=0; i<n; i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    // for(int i=1; i<=n; i++){
    //     for(auto it: adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    vector<bool>vis(n+1, false);
    vector<int>dis(n+1, 100000000);
    dis[s]=0;
    vector<int>pred(n+1, -1);
    pred[s]=s;
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto v: adj[front]){
            if(vis[v]==false){
             	if(dis[v]>(1+dis[front])){
                	dis[v]=1+dis[front];
                	pred[v]=front;
            	}
            	q.push(v);
            	vis[v]=true;   
            }
        }
    }
    // for(auto j: pred){
    //     cout<<j<<" ";
    // }
    vector<int>ans;
    ans.push_back(t);
    int tmp = pred[t];
    while(tmp!=s){
        ans.push_back(tmp);
        tmp = pred[tmp];
    }
    ans.push_back(s);
	reverse(ans.begin(), ans.end());
    for(int i: ans){
        cout<<i<<" ";
    }
    return ans;
}

int main(){
    int t,i,cnt=0,n;
    string s;
    vector<pair<int, int>>edges{
        {1, 2},
        {2 ,3},
        {3 ,4},
        {1 ,3}
    };
    vector<int> ans = shortestPath(edges, 4, 4, 1, 4);
    return 0;
}