#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans=-1;
    BinaryTreeNode<int> *cur=node;
    while(cur)
    {
        if(cur->data>=x)
        {
            ans=cur->data;
            cur=cur->left;
        }
        else
          cur=cur->right;
    }
    return ans;
}
