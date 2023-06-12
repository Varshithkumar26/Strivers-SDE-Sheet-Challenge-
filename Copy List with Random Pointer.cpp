#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head)
      return NULL;
    LinkedListNode<int> *cur=head;
    while(cur)
    {
        LinkedListNode<int> *nxt=cur->next;
        LinkedListNode<int> *node=new LinkedListNode<int>(cur->data);
        cur->next=node;
        node->next=nxt;
        cur=nxt;
    }

    cur=head;
    while(cur)
    {
        if(cur->random)
          cur->next->random=cur->random->next;
        cur=cur->next->next;
    }

    cur=head;
    LinkedListNode<int>* dummy=new LinkedListNode<int>(-1);
    LinkedListNode<int>* copy=dummy;
    while(cur)
    {
        LinkedListNode<int>* nxt=cur->next->next;
        copy->next=cur->next;
        cur->next=nxt;
        cur=nxt;
        copy=copy->next;
    }

    return dummy->next;
}
