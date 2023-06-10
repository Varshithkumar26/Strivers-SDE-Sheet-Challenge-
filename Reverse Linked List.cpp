#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* dummy=NULL;
    LinkedListNode<int>* cur=head;
    while(cur)
    {
        LinkedListNode<int>* nxt=cur->next;
        cur->next=dummy;
        dummy=cur;
        cur=nxt;
    }

    return dummy;

}
