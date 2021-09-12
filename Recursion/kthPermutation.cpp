#include<bits/stdc++.h>
using namespace std;


void permute(string ip, int st, int end, vector<string>&ans){
    if(st==end){
        ans.push_back(ip);
    }
    for(int i=st; i<=end; i++){
        swap(ip[st], ip[i]);
        permute(ip, st+1, end, ans);
        swap(ip[st], ip[i]);
    }
}

string getPermutation(int A, int B) {
    string ip="";
    for(int i=1; i<=A; i++){
        ip += to_string(i);
    }
    //string ans;
    vector<string>ans;
    permute(ip, 0, ip.size()-1, ans);
    
    return ans[B-1];

}


int main(){
    int t,i,cnt=0,ans;
    int num;
    int x;
    cin>>num>>x;
    cout<<getPermutation(num, x);
    return 0;
}