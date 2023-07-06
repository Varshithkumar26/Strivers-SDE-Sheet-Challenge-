#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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

pair<int,pair<int,int>> f(TreeNode<int>* root,int s,int l,int cnt)
{
    if(!root)
      return {0,{INT_MAX,INT_MIN}};
    
    pair<int,pair<int,int>> p1=f(root->left,s,l,cnt);
    pair<int,pair<int,int>> p2=f(root->right,s,l,cnt);

    if(p1.second.second>=root->data || p2.second.first<=root->data)
      return {max(p1.first,p2.first),{INT_MIN,INT_MAX}};
    
    return {p1.first+p2.first+1,{min(p1.second.first,root->data),max(p2.second.second,root->data)}};
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int l=INT_MAX,s=INT_MIN,cnt=0;
    return f(root,s,l,cnt).first;
}
