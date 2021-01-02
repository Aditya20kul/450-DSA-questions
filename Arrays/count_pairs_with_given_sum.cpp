#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
    {
        int c=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(m.find(k-arr[i])!=m.end())
            {
                c+=m[k-arr[i]];
            }
            m[arr[i]]++;
        }
        return c;
    }

int main()
{
    int arr[]={1,5,7,1}, n=4, k=6;
    cout<<getPairsCount(arr,n,k);
}