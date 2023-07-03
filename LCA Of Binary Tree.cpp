#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *f(TreeNode<int> *root, int x, int y)
{
    if(!root)
      return NULL;
    
    if(root->data==x || root->data==y)
      return root;
    
    TreeNode<int>* left=f(root->left,x,y);
    TreeNode<int>* right=f(root->right,x,y);

    if(left==NULL)
      return right;
    if(right==NULL)
      return left;
    return root;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return f(root,x,y)->data;
}
