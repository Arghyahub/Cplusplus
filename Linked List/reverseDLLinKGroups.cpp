/*********************************************************

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

************************************************************/

Node* reverseDLLInGroups(Node* head, int k)
{	
    Node* curr = head ;
    int count=0 ;
    Node* nex =NULL ;
    Node* pre = NULL ;
    while(count<k && curr!=NULL)
    {
        nex = curr->next ;
        
        curr->next = pre ;
        pre = curr ;
        curr=nex ;
        count++ ;
    }
    
    
    if (curr!=NULL)
        head->next =reverseDLLInGroups(nex,k) ;
        
    return pre ;
    
}

