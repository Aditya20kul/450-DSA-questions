
//https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    //Your code here
    int flag=0, sum=0;
    unordered_set<int>st;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(st.find(sum)!=st.end() || sum==0 || arr[i]==0)
        {
            return true;
        }
        else
         st.insert(sum);
    }
    
    return false;
}


int main()
{
   int i,j,cnt=0;
   int arr[] = {4,2,-3,1,6};
   int sz = sizeof(arr)/sizeof(arr[0]);
   cout<<subArrayExists(arr, sz);
   return 0;
}