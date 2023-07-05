#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pred=-1,succ=-1;
    BinaryTreeNode<int>* cur=root;
    while(cur)
    {
        if(cur->data<key)
        {
            pred=cur->data;
            cur=cur->right;
        }
        else
          cur=cur->left;
    }

    cur=root;
    while(cur)
    {
        if(cur->data>key)
        {
            succ=cur->data;
            cur=cur->left;
        }
        else
          cur=cur->right;
    }


    return {pred,succ};
}
