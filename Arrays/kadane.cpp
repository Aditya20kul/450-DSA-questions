
// Kadane's Algorithm for finding out maximum contiguous sum in an array

#include<bits/stdc++.h>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long int
#define fi first
#define se second
#define vll std::vector<ll> vl
#define ld long double
using namespace std;

    int maxSubArray(vector<int>& nums) {
        int curr_sum=0, max_so_far=INT_MIN, neg_sum=0, flag=0, cnt=0, i;
        for(i=0; i<nums.size(); i++)
        {
            if(nums[i]<0)
            {
                cnt++;
                
            }
            
        }
        if(cnt==nums.size())
            {
                flag=1;
            }
        if(flag==1)
        {
            return *max_element(nums.begin(), nums.end());
        }
        else
        {
            for(int i=0; i<nums.size(); i++)
            {
                curr_sum += nums[i];
                max_so_far = max(max_so_far, curr_sum);
                if(curr_sum < 0)
                {
                    curr_sum=0;
                }
                
            }
            return max_so_far;
        }
        
    }

int main()
{
fastio;

	ll i,j,cnt=0,n;
	vector<int>arr{-1,2,4,-2,5,-6};
	cout<<maxSubArray(arr);
return 0;
}