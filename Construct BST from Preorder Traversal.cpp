#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* f(vector<int> &arr, int &i,int bound)
{
    if(i==arr.size() || arr[i]>bound)
      return NULL;
    TreeNode<int>* root=new TreeNode<int>(arr[i++]);
    root->left=f(arr,i,root->data);
    root->right=f(arr,i,bound);
    return root;

}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return f(preOrder,i,INT_MAX);
}
