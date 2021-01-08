// Best Time to Buy and Sell Stock

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int minval = INT_MAX, ans=0;
        for(int i=0; i<prices.size(); i++)
        {
            minval = min(minval, prices[i]);
            ans = max(ans, prices[i]-minval);
        }
        return ans;
}

int main()
{
    vector<int> prices{7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}