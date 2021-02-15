// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    string str;
    cin>>str;
    int cnt1=0, cnt2=0, main_cnt=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='0'){
            cnt1++;
        }
        else if(str[i]=='1')
        {
            cnt2++;
        }
        if(cnt1==cnt2){
            main_cnt++;
            cnt1=0;
            cnt2=0;
        }
    }
    cout<<main_cnt;
    return 0;
}