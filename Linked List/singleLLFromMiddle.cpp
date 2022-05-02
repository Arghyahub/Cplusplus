#include<iostream>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next ;

    Node(int data)
    {
        this->data=data ;
        this->next=NULL ;
    }
    ~Node()
        {
            int value= this->data ;
            if (this->next!=NULL)
            {
                delete next;
                this->next = NULL ;
            }
            cout<< "Memory is free for node with data"<< value<<endl ;
        }
};

void insertAtHead(Node* &head,int data)
{
    // 1. First create a node
    Node* newnode = new Node(data) ;
    // 2. Attach address of head to the new node
    newnode->next = head ;
    // 3. Update the head , i.e move the head to the new position
    head = newnode ;

}

void insertAtTail(Node* &tail , int data)
{
    // 1. Create a new node
    Node* newnode = new Node(data) ;
    // 2. Add the address of new node to the address(next) of current tail
    tail->next = newnode ;
    // 3. now shift tail to the address of new node
    tail=newnode ;
}


void insertAtPosition(Node* &tail,Node* &head, int position, int data)
{
    // take a copy of head
    Node* temp = head ;
    // 1. Create a new node
    Node* newnode = new Node(data) ;

    //              say if position = 1 then call the insertAtHead func
    if (position==1)
    {
        insertAtHead(head,data) ;
        return ;
    }
    // exceptional

    // Traverse to the position
    int count=1 ;
    while (count<position-1)
    {
        temp = temp->next ;
        count++ ;
    }

    //              say it is the last element then head->next will be == 0 then call insertfromTail
    if (temp->next==NULL)
    {
        insertAtTail(head,data) ;
        return ;
    }
    
    // 2.Put the address of next element to the new node
    newnode->next = temp->next ;

    // 3. Break the link of the position element and attach it to the new node
    temp->next = newnode ;

}

void deleteNodeAtPosition(int position, Node* &head, Node* &tail)
{
    // 1. create a temp to traverse
    Node* temp = head ;
    //              say position == 1 
    if (position==1)
    {
        head=head->next ;
        temp->next=NULL ;
        delete  temp ;
        return ;
    }
    int count=1 ;
    while (count<position-1)
    {
        temp=temp->next ;
        count++ ;
    }
    Node* delElement = temp->next ;
    temp->next = delElement->next ;
    // free the space 
    if (delElement->next==NULL)
    {
        tail=temp ;
        delete delElement ;
        return ;
    }
    delElement->next=NULL ;
    delete delElement ;
}

void print(Node* head)
{
    // Node* temp = head ;
    while (head!=NULL)
    {
        cout<<head->data<<" " ;
        head = head -> next ;
    }cout<<endl ;
}


int main(){
    
    Node* n1 = new Node(10) ;
    
    Node* head = n1 ;
    Node* tail = n1 ;

    print(head) ;

    insertAtTail(tail, 20) ;
    insertAtTail(tail, 30) ;
    insertAtTail(tail, 40) ;

    print(head) ; // 10 20 30 40

    insertAtPosition(tail,head,3,25) ;
    print(head) ;


    deleteNodeAtPosition(1,head,tail) ;
    print(head) ;
    return 0 ;
}