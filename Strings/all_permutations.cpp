#include<bits/stdc++.h>
using namespace std;
 
void printPermutations(string s, int l, int r)
{
    if(l==r){
        cout<<s<<"\n";
    }
    for(int i=l; i<=r; i++){
        swap(s[l], s[i]);
        printPermutations(s, l+1, r);
        swap(s[l], s[i]);
    }
}
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    int l=0, r=s.size()-1;
    printPermutations(s, l, r);
    return 0;
}