
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char* reverse(char *S, int len)
{
    //code here
    stack<char> st;
    for(int i=0; i<len; i++){
        st.push(S[i]);
    }
    int i=0;
    char res[len];
    while(!st.empty()){
        char ch = st.top();
        st.pop();
        S[i++]=ch;
    }
    return S;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  vector<int>vec;
  ll t;
  cin>>t;
  while(t--){
      char str[10000];
      cin>>str;
      ll len = strlen(str);
      char *ch = reverse(str, len);
      cout<<ch;
      cout<<endl; 
  }

  return 0;
}
