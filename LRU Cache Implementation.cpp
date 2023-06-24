#include<bits/stdc++.h>
class LRUCache
{

class Node{
    public:
    Node* next;
    Node* prev;
    int key;
    int val;
    Node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
};

Node* start=new Node(-1,-1);
Node* dummy=start;
unordered_map<int,Node*> mp;
int size;

public:
    LRUCache(int capacity)
    {
        // Write your code here
        size=capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(mp.find(key)==mp.end())
          return -1;
        
        Node* n=mp[key];
        if(n->next)
        {
            n->next->prev=n->prev;
            n->prev->next=n->next;
            dummy->next=n;
            n->prev=dummy;
            n->next=NULL;
            dummy=n;
        }
        
        return n->val;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            get(key);
        }
          
        
        else
        {
            Node* node=new Node(key,value);
            mp[key]=node;
            dummy->next=node;
            node->prev=dummy;
            node->next=NULL;
            dummy=dummy->next;
            if(mp.size()==size+1)
            {
                mp.erase(start->next->key);
                start->next=start->next->next;
                start->next->prev=start;
            }
        }
    }
};
