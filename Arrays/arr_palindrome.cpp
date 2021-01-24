
// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

// Find minimum number of merge operations to make an array palindrome

#include<bits/stdc++.h>
using namespace std;
 
int minops(int arr[], int n)
{
    int low=0, high=n-1, ops=0;
    while(low <= high)
    {
        if(arr[low] == arr[high]){
            low++;
            high--;
        }
        else if(arr[low] > arr[high]){
            arr[high-1] = arr[high-1] + arr[high];
            high--;
            ops++;  
        }
        else{
            arr[low+1] = arr[low] + arr[low+1];
            low++;
            ops++;
        }
    }
    return ops;
}
 
int main()
{
    int i, j, cnt=0, arr[]={1, 4, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minops(arr, n);
    return 0;
}