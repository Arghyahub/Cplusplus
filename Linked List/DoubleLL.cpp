#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next ;
    Node* prev ;

    Node(int d)
    {
        this->data = d ;
        this->next= NULL ;
        this->prev= NULL ;
    }

    ~Node()
    {
        int value = this->data ;
        if (next!=NULL)
        {
            delete next ;
            next = NULL ;
        }
        cout<<"Memory free for element : "<<value<<endl ;
    }
};

void print(Node* head)
{
    Node* temp = head ;
    while (temp!=NULL)
    {
        cout<<temp->data<<" " ;
        temp=temp->next ;
    }cout<<endl ;
}

int getLen(Node* head)
{
    Node*temp = head ;
    int count=0 ;
    while (temp!=NULL)
    {
        temp=temp->next ;
        count++ ;
    }
    return count ;
}

void insertAtHead(Node* &tail ,Node* &head, int d)
{
    if (head==NULL) // for empty list
    {
        Node* temp = new Node(d) ;
        head = temp ;
        tail=temp ;
        return ;
    }
    //1 Create new Node
    Node* temp = new Node(d) ;
    // 2 Put temp's next to the the prev address(head)
    temp->next = head ;
    //3 Put head's prev to the address of temp
    head->prev = temp ;

    // 4 Head is in wrong positon put it int right position
    head=temp ;
}

void insertAtTail(Node* &head,Node* &tail,int d)
{
    if (head==NULL)
    {
        Node* temp = new Node(d) ;
        head = temp ;
        tail= temp ;
        return ;
    }
    // 1. Create new node
    Node* n = new Node(d) ;

    // 3. Attach the address of new node to the end node
    tail->next = n ;

    /// 4. Attach previous of new node to temp
    n->prev = tail ;

    // update tail
    tail = n ;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d)
{
    if (position==1) // for 1st position
    {
        insertAtHead(tail,head,d) ;
        return ;
    }

    // for diff position
    Node* temp = head ;
    int count= 1 ;

    while (count<position-1)
    {
        temp = temp->next ;
        count++ ;
    }// we have reached the priv position

    // if position == last then use insertAtTail
    if (temp->next==NULL)
    {
        insertAtTail(head,tail,d) ;
        return ;
    }
    
    Node* n = new Node(d) ;

    // if middle position
    Node* nextElement = temp->next ;

    n->next = nextElement ;
    n->prev = temp ;

    // now for temp and nextElement
    temp->next = n ;
    nextElement->prev = n ;


}

void deletenode(Node* &tail,Node* &head, int position)
{
    Node* temp = head ;
    if (position==1)
    {
        temp->next->prev = NULL ;
        head = temp ->next ;

        temp->next=NULL ;
        delete temp ;
        return ;
    }
    int count= 1 ;
    while (count<position)
    {
        count++ ;
        temp= temp->next ;
    }

    if (temp->next==NULL) // last node
    {
        temp->prev->next = NULL ;
        tail=temp->prev ;

        temp->prev = NULL ;
        delete temp ;
    }
    else
    {
        temp->prev->next = temp->next ;
        temp->next->prev = temp -> prev ;

        temp->next = NULL ;
        temp->prev = NULL ;
        delete temp ;
    }
}

int main(){
    Node* node1 = new Node(10) ;
    Node* head = node1 ;
    Node* tail = node1 ;

    print(head) ;
    
    insertAtHead(tail,head,999) ;

    print(head) ;

    insertAtTail(head,tail,-444) ;

    print(head) ;

    insertAtPosition(tail,head,3,0) ;

    print(head) ;

    insertAtPosition(tail,head,5,777) ;

    print(head) ;

    cout<<"Head : "<<head->data<<endl ;
    cout<<"Tail : "<<tail->data<<endl ;


    deletenode(tail,head,4) ;
    print(head) ;
    cout<<"Head : "<<head->data<<endl ;
    cout<<"Tail : "<<tail->data<<endl ;
    return 0 ;
}