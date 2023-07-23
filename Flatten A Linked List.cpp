/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* left,Node* right) 
{
	Node* temp=new Node(-1);
	Node* res=temp;
	while(left && right)
	{
		if(left->data<right->data)
		{
			res->child=left;
			res=res->child;
			left=left->child;
		}
		else
		{
			res->child=right;
			res=res->child;
			right=right->child;
		}
	}
	if(left)
	  res->child=left;
	if(right)
	  res->child=right;
	
	return temp->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)
	  return head;
	
	Node* left = head;
	Node* sorted = flattenLinkedList(head -> next);
	left->next = NULL;
	Node* ans = merge(left, sorted);

	return ans;
}
