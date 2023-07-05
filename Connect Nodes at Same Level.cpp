#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int > *>q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            BinaryTreeNode< int > *n=q.front();
            q.pop();
            if(i!=s-1)
            {
                BinaryTreeNode< int > *nxt=q.front();
                n->next=nxt;
            }
            else
              n->next=NULL;
            if(n->left)
              q.push(n->left);
            if(n->right)
              q.push(n->right);
        }
    }
}
