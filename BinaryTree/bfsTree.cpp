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

void bfs(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        
        int sz = q.size();
        TreeNode* temp = q.front();
        if(temp==NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
                cout<<temp->data<<" ";
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
        }
    }
    return;
}

int main(){
    TreeNode* root = buildTree();
    // Level Order Traversal of Tree
    bfs(root);
    return 0;
}