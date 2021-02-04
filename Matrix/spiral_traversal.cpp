//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

#include<bits/stdc++.h>
using namespace std;
 
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int row_st=0, col_st=0, row_end=r, col_end=c, i, k, j;
        while(row_st<row_end && col_st<col_end)
        {
            for(i=col_st; i<col_end; i++)
            {
                ans.push_back(matrix[row_st][i]);
            }
            row_st++;
            for(i=row_st; i<row_end; i++)
            {
                ans.push_back(matrix[i][col_end-1]);
            }
            col_end--;
            if(row_st<row_end){
                for(i=col_end-1; i>=col_st; i--)
            {
                ans.push_back(matrix[row_end-1][i]);
            }
            row_end--;
            }
            if(col_st<col_end)
            {
                for(i=row_end-1; i>=row_st; i--)
            {
                ans.push_back(matrix[i][col_st]);
            }
            col_st++;
            }
            
        }
        return ans;
    } 
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int> >mat{{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

    vector<int>ans = spirallyTraverse(mat, mat.size(), mat[0].size());
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}