// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
	//code
	int i, j, n1, n2, t, ele;
	cin>>t;
	while(t--)
	{
	    int flag=1;
	    cin>>n1>>n2;
	    //vector<int>arr;
	    set<int>st;
	    for(i=0; i<n1; i++)
	    {
	        cin>>ele;
	        st.insert(ele);
	    }
	    for(i=0; i<n2; i++)
	    {
	        cin>>ele;
	        if(st.find(ele)==st.end())
	        {
	            flag=0;
	        }
	    }
	    if(flag){
	        cout<<"Yes\n";
	    }
	    else{
	        cout<<"No\n";
	    }
	}
	return 0;
}