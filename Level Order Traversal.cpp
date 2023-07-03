#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    if(root==NULL)
        return ans;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int> * n=q.front();
            ans.push_back(n->val);
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right); 
            q.pop();
        }
        
    }
    return ans;
}
