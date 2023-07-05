#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans;
    TreeNode<int> *cur=root;
    while(cur)
    {
        if(cur->val<=X)
        {
            ans=cur->val;
            cur=cur->right;
        }
        else
          cur=cur->left;
    }
    return ans;
}
