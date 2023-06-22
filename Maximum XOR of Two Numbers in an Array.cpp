#include <bits/stdc++.h> 

class Node{
    public:
    Node* links[2];
};

Node* insert(vector<int> A)
{
    Node* root=new Node();
    for(int i=0;i<A.size();i++)
    {
        int n=A[i];
        Node* cur=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(cur->links[bit]==NULL)
              cur->links[bit]=new Node();
            cur=cur->links[bit];
        }
    }
    return root;
}

int maximumXor(vector<int> A)
{
    // Write your code here.  
    Node* root=insert(A);
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        int n=A[i];
        Node* cur=root;
        int val=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(cur->links[bit^1]!=NULL)
            {
                val+=(1<<i);
                cur=cur->links[bit^1];
            }
            else
             cur=cur->links[bit];     
        }
        ans=max(ans,val);
    }
    return ans;


}
