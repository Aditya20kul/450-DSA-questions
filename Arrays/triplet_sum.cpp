// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

#include<bits/stdc++.h>
using namespace std;
bool find3Numbers(int arr[], int n, int x)
{
    //Your Code Here
    int flag=0, i, j;
    sort(arr, arr+n);
    for(i=0; i<n-2; i++)
    {
        int tar = x - arr[i];
        int low = i+1;
        int high = n-1;
        while(low<high)
        {
            if((arr[low]+arr[high])==tar)
            {
                return true;
            }
            else if((arr[low]+arr[high])>tar)
            {
                high--;
            }
            else{
                low++;
            }
        }
    }
    return false;
}

int main()
{
   int i,j,cnt=0;
    int arr[]={1, 4, 45, 6, 10, 8}, n=6, x=13;
    cout<<find3Numbers(arr, n, x);
   return 0;
}