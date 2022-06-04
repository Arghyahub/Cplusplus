/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/
int count(DLLNode* first, DLLNode* second, int val)
{
    int ans = 0 ;
    while(second!=NULL && first!=NULL && first!=second && second->next!=first)
    {
        if (second->data + first->data < val)
            first=first->next ;
        else if (second->data + first->data > val)
            second = second->prev ;
        else if (second->data + first->data == val)
        {
            ans++ ;
            first=first->next ;
            second=second->prev ;
        }
    }
    return ans ;
}
int countTriplets(DLLNode* head, int x)
{
    if (head==NULL) return 0 ;
    int ans=0 ;
    DLLNode* last = head ;
    DLLNode* first = head ;
    while(last->next!=NULL) last=last->next ;
    
    while(first->next!=last)
    {
        ans = ans + count(first->next, last, x - first->data) ;
        first=first->next ;
    }
    return ans ;
}  