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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)
      return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    int ans=0;
    while(!q.empty())
    {
        int s=q.size();
        ans=max(s,ans);
        for(int i=0;i<s;i++)
        {
            TreeNode<int> *node=q.front();
            q.pop();
            if(node->left)
              q.push(node->left);
            if(node->right)
              q.push(node->right);
        }
    }
    return ans;
}
