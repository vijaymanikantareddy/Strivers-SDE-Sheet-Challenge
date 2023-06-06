#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preorder(TreeNode* root, vector<int>& res){
    if(root == NULL){
        return;
    }
    res.push_back(root->data);
    preorder(root->left, res);    
    preorder(root->right, res);

}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> res;
    preorder(root, res);
    return res;
}
