#include<bits/stdc++.h>
using namespace std;

int getMax(int pos, int maxSteps, int steps, unordered_map<int, int>mp, int toys, vector<int>dp){
    if(steps==maxSteps){
        return toys;
    }
    if(dp[pos]!=-1){
        return dp[pos];
    }
    if(mp.find(pos)!=mp.end()){
        toys += mp[pos];
        mp[pos]=0;
    }
    int m = getMax(pos+1, maxSteps, steps+1, mp, toys, dp);
    int n = getMax(pos-1, maxSteps, steps+1, mp, toys, dp);
    return dp[pos]=max(m,n);
}

int main(){
    int i, sum=0, n;
    string s;
    int maxSteps=4;
    int x=0;
    vector<int>cords{-5, -1, 2, 5};
    vector<int>candies{10, 2, 3, 1};
    vector<int>dp(10, -1);
    unordered_map<int, int>mp;
    for(int i=0; i<cords.size(); i++){
        mp[cords[i]]=candies[i];
    }
    int toys = 0;
    cout<<getMax(x, maxSteps, 0, mp, toys, dp);

    return 0;
}