#include<bits/stdc++.h>
using namespace std;
int main()
 {
     
	int t;
	cin>>t;
	while(t--)
	{
	    int i,j,n, st;
	    cin>>n;
	    int arr[n];
	    for(i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cin>>st;
	    sort(arr, arr+n);
	    int ans = (arr[n-1]-arr[0]);
	    for(i=0; i<=n-st; i++)
	    {
	        ans = min(ans, arr[i+st-1]-arr[i]);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}

//1 