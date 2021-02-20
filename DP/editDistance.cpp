// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

#include<bits/stdc++.h>
using namespace std;

int editDistance(string s, string t)
		{
		    // Code here
		    int n = s.size();
		    int m = t.size();
		    int dp[n+1][m+1], i, j;
		    for(i=0;i<=m;i++){
		        dp[0][i] = i;
		    }
		    for(i=0; i<=n; i++){
		        dp[i][0] = i;
		    }
		    for(i=1; i<=n; i++){
		        for(j=1; j<=m; j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j] = dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
		            }
		        }
		    }
		    return dp[n][m];
		}
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    //int n = sizeof(arr)/sizeof(arr[0]);
    string s1, s2;
    cin>>s1>>s2;
    cout<<editDistance(s1, s2);
    return 0;
}