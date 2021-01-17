// https://leetcode.com/problems/longest-consecutive-sequence/
// Below Solution will travel every element maximum 2 times hence TC of the Solution is O(n).
#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& arr) {
        if(!arr.size()){
            return 0;
        }
        int i, j, maxLen = 1, cnt;
        int n = arr.size();
        set<int>st(arr.begin(), arr.end());
        for(auto ele : st)
        {
            if(st.find(ele-1) == st.end())
            {
                cnt=1;
                ele++;
                while(st.find(ele++)!=st.end())
                {
                    cnt++;
                }
                maxLen = max(maxLen, cnt); 
            }
        }
        return maxLen;
    }
int main()
{
   int i,j,cnt=0;
   vector<int>arr{100,4,200,1,3,2};
   cout<<longestConsecutive(arr);
   return 0;
}