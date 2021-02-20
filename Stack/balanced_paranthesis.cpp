#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    // Your code here
    stack<char>st;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]=='['){
            st.push(x[i]);
        }
        else if(!st.empty() && (x[i]==')' || x[i]=='}' || x[i]==']')){
            if(st.top() == '(' && x[i]==')'){
                st.pop();
            }
            else if(st.top() == '{' && x[i]=='}'){
                st.pop();
            }
            else if(st.top() == '[' && x[i]==']'){
                st.pop();
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
 
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    string str;
    cin>>str;
    ispar(str) ? cout<<"Balanced" : cout<<"Not Balanced";
    return 0;
}