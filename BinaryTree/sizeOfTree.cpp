#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree(){
    // Enter the INput in preOrder Manner
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    TreeNode* n = new TreeNode(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;

}

int sizeOfTree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}

int main(){
    TreeNode* root = buildTree();
    // Level Order Traversal of Tree
    cout<<sizeOfTree(root);
    return 0;
}
/*
        10
       /  \
      5    15
    /  \   
   2    8
Input = 10 5 2 -1 -1 8 -1 -1 15 -1 -1

*/