/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *h1=firstHead;
    Node *h2=secondHead;
    while(h1!=h2)
    {
        if(h1==NULL)
          h1=secondHead;
        else
          h1=h1->next;

        if(h2==NULL)
          h2=firstHead;
        else
          h2=h2->next;
    }

    return h1->data;
}
