#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        vector<int>nsr, nsl;
        stack<pair<int, int>> st1, st2;
        /// Computing Nearest Smaller Towards Left
        st1.push({heights[0], 0});
        nsl.push_back(-1);
        for(int i=1; i<sz; i++){
            int ele = heights[i];
            while(!st1.empty() && st1.top().first>=ele){
                st1.pop();
            }
            if(st1.empty()){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(st1.top().second);
            }
            st1.push({ele, i});
        }
        /// For Nearest Smaller right
        st2.push({heights[sz-1], sz-1});
        nsr.push_back(sz);
        for(int i=sz-2; i>=0; i--){
            int ele = heights[i];
            while(!st2.empty() && st2.top().first>=ele){
                st2.pop();
            }
            if(st2.empty()){
                nsr.push_back(sz);
            }
            else{
                nsr.push_back(st2.top().second);
            }
            st2.push({ele, i});
        }
        reverse(nsr.begin(), nsr.end());
        int res = 0;
        for(int i=0; i<sz; i++){
            res = max(res, (heights[i]*(nsr[i]-nsl[i]-1)));
        }
        return res;
}

int main(){
    int t,i,cnt=0,n,ans;
    string s;
    vector<int>vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(3);
    cout<<"Largest Area of Rectangle in Histogram - "<<largestRectangleArea(vec);
    return 0;
}