#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t, i, j, ip;
	cin>>t;
	while(t--)
	{
	    cin>>ip;
	    vector<int>nums;
	    nums.push_back(1);
	    for(i=2; i<=ip; i++){
	        int carry = 0;
	        for(j=0; j<nums.size(); j++)
	        {
	            int mul = (nums[j]*i) + carry ;
	            nums[j] = mul%10;
	            carry = mul/10;
	        }
	        while(carry)
	        {
	            nums.push_back(carry%10);
	            carry/=10;
	        }
	    }
	    for(i=nums.size()-1; i>=0; i--)
	    {
	        cout<<nums[i];
	    }
	    cout<<"\n";
	}
	return 0;
}