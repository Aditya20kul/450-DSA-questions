#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool>mp;
 bool dfs(string s, unordered_set<string>st){
        if(s=="")return true;
        if(mp.find(s)!=mp.end())return mp[s];
        for(int i=0; i<s.size(); i++){
            //cout<<s.substr(0,i+1)<<" "<<s.substr(i+1, s.size())<<"\n";
            if(st.find(s.substr(0,i+1))!=st.end() && dfs(s.substr(i+1, s.size()), st)){
                mp[(s.substr(i+1, s.size()))]=true;
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto it: wordDict){
            st.insert(it);
        }
        return dfs(s, st);
    }


int main(){
    vector<string>strs{"geek","s","for"};
    string s ="geeksforgeeks";
    cout<<wordBreak(s, strs);
    return 0;
}