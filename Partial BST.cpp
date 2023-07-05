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

bool f(BinaryTreeNode<int> *root,int lower,int higher)
{
    if(!root)
      return true;
    
    if(root->data<lower || root->data>higher)
      return false;
    
    bool left=f(root->left,lower,root->data);
    bool right=f(root->right,root->data,higher);

    if(left && right)
      return true;
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return f(root,INT_MIN,INT_MAX);
}
