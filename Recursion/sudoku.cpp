#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> >&input, int x, int y, int num, int n){
    for(int i=0; i<n; i++){
        if(input[i][y]==num){
            return false;
        }
    }
    for(int i=0; i<n; i++){
        if(input[x][i]==num){
            return false;
        }
    }
    int nx = (x/3)*3;
    int ny = (y/3)*3;
    for(int i=nx; i<nx+3; i++){
        for(int j=ny; j<ny+3; j++){
            if(input[i][j]==num){
                return false;
            }
        }
    }
    
    return true;
}

bool helper(vector<vector<int>>&input, int i, int j, int n){
    
    if(i==n){
        return true;
    }
    if(j==n){
        return helper(input, i+1, 0, n);
    }
    if(input[i][j]!=0){
        return helper(input, i, j+1, n);
    }
    for(int k=1; k<=n; k++){
        if(isSafe(input, i, j, k, n)){
            input[i][j]=k;
            if(helper(input, i, j+1, n)){
                return true;
            }
        }
        
    }
    input[i][j]=0;
    return false;
}

vector<vector<int> > solveSudoku(vector<vector<int> > input){
    vector<vector<int>>board(input.begin(), input.end());
    int ans = helper(board, 0, 0, input.size());
    return board;
}

int main(){
    vector<vector<int>>board{
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    vector<vector<int>>ans = solveSudoku(board);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}