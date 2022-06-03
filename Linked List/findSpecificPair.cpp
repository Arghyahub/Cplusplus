/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

*****************************************************************/

bool findPair(Node* head, int k)
{
    bool ans = 0 ;
    for (Node* temp=head; temp->next!=NULL; temp=temp->next)
    {
        for (Node* temp2=temp->next; temp2!=NULL; temp2=temp2->next)
        {
            if (temp->data + temp2->data == k)
                return 1 ;
        }
    }
    return ans ;
}

