//https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>
using namespace std;
 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low=0, high=(rows*cols)-1;
        //bool found=false;
        while(low<=high){
            //cout<<low<<" "<<high<<"\n";
            int mid = low + ((high-low)/2);
            //cout<<"Mid - "<<mid<<"\n";
            int i = mid/cols;
            int j = mid%cols;
            //cout<<"i - "<<i<<" j - "<<j<<"\n";
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
       return false; 
    }    
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int> >matrix{{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    //vector<vector<int> >matrix{{1,1}};
    cout<<searchMatrix(matrix, 2);
    return 0;
}