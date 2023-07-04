#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int f(TreeNode<int> *root,long long int &ans,int &cnt)
{
    if(!root)
      return 0;
    
    if(root->left==NULL && root->right==NULL)
      cnt++;

    long long int left=f(root->left,ans,cnt);
    long long int right=f(root->right,ans,cnt);

    ans=max(ans,left+right+1ll*root->val);

    return 1ll*root->val+max(left,right);

}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    int cnt=0;
    long long int ans=-1;
    f(root,ans,cnt);
    if(cnt==1)
      return -1;
    return ans;
}
