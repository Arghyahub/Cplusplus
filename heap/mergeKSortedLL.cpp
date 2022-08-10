/************************************************************

    Following is the linked list node structure

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
#include<queue>
class compare
{
    public:
    bool operator()(Node<int>* a , Node<int>* b)
    {
        return a->data > b->data ;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    if (listArray.empty()) return NULL ;
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minheap ;
    
    for (int i=0; i<listArray.size(); i++)
        if (listArray[i]!=NULL)
            minheap.push(listArray[i]) ;
    
    Node<int>* head = NULL ;
    Node<int>* tail = NULL ;
    
    while(minheap.size()>0)
    {
        auto x = minheap.top() ; minheap.pop() ;
        if (x->next)
            minheap.push(x->next) ;
        
        if (head==NULL){
            head = x ;
            tail = x ;
        }
        else
        {
            tail->next = x ;
            tail = tail->next ;
        }
    }
    return head ;
}
