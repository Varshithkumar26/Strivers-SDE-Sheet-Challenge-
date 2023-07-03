#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int f(BinaryTreeNode<int>* root,bool &flag)
{
    if(!root)
      return 0;

    int left=f(root->left,flag);
    int right=f(root->right,flag);
    if(abs(left-right)>1)
        flag=false;
        
    return 1+max(left,right);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool flag=true;
    f(root,flag);
    return flag;
}
