#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fillLps(string str, string pat, int sz1, int sz2, int *lps){
    int ptr = 1, len=0, i;
    lps[0]=0;
    while(ptr < sz2){
        if(pat[ptr]==pat[len]){
            len++;
            lps[ptr] = len;
            ptr++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[ptr]=0;
                ptr++;
            }
        }
    }
}

void kmpSearch(string str, string pat, int sz1, int sz2){
    int lps[sz2],i;
    fillLps(str, pat, sz1, sz2, lps);
    cout<<"Printing LPS Array - \n";
    int ptr1=0, ptr2=0;
    while(ptr1 < sz1){
        if(str[ptr1] == pat[ptr2]){
            ptr1++;
            ptr2++;
        }
        if(ptr2==sz2){
            cout<<"Pattern found at "<<(ptr1-ptr2)<<"\n";
            ptr2 = lps[ptr2-1];
        }
        else if(ptr1<sz1 && (pat[ptr2]!=str[ptr1])){
            if(ptr2!=0){
                ptr2 = lps[ptr2-1];
            }
            else{
                ptr1++;
            }
        }
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str, pat;
  cin>>str>>pat;
  int sz1 = str.size();
  int sz2 = pat.size();
  int lps[sz2];
  kmpSearch(str, pat, sz1, sz2);
  return 0;
}