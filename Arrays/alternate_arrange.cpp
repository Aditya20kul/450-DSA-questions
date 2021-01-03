/*
  Arrange the positive and negative elements of array Alternately.
  TC of below Solution - O(n)
  SC = o(1)
  * Only problem with this solution is that the order of elements is not maintained 

*/


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

void arrange(vector<int>vec)
{
	int sz = vec.size();
	int left=0, right=sz-1;
	while(left<right)
	{
		if(vec[left]>=0 && vec[right]<0)
		{
			swap(vec[left], vec[right]);
			left++;
			right--;
		}
		else
		{
			if(vec[left]<0)
			{
				left++;
			}
			if(vec[right]>=0)
			{
				right--;
			}
		}
	}
	int pos;
	for(int i=0; i<sz; i++)
	{
		if(vec[i]>0){
			pos = i;
			break;
		}
	}
	for(int n=0; (pos < sz && n<pos); n+=2,pos++ )
	{
		swap(vec[n], vec[pos]);
	}
	for(auto i : vec)
	{
		cout<<i<<" ";
	}
}

int main()
{
    fastio;
	ll i,j,cnt=0,n;
	vector<int>vec{2, 3, 7, -2, -5, -9, -10};
	arrange(vec);

return 0;
}