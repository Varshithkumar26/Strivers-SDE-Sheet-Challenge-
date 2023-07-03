#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool f(TreeNode<int> *root, int x,vector<int>&path)
{
	if(!root)
	  return false;

    path.push_back(root->data);
	if(root->data==x)
	  return true;
	bool left=f(root->left,x,path);
	bool right=f(root->right,x,path);
	if(left || right)
	  return true;
	path.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> path;
	f(root,x,path);
	return path;
}
