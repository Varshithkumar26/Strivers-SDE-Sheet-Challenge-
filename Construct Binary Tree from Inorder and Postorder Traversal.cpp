#include<bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

TreeNode<int> * build(int &pidx,unordered_map<int,int> &mp, vector<int> &postOrder,int low,int high)
{
    if(low>high)
      return NULL;
    
    int ele=postOrder[pidx];
    TreeNode<int> *root=new TreeNode<int>(ele);
    int iidx=mp[ele];
    pidx--;
    root->right=build(pidx,mp,postOrder,iidx+1,high);
    root->left=build(pidx,mp,postOrder,low,iidx-1);
    return root;

}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     unordered_map<int,int> mp;
     for(int i=0;i<inOrder.size();i++)
          mp[inOrder[i]]=i;

     int pidx=postOrder.size()-1;
     return build(pidx,mp,postOrder,0,postOrder.size()-1);
}
