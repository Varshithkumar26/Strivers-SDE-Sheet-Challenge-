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

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    while(root)
    {
        if(root->left==NULL)
        {
            ans.push_back(root->data);
            root=root->right;
        }
        else
        {
            TreeNode *prev=root->left;
            while(prev->right && prev->right!=root)
              prev=prev->right;

            if(prev->right==NULL)
            {
                prev->right=root;
                root=root->left;
            } 
            else
            {
                prev->right=NULL;
                ans.push_back(root->data);
                root=root->right;
            } 
             
        }
    }
    return ans;
}
