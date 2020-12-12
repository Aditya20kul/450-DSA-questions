/*
	Cylically Rotate the array by 'p' positions (Clockwise)

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

void rotate(ll arr[], ll len, ll pos)
{
	if(pos>=len){
		pos = pos%len;
	}
	while(pos--)
	{
		ll tmp = arr[len-1];
		for(int i=len-2;i>=0;i--)
		{
			arr[i+1]=arr[i];
		}
		arr[0]=tmp;
	}
}


int main()
{
	fastio;
	ll i,j,cnt=0,n,pos,len;
	ll arr[] = {1,2,3,4,5};
	cin>>pos;
	len=5;
	cout<<"Array before rotation\n";
	for(i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	rotate(arr, len, pos);
	cout<<"\nArray after being rotated Clockwise by "<<pos<<" positions\n";
	for(i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}