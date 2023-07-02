#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(!root)
      return ans;
    map<int,BinaryTreeNode<int> *> mp;
    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            BinaryTreeNode<int> *node=q.front().first;
            int ver=q.front().second;
            q.pop();
            mp[ver]=node;
            if(node->left)
              q.push({node->left,ver-1});
            if(node->right)
              q.push({node->right,ver+1});
        }
    }

    for(auto it:mp)
      ans.push_back(it.second->data);
    return ans;

    
}
