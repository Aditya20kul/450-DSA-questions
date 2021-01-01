/*
    Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
    Find all the elements that appear twice in this array.
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) 
{
        vector<int>ans;
        int i=0,j=0;
        for(i=0; i<nums.size(); i++)
        {
            int temp = abs(nums[i])-1;
            if(nums[temp]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
                nums[temp]*=(-1);
            }
        }
        return ans;
}

int main()
{
    vector<int>vec{1,4,3,2,2,1};
    vector<int>res;
    res = findDuplicates(vec);
    for(auto num: res)
    {
        cout<<num<<" ";
    }
    return 0;
}