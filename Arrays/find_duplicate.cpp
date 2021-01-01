#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        cout<<"\nLow : "<<low<<" High : "<<high<<"\n";
        mid=(low+high)/2;
        cout<<"Mid : "<<mid<<"\n";
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        cout<<"count : "<<count<<"\n";
        if(count>mid) high=mid;
        else low=mid+1; 
    }
    return low;
}


int main()
{
    vector<int>arr{1,2,3,3,4};
    cout<<findDuplicate(arr);

    return 0;
}
