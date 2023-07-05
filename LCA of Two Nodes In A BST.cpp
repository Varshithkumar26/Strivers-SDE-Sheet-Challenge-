#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    TreeNode<int>* cur=root;
    while(cur)
    {
        if((cur->data<=p->data && cur->data>=q->data) || (cur->data>=p->data && cur->data<=q->data))
          return cur;
        if(cur->data<=p->data && cur->data<=q->data)
          cur=cur->right;
        else
          cur=cur->left;
    }
    return cur;
}
