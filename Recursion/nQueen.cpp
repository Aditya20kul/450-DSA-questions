#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
// Function for checking if the queen can be placed at (x,y)
bool isSafe(vector<vector<int>>board, int x, int y, int n){
    // Check if it can be placed in current column
    for(int i=0; i<x; i++){
        if(board[i][y]==1){
            return false;
        }
    }
    // Check left Diagonal
    int i=x, j=y;
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    // Check right Diagonal
    i=x;j=y;
    while(i>=0 && j<n){
        if(board[i][y]==1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool nQueen(vector<vector<int>>board, int n, int row){
    //cout<<"Row - "<<row<<"\n";
    // Base Case
    if(row==n){
        printBoard(board,n);
        return true;
    }
    // Recursive Code
    for(int i=0; i<n; i++){
        if(isSafe(board, row, i, n)){
            board[row][i]=1;
            bool success = nQueen(board, n, row+1);
            if(success){
                //cout<<"Col - "<<i<<"\n";
                return true;
            }
            board[row][i]=0;
        }
    }
    return false;
}


int main(){
    int t,i,cnt=0,ans,n;
    cin>>n;
    vector<vector<int>>board(20, vector<int>(20,0));
    cout<<nQueen(board, n, 0);
    return 0;
}