#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define prime 3

bool checkIfEqual(string str, string pat, int strIndex){
    for(int i=0; i<pat.size(); i++){
        if(str[strIndex+i]!=pat[i]){
            return false;
        }
    }
    return true;
}

ll createHash(string str, int n){
    int sz = str.size();
    ll result=0;
    for(int i=0; i<n; i++){
        result += (ll)(str[i]*((ll)pow(prime, i)));
        //cout<<result<<" ";
    }
    return result;
}

ll reCalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLen){
    ll newHash;
    newHash = oldHash - str[oldIndex];
    newHash/=prime;
    newHash += str[newIndex]*((ll)pow(prime,patLen-1)); 
    return newHash;
}

void rabinKarp(string str, string pat, int sz1, int sz2){
    ll patHash = createHash(pat, sz2);
    ll textHash = createHash(str, sz2);
    //cout<<textHash<<" "<<patHash<<"\n";
    for(int i=1; i<=(sz1-sz2+1); i++){
        if(textHash == patHash && checkIfEqual(str, pat, i-1)){
            cout<<"Pattern Found at - "<<i-1<<"\n";
        }
        if(i < sz1-sz2+1){
            textHash = reCalculateHash(str, i-1, i+sz2-1, textHash, sz2);
        }
    }
                   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,t,n,cnt=0;
    string str, pat;
    vector<int>vec;

    cin>>str>>pat;
    int sz1 = str.size();
    int sz2 = pat.size();
    rabinKarp(str, pat, sz1, sz2);

    
    return 0;
}