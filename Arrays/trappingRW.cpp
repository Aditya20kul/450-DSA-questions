#include<bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n){

    // Your code here
    int right_max[n], left_max[n], i, j, ans=0;
    right_max[n-1] = arr[n-1];
    left_max[0] = arr[0];
    for(i=1; i<n; i++){
        left_max[i] = max(left_max[i-1], arr[i]);
    }
    for(i=n-2; i>=0; i--){
        right_max[i] = max(right_max[i+1], arr[i]);
    }
    for(i=0;i<n;i++){
        ans += abs(min(left_max[i], right_max[i]) - arr[i]);
    }
    return ans;
}

int main()
{
   int i,j,cnt=0;
   int arr[] = {7,4,0,9};
   int sz = sizeof(arr)/sizeof(arr[0]);
   cout<<trappingWater(arr, sz);
   return 0;
}