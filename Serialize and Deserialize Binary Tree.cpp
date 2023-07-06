#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string ans;
    if(!root)
      return "";
    
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
           TreeNode<int> *n=q.front();
           q.pop();
           if(n==NULL)
             ans+="#,"; 
           else
           {
             ans+=to_string(n->data)+',';
             q.push(n->left);
             q.push(n->right);
           }
        }
    }

    return ans;

}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
        int n=serialized.length();
        if(n==0)
          return NULL;
        int idx=0;
        stringstream s(serialized);
        string str;
        getline(s,str,',');
        TreeNode<int>* root=new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode<int>* node=q.front();
            q.pop();
            getline(s,str,',');//str stores the char from ',' to next ','
            if(str=="#")
             node->left=NULL;
            else
            {
                TreeNode<int>* left=new TreeNode<int>(stoi(str));
                node->left=left;
                q.push(left);
            }
            getline(s,str,',');
            if(str=="#")
             node->right=NULL;
            else
            {
                TreeNode<int>* right=new TreeNode<int>(stoi(str));
                node->right=right;
                q.push(right);
            }
        }

        return root;

}



