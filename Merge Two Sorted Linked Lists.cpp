#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* dummy=new Node<int>(-1);
    Node<int>* cur=dummy;
    while(first && second)
    {
        if(first->data<second->data)
        {
            cur->next=first;
            first=first->next;
            cur=cur->next;        
        }
        else
        {
            cur->next=second;
            second=second->next;
            cur=cur->next;   
        }
    }

    if(first)
      cur->next=first;
    if(second)
      cur->next=second;
    
    return dummy->next;
}
