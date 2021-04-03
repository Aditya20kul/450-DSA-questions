// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string removeDuplicates(string S) {
        stack<char> st;
        st.push(S[0]);
        string res = "";
        for(int i=1; i<S.size(); i++)
        {
            if(!st.empty() && S[i]==st.top()){
                st.pop();
            }
            else{
                st.push(S[i]);
            }
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i,j,t,n,cnt=0;
  string str;
  vector<int>vec;
  cin>>str;
  cout<<removeDuplicates(str);

  return 0;
}