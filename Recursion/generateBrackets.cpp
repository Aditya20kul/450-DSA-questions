#include<bits/stdc++.h>
using namespace std;

void genB(int n, string curr, int open, int close){
    if(open==n && close==n){
        cout<<curr<<" ";
        return;
    }
    if(open<n){
        genB(n, curr+'(', open+1, close);
    }
    if(close<open){
        genB(n, curr+')', open, close+1);
    }
}

int main(){
    int t,i,cnt=0,ans,n;
    cin>>n;
    int open=0, close=0;
    string curr="";
    genB(n, curr, open, close);
    return 0;
}