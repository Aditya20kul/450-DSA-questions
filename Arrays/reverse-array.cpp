#include<bits/stdc++.h>
using namespace std;

void reverse_arr(vector<int>&arr)
{
    for (int i = 0; i < arr.size()/2;i++)
    {
        swap(arr[i],arr[arr.size()-i-1]);
    }
}

int main()
{
    int n,ele,i;
    vector<int>arr;
    cout<<"Enter Size - ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    reverse_arr(arr);
    cout<<"Reversed Array - \n";
    for(auto it : arr)
    {
        cout<<it<<" ";
    }
    return 0;
}

/*
    Reversal of an Array can also be done using the inbuilt functions -
        --> reverse(arr.begin(),arr.end());
    
*/