#include<bits/stdc++.h>
using namespace std;

void nextPerm(vector<int>&nums)
{
    int i, flag=0, idx1, idx2;
    for(i=nums.size()-1; i>0; i--)
    {
        if(nums[i]>nums[i-1])
        {
            idx1 = i-1;
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        return;
    }
    else
    {
        for(i=nums.size()-1; i>=0; i--)
        {
            if(nums[i]>nums[idx1])
            {
                idx2 = i;
                break;
            }
        }
        //cout<<idx1<<" "<<idx2<<"\n";
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin()+idx1+1, nums.end());
    }
}

int main()
{
    vector<int>nums{1, 3, 5, 4, 2};
    //vector<int>nums{4,3,2,1};
    nextPerm(nums);
    for(auto it : nums)
    {
        cout<<it<<" ";
    }
    return 0;
}