// Problem Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

int count=0;
int merge(int arr[], int temp[], int low, int high, int mid)
{
    int i, j, k; 
    int inv_count = 0; 
    i = low; 
    j = mid;
    k = low;
    while((i<=mid-1) && (j<=high))
    {
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += (mid-i);
        }
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
     while (j <= high) 
        temp[k++] = arr[j++]; 

    for (i = low; i <= high; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 

}


int mergeSort(int arr[], int temp[], int low, int high)
{
    int inv_cnt=0,mid;
    if(low<high)
    {
        mid = low + (high - low)/2;
        inv_cnt += mergeSort(arr, temp, low, mid);
        inv_cnt += mergeSort(arr, temp, mid+1, high);
        inv_cnt += merge(arr, temp, low, high, mid+1);
    }
    return inv_cnt;

}

long long int NaiveinversionCount(int arr[], int n) // Naive Solution 
{
    int i, j, flg1=0, flg2=0, cnt=0;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
   int i,j,cnt=0, n=5;
   int temp[n], arr[n]={1, 20, 6, 4, 5};
   cout<<mergeSort(arr, temp, 0, n-1);
    
   return 0;
}