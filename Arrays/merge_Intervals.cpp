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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
}

int main()
{
    fastio;
	ll i,j,cnt=0,n;
	vector<vector<int>> intervals{{1,3}, {2,6}, {8,10}, {15, 18}};
	vector<vector<int>>ans = merge(intervals);
	for(auto vec : ans)
	{
		for(int i = 0; i < vec.size(); i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<"\n";
	}
return 0;
}