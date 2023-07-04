#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isleaf(TreeNode<int>* root)
{
  if(root->left==NULL && root->right==NULL)
    return true;
  return false;
}

void left(TreeNode<int>* root,vector<int>&a)
{
    TreeNode<int>* cur=root->left;
    while(cur)
    {
      if(!isleaf(cur))
        a.push_back(cur->data);
      if(cur->left)
        cur=cur->left;
      else 
        cur=cur->right;
    }
    return;
}

void leaf(TreeNode<int>* root,vector<int>&a)
{
    if(!root)
      return;
    if(isleaf(root))
    {
      a.push_back(root->data);
      return;
    }
    leaf(root->left,a);
    leaf(root->right,a);
}

void right(TreeNode<int>* root,vector<int>&a)
{
    TreeNode<int>* cur=root->right;
    vector<int> temp;
    while(cur)
    {
      if(!isleaf(cur))
        temp.push_back(cur->data);
      if(cur->right)
        cur=cur->right;
      else 
        cur=cur->left;
    }

    for(int i=temp.size()-1;i>=0;i--)
      a.push_back(temp[i]);
    return;
}


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.

    vector<int> ans;
    if(!root)
      return ans;
    
    if(!isleaf(root))
      ans.push_back(root->data);
    
    left(root,ans);
    leaf(root,ans);
    right(root,ans);

    
    return ans;
}
