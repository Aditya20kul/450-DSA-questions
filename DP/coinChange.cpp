#include<bits/stdc++.h>
using namespace std;

int sz;
int summ;
void printMatrix(int **dp){
    for(int i=0; i<=sz; i++){
        for(int j=0; j<=summ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int minNumOfCoins(vector<int>coins, int sum){
    sz = coins.size();
    summ = sum;
    bool dp[sz+1][sum+1];
    for(int i=0; i<=sum; i++)dp[0][i]=false;
    for(int i=1; i<=sz; i++)dp[i][0]=true;
    for(int i=1; i<=sz; i++){
        for(int j=1; j<=sum; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i-1][j] || dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
        }
    }
    for(int i)
    return dp[sz][sum];
}


int numOfWays(vector<int>coins, int sum){
    sz = coins.size();
    summ = sum;
    int dp[sz+1][sum+1];
    for(int i=0; i<=sum; i++)dp[0][i]=0;
    for(int i=1; i<=sz; i++)dp[i][0]=1;
    for(int i=1; i<=sz; i++){
        for(int j=1; j<=sum; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
        }
        printMatrix(dp);
    }
    return dp[sz][sum];
}

int main(){
    int i, sum=0, n;
    string s;
    
    vector<int>coins{1, 2, 3};
    sum=5;
    summ = sum;
    sz = coins.size(); 
    cout<<numOfWays(coins, sum);
    return 0;
}