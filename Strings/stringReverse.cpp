#include<bits/stdc++.h>
using namespace std;

string revString(string s){
    for(int i=0; i<s.size()/2; i++)
    {
        swap(s[i], s[s.size()-i-1]);
    }
    return s;
} 
 
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    string s;
    getline(cin, s);
    cout<<revString(s);
    //reverse(s.begin()+2,s.begin()+5);
    //cout<<s;
    return 0;
}

// STL way of reversing a String
/*
    reverse(s.begin(), s.end()) // Used to reverse whole string
    reverse(s.begin()+pos, s.end()+pos) // Used to reverse a part of string
*/