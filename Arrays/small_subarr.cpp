//https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include<bits/stdc++.h>
using namespace std;
int sb(int arr[], int n, int x)
{
    // Your code goes here   
    int i=0, j=0, sum=0, min_len=n, len=0;
    while(i<n)
    {
        if(sum > x){
            min_len = min(min_len, len);
            if(min_len == 1)
            {
                break;
            }
            else{
                sum -= arr[j];
                j++;
                len--;
            }
        }
        else{
            sum += arr[i++];
            len++;
        }
    }
    while(sum > x){
        sum -= arr[j++];
        len--;
        if(sum>x){
             min_len = min(min_len, len);
        }
    }
    return min_len;
}

int main()
{
   int i,j,cnt=0;
    int arr[] = {6, 3, 4, 5, 4, 3, 7, 9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int x = 16;
    cout<<sb(arr, sz, x);
   return 0;
}