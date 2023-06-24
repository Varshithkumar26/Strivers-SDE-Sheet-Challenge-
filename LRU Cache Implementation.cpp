#include<bits/stdc++.h>
class LRUCache {

class node{
    public:
    node* prev;
    node* next;
    int key;
    int val;
    node(int _key, int _val)
    {
      key = _key;
      val = _val;
    }
};

unordered_map<int,node*> mp;
int size;
node* head=new node(-1,-1);
node* tail=head;

public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())
          return -1;
        else
        {
            node* n=mp[key];
            if(n->next)
            {
                n->prev->next=n->next;
                n->next->prev=n->prev;
                tail->next=n;
                n->prev=tail;
                n->next=NULL;
                tail=tail->next;
            }
            return mp[key]->val;
        }

    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            get(key);
        }
        else
        {
            node* temp=new node(key,value);
            mp[key]=temp;
            tail->next=temp;
            temp->prev=tail;
            temp->next=NULL;
            tail=tail->next;
            if(mp.size()==(size+1))
            {
                mp.erase(head->next->key);
                head->next=head->next->next;
                head->next->prev=head;
            }
        }

    }
};
