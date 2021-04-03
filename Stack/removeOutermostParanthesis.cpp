#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string removeOuterParentheses(string S)
{
        string ans="";
        int open=0;
        for(char c : S){
            if(c=='(' && open++ > 0){
                ans+=c;
            }
            if(c==')' && open-- > 1){
                ans+=c;
            }
        }
        return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i,j,t,n,cnt=0;
  string str;
  vector<int>vec;
  cin>>str;
  cout<<removeOuterParentheses(str);
  return 0;
}