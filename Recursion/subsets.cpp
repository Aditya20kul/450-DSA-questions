#include<bits/stdc++.h>
using namespace std;
void subsets(string s, int idx, string curr){
    if(idx==s.size()){
        cout<<curr<<" ";
        return;
    }
    subsets(s, idx+1, curr);
    curr += s[idx];
    subsets(s, idx+1, curr);
}
int main(){
    string s,curr="";
    cin>>s;
    int idx=0;
    subsets(s, idx, curr);
    return 0;
}