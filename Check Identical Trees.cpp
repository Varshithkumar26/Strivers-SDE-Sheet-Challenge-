#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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

***********************************************************/

bool f(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(!root1)
      return root2==NULL;
    if(!root2)
      return root1==NULL;
    if(root1->data!=root2->data)
      return false;
    
    bool left=f(root1->left,root2->left);
    bool right=f(root1->right,root2->right);

    if(left && right)
      return true;
    return false;
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    return f(root1,root2);
}
