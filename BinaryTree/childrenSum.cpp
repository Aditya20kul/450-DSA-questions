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

int isSumProperty(TreeNode* root){
    if(root==NULL)return 1;
 if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int sum = 0;
    if(root->left != NULL){
        sum += root->left->data;
    }
    if(root->right != NULL){
        sum += root->right->data;
    }
    
    return (sum==root->data) && isSumProperty(root->left) && isSumProperty(root->right) ;
}

int main(){
    TreeNode* root = buildTree();
    // Level Order Traversal of Tree
    cout<<isSumProperty(root);
    return 0;
}
/*
        10
       /  \
      5    5
    /  \   
   2    3
Input = 10 5 2 -1 -1 3 -1 -1 5 -1 -1

*/