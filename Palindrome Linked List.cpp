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

LinkedListNode<int> *mid(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev=NULL;
    while(head)
    {
        LinkedListNode<int> *temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    
    if(head==NULL || head->next==NULL)
      return true;

    LinkedListNode<int> *m=mid(head);
    LinkedListNode<int> *nh=reverse(m);

    while(head && nh)
    {
        if(head->data!=nh->data)
          return false;
        
        head=head->next;
        nh=nh->next;
    }
    return true;

}
