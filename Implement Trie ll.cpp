#include <bits/stdc++.h> 
class Trie{

    public:

    class Node{
        public:
        Node* links[26];
        bool isend=false;
        int count=0;
        int eow=0;
    };
    
    Node* root;
    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        int n=word.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            if(cur->links[ch-'a']==NULL)
              cur->links[ch-'a']=new Node();
            cur=cur->links[ch-'a'];
            cur->count++;
        }
        cur->isend=true;
        cur->eow++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        int n=word.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            if(cur->links[ch-'a']==NULL)
              return 0;
            cur=cur->links[ch-'a'];
        }
        if(cur->isend)
          return cur->eow;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int n=word.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            if(cur->links[ch-'a']==NULL)
              return 0;
            cur=cur->links[ch-'a'];
        }
        return cur->count;
    }

    void erase(string &word){
        // Write your code here.
        int n=word.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            cur=cur->links[ch-'a'];
            cur->count--;
        }
        if(cur->isend)
        {
            cur->isend=false;
            cur->eow--;
        }
    }
};
