//https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        int i, low=0, mid=0, high = arr.size()-1;
        while(mid<=high){
            if(arr[mid]<a){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]>=a && arr[mid]<=b){
                mid++;
            }
            else if(arr[mid]>b){
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }

int main()
{
   int i,j,cnt=0;
    vector<int>vec{1, 5, 4, 2, 8};
    threeWayPartition(vec, 3, 6);
    for(auto it : vec){
        cout<<it<<" ";
    }
   return 0;
}