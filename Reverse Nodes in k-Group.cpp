#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	
	if(!head)
	  return head;

	Node *cur=head;
	int len=0;
	while(cur)
	{
		len++;
		cur=cur->next;
	}

	Node *dummy=new Node(-1);
	dummy->next=head;
	Node *prev=dummy;
	cur=head;
	for(int i=0;i<n;i++)
	{
		if(b[i]>0)
		{
			int k=min(b[i],len);
			len-=k;
			while(k-->1)//to reverse k nodes we do k-1 iterations not k
			{
				Node *nxt=cur->next;
				cur->next=nxt->next;
				nxt->next=prev->next;
				prev->next=nxt;
				nxt=cur->next;
			}
			prev=cur;
			cur=prev->next;
			if(len==0)
			break;
		}
		
	}
	return dummy->next;

}
