#include<bits/stdc++.h>
using namespace std;

const int maxi = 1000;

int lcs(string s1, string s2, int m, int n, int dp[][maxi]) 
 {
     if(m==0 || n==0 )
     {
         return 0;
     }
     if(dp[m-1][n-1]!=-1){
         return dp[m-1][n-1];
     }
     if(s1[m-1] == s2[n-1]){
         dp[m-1][n-1] = 1 + lcs(s1, s2, m-1, n-1, dp);
         return dp[m - 1][n - 1]; 
     }
     else{
         dp[m-1][n-1] = max(lcs(s1, s2, m-1, n, dp), lcs(s1, s2, m, n-1, dp));
        return dp[m-1][n-1];
     }
 }
 
int main()
{
    int n,m,i, j, cnt=0, arr[]={} ;
    string s1,s2;
    cin>>s1>>s2;
    m = s1.size();
    n = s2.size();
    int dp[m][maxi];
    memset(dp, -1, sizeof(dp));
    cout<<lcs(s1, s2, m, n, dp);
    return 0;
}