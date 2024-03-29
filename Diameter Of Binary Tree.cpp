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

int f(TreeNode<int> *root,int &ans)
{
    if(!root)
      return 0;
    
    int left=f(root->left,ans);
    int right=f(root->right,ans);
    ans=max(ans,right+left);

    return 1+max(left,right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans=0;
    f(root,ans);
    return ans;
}
