#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>arr, int idx, int remSum){
    if(idx==arr.size()){
        if(remSum==0){
            return 1;
        }
        return 0;
    }

    int incCurrentNum = countSubsets(arr, idx+1, remSum-arr[idx]);
    int exlCurrentNum = countSubsets(arr, idx+1, remSum);
    return incCurrentNum + exlCurrentNum;
}

int main(){
    int t,i,cnt=0,ans;
    vector<int>arr{1,2,3,4,5};
    int target=10;
    int idx=0;
    cout<<countSubsets(arr, idx, target);
    return 0;
}