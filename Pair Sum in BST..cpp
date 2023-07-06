#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

class BSTIterator {
stack<BinaryTreeNode<int>*> st;
public:
    BSTIterator(BinaryTreeNode<int>* root,bool flag) {
        while(root)
        {
            st.push(root);
            if(flag)
              root=root->left;
            else
              root=root->right;
        }
    }
    
    int next(bool flag) {
        BinaryTreeNode<int>* temp=st.top();
        st.pop();
        BinaryTreeNode<int>* cur;
        if(flag)
          cur=temp->right;
        else
          cur=temp->left;
        while(cur)
        {
            st.push(cur);
            if(flag)
              cur=cur->left;
            else
              cur=cur->right;
        }
        return temp->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTIterator* l=new BSTIterator(root,true);
    BSTIterator* r=new BSTIterator(root,false);

    int i=l->next(true);
    int j=r->next(false);
    while(i<j)
    {
        if(i+j==k)
            return true;
        if(i+j<k)
            i=l->next(true);
        else
            j=r->next(false);
    }
    return false;
}
