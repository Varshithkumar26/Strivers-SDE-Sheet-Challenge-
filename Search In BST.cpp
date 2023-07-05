#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.

    BinaryTreeNode<int> *cur=root;
    while(cur)
    {
        if(cur->data==x)
          return true;
        if(cur->data>x)
          cur=cur->left;
        else
          cur=cur->right;
    }
    return false;

}
