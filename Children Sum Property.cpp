#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void f(BinaryTreeNode < int > * root)
{
    if(!root)
      return;
    
    int left=0;
    if(root->left)
      left=root->left->data;
    int right=0;
    if(root->right)
      right=root->right->data;
    
    if(root->data>left+right)
    {
        if(root->left)
          root->left->data=root->data;
        if(root->right)
          root->right->data=root->data;
    }

    f(root->left);
    f(root->right);

    if (root->left && root->right)
		root->data = root->left->data + root->right->data;
	else if (root->left)
		root->data = root->left->data;
	else if(root->right)
		root->data = root->right->data;
	return;
    
}

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    f(root);
    return;
}  
