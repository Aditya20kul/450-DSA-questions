#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>grid, int x, int y, int n){
    if(x>=n || y>=n || grid[x][y]=='X'){
        return false;
    }
    return true;
}

bool helper(vector<vector<char>>&grid, int x, int y, vector<int>&ans, int n){
    //cout<<"\nx- "<<x<<" y - "<<y<<"\n";

    if(!isSafe(grid, x, y, n)){
        return false;
    }
    else{
        ans.push_back((x*n)+(y)+1);
        //grid[x][y]='X';
        if(x==n-1 && y==n-1){
        return true;
    }
        if(helper(grid, x+1, y, ans, n)){
            return true;
        }
        if(helper(grid, x, y+1, ans, n)){
            return true;
        }

        return false;
        
    }
}

vector<int> findPath(int n, vector<vector<char>> c){
    ////Write your code below. Do not modify this function or parameters. You can use helper function if needed.   
    vector<int>ans;
    helper(c, 0, 0, ans, n);
    return ans;
}

int main(){
    vector<vector<char>>grid{
        {'O','O','X','O'},
        {'O','X','O','O'},
        {'O','O','O','X'},
        {'X','X','O','O'}
    };
    int n=4;
    vector<int>ans = findPath(n, grid);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}