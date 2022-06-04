/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/

DLLNode* rotateDLL(DLLNode* head, int k) 
{
    DLLNode* last= head ;
    while(last->next!=NULL) last=last->next ;
    
    last->next = head ;
    head->prev = last ;
    
    while(k--)
        head=head->next ;
    
    head->prev->next = NULL ;
    head->prev = NULL ;
    return head ;
}