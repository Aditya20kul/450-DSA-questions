#include<bits/stdc++.h>
using namespace std;
 
int romanToDecimal(string &str) {
    // code here
    map<char, int>mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int ans = 0;
    for(int i=0; i<str.size(); i++){
        if(i+1 < str.size() && mp[str[i]]<mp[str[i+1]]){
            ans += mp[str[i+1]] - mp[str[i]];
            i++;
        }
        else{
            ans += mp[str[i]];
        }
    }
    return ans;
}
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    string str;
    cin>>str;
    cout<<romanToDecimal(str);
    return 0;
}