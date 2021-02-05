// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include<bits/stdc++.h>
using namespace std;
 
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int row = 0, col=m-1, max_row=0, max_cnt=0;
	    int ptr = arr[row][col];
	    int count=0;
	    while(col>=0 && row<n)
	    {
	        if(arr[row][col]==1){
	            col--;
	            count++;
	        }
	        else if(arr[row][col]==0)
	        {
	            if(count>max_cnt){
	                max_cnt=count;
	                max_row = row;
	            }
	            row++;
	        }
	    }
	    if(count>max_cnt)
	    {
	       max_cnt=count;
	       max_row = row;
	    }
	    if(count==0){
	        return -1;
	    }
	    return max_row;
	} 
 
int main()
{
    int i, j, cnt=0, arr[]={} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int> >vec{{0,1,1,1}, {0,0,1,1}, {0,0,0,1}, {0,0,0,0}};
    cout<<rowWithMax1s(vec, 4,4);
    return 0;
}