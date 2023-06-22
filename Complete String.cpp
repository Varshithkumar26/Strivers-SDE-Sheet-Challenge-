#include <bits/stdc++.h> 

class Node{
    public:
    Node* links[26];
    bool isend=false;
};

Node* insert(int n, vector<string> &a)
{
    Node* root=new Node();
    for(int i=0;i<n;i++)
    {
        Node* cur=root;
        string s=a[i];
        for(int j=0;j<s.length();j++)
        {
            if(cur->links[s[j]-'a']==NULL)
              cur->links[s[j]-'a']=new Node();
            cur=cur->links[s[j]-'a'];
        }
        cur->isend=true;
    }
    return root;
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    Node* root=insert(n,a);
    
    string ans;
    for(int i=0;i<n;i++)
    {
        Node *cur=root;
        string s=a[i];
        bool flag=true;
        for(int j=0;j<s.length();j++)
        {
            cur=cur->links[s[j]-'a'];
            if(cur->isend==false)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            if(ans.length()<s.length())
              ans=s;
            if(ans.length()==s.length() && ans>s)
              ans=s;
        }
    }

    if(ans=="")
      return "None";
    return ans;

}
