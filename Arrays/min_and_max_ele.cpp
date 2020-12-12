#include<bits/stdc++.h>
using namespace std;

int find_min(vector<int>arr)
{
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++)
    {
        mini = std::min(arr[i],mini);
    }
    return mini;
}

int find_max(vector<int>arr)
{
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++)
    {
        maxi = std::max(arr[i],maxi);
    }
    return maxi;
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
    cout<<"Minimum element is "<<find_min(arr)<<"\n";
    cout<<"Maximum element is "<<find_max(arr);
    return 0;
}


/*
    STL way -> 
    Find the minimum element
        cout << "\nMin Element = "<< *min_element(arr.begin(), arr.end());
 
    Find the maximum element
        cout << "\nMax Element = "<< *max_element(arr.begin(), arr.end());
        
*/