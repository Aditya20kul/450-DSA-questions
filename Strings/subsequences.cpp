#include<bits/stdc++.h>
using namespace std;
 
void generate(string str, string out, set<string>&st){
    // Include the char at current idx
    if(str.empty()){
        st.insert(out);
        return;
    }
    generate(str.substr(1), out+str[0], st);
    generate(str.substr(1), out, st);
}
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    //int n = sizeof(arr)/sizeof(arr[0]);
    string str,out="";
    set<string>st;
    cin>>str;
    //n = str.size();
    //int idx=0;
    generate(str, out, st);
    cout<<"SubSequences of "<<str<<" are as follows -\n";
    for(auto i : st){
        cout<<i<<"\n";
    }
    return 0;
}