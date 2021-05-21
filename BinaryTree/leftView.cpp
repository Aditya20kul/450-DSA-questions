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

int maxLevel = 0;

void leftView(TreeNode* root, int level){
    if(root==NULL){
        return ;
    }
    if(level>maxLevel){
        maxLevel = level;
        cout<<root->data<<"\n";
    }
    
    leftView(root->left, level+1);
    leftView(root->right, level+1);
    
}

int main(){
    TreeNode* root = buildTree();
    // Level Order Traversal of Tree
    leftView(root, 1);
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