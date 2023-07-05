#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* f(vector<int> &arr, int low,int high)
{
    if(low>high)
      return NULL;
    
    int mid=(low+high)/2;
    int ele=arr[mid];
    TreeNode<int>* root=new TreeNode<int>(ele);
    root->left=f(arr,low,mid-1);
    root->right=f(arr,mid+1,high);
    return root;

}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return f(arr,0,n-1);
}
