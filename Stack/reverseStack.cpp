#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&st, int x){
    if(st.empty()){
        st.push(x); 
        return;
    }
    else{
        int tp = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(tp);
    }
}

void rev(stack<int>&st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    rev(st);
    insertAtBottom(st, top);
}

int main(){
    int t,i,cnt=0,n,ans;
    string s;
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    rev(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}