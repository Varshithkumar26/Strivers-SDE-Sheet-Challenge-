/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node *cur=head;
     int len=0;
     while(cur)
     {
          len++;
          cur=cur->next;
     }

     k=k%len;
     Node *dummy=new Node(-1);
     dummy->next=head;
     Node *fast=dummy;
     Node *slow=dummy;
     for(int i=0;i<k;i++)
       fast=fast->next;
     
     while(fast->next)
     {
          slow=slow->next;
          fast=fast->next;
     }

     fast->next=dummy->next;
     dummy->next=slow->next;
     slow->next=NULL;
     
     return dummy->next;

}
