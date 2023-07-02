#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if(!root)
      return ans;
    map<int,vector<TreeNode<int> *>> mp;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            TreeNode<int> *node=q.front().first;
            int ver=q.front().second;
            q.pop();
            mp[ver].push_back(node);
            if(node->left)
              q.push({node->left,ver-1});
            if(node->right)
              q.push({node->right,ver+1});
        }
    }

    for(auto it:mp)
    {
        for(auto it1:mp[it.first])
          ans.push_back(it1->data);
    }
      
    return ans;
}
