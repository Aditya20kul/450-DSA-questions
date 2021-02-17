#include<bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    int i, j, m, n, cnt=0, arr[]={} ;
    string s1,s2;
    cin>>s1>>s2;
    m = s1.size();
    n = s2.size();
    int dp[m+1][n+1];

    for(i=0;i<=m;i++){
        dp[i][0] = 0;
    }

    for(i=0;i<=n;i++){
        dp[0][i] = 0;
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<"\n Length of Longest Common Subsequence - "<<dp[m][n]<<"\n";
    // for(i=0; i<=m; i++){
    //     for(j=0;j<=n; j++)
    //     {
    //         cout<<dp[i][j]<<" "; 
    //     }
    //     cout<<"\n";
    // }
    cout<<"\nLongest Common Subsequence - ";
    string ans;
    i=m;j=n;
    while(i>=0 && j>=0)
    {
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
    return 0;
}