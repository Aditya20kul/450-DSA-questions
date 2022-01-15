#include<bits/stdc++.h>
using namespace std;

int numberOfWaysTD(int n, int k, vector<int>&dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=0;
    for(int i=1; i<=k; i++){
        ans += numberOfWaysTD(n-i, k, dp);
    }
    return dp[n]=ans;
}

int numberOfWaysBU(int n, int k){
    vector<int>dp(n+1, 0);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

int main(){
    int i, sum=0;
    string s;
    int numberOfStairs, maxSteps;
    cin>>numberOfStairs>>maxSteps;
    vector<int>dp(numberOfStairs+1, 0);
    //cout<<"Number of Ways - "<<numberOfWaysTD(numberOfStairs, maxSteps, dp);
    cout<<"Number of Ways - "<<numberOfWaysBU(numberOfStairs, maxSteps);

    return 0;
}