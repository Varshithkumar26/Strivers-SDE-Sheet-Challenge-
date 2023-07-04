#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(!root)
      return ans;
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool flag=true;
    vector<vector<int>> arr;
    while(!q.empty())
    {
        int s=q.size();
        vector<int> a(s);
        for(int i=0;i<s;i++)
        {
            BinaryTreeNode<int> *n=q.front();
            q.pop();
            if(flag)
              a[i]=n->data;
            else
              a[s-i-1]=n->data;
            if(n->left)
              q.push(n->left);
            if(n->right)
              q.push(n->right);
        }
        flag=!flag;
        arr.push_back(a);
    }

    for(auto it:arr)
    {
        for(auto it1:it)
          ans.push_back(it1);
    }
    return ans;
}
