// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include<bits/stdc++.h>
using namespace std;
 
int median(vector<vector<int>> &matrix, int r, int c){
        int mini=INT_MAX, maxi = INT_MIN, i;
        for(i=0; i<r; i++)
        {
            mini = min(mini, matrix[i][0]);
            maxi = max(maxi, matrix[i][c-1]);
        }
        int desired = ((r*c)+1)/2;
        while(mini<maxi)
        {
            int place = 0;
            int mid = mini + ((maxi-mini)/2);
            for(i=0;i<r;i++){
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(place < desired){
                mini = mid+1;
            }
            else{
                maxi = mid;
            }
        }
        return mini;
    } 
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int> >matrix{{1,3,5}, {2,6,9}, {3,6,9}};
    cout<<median(matrix, 3, 3);
    return 0;
}