#include<bits/stdc++.h>
using namespace std;
  
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    string s,s1;
    cin>>s;
    s1 = s;
    reverse(s.begin(), s.end());
    !s.compare(s1) ? cout<<"Palindrome" : cout<<"Not a Palindrome";
    return 0;
}