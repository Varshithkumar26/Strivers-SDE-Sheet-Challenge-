#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> * build(int &pidx,unordered_map<int,int> &mp, vector<int> &preorder,int low,int high)
{
    if(low>high)
      return NULL;
    
    int ele=preorder[pidx];
    TreeNode<int> *root=new TreeNode<int>(ele);
    int iidx=mp[ele];
    pidx++;
    root->left=build(pidx,mp,preorder,low,iidx-1);
    root->right=build(pidx,mp,preorder,iidx+1,high);
    return root;

}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++)
      mp[inorder[i]]=i;
    
    int pidx=0;
    return build(pidx,mp,preorder,0,preorder.size()-1);
}
