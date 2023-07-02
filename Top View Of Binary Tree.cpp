#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(!root)
      return ans;
    map<int,TreeNode<int> *> mp;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            TreeNode<int> *node=q.front().first;
            int ver=q.front().second;
            q.pop();
            if(mp.find(ver)==mp.end())
             mp[ver]=node;
            if(node->left)
              q.push({node->left,ver-1});
            if(node->right)
              q.push({node->right,ver+1});
        }
    }

    for(auto it:mp)
      ans.push_back(it.second->val);
    return ans;
}
