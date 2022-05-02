#include<iostream>
using namespace std;
// circular LL doesn't need head
// only tail is sufficient to head to next data 
class Node
{
    public:
    int data ;
    Node* next ;

    Node(int d)
    {
        this->data = d ;
        this->next = NULL ;
    }

    ~Node()
    {
        int val = this->data ;
        if (this->next == NULL)
        {
            delete next ;
            next = NULL ;
        }cout<<"Memory free for element : "<<val<<endl ;
    }
};

void insertNode(Node* &tail,int check ,int d)
{
    Node* temp = new Node(d) ;
    if (tail==NULL) // if no node exist 
    {
        tail = temp ;
        temp->next = temp ; // for circular loop with one node it points towards the same node
    }
    
    else  // Non empty
    {
        // assuming the data is in the list
        Node * curr = tail ;
        while (curr->data!=check)
        {
            curr = curr->next ;
        }
        // curr representing the element 

        temp->next = curr->next ;
        curr->next = temp ;


    }
}

void print(Node* &tail)
{
    Node* temp = tail ;
    if (tail==NULL)
    {
        cout<<"The list is empty"<<endl ;
        return ;
    }

    do
    {
        cout<<temp->data<<" " ;
        temp = temp->next ;

    } while(temp != tail) ;

    cout<<endl ;
}

void deleteNode(Node* &tail,int check)
{
    if (tail==NULL)
    {
        cout<<"List is empty, please check"<<endl ;
        return ;
    }
    Node* prev = tail ;
    Node * cur = prev->next ;
    while (cur->data!=check) // assuming data exist
    {
        prev=cur ;
        cur = cur->next ;
    }

    prev->next = cur->next ;
    // for single element
    if (cur==prev)
    {
        tail=NULL ;
    }
    if (tail==cur) // greater than 2 list
    {
        tail=prev ;
    }

    cur->next = NULL ;
    delete cur ;
}


int main(){
    
    Node* tail = NULL ;
    insertNode(tail,8,5) ;

    print(tail) ;

    insertNode(tail,5,10) ;

    print(tail) ;

    insertNode(tail,10,15) ;

    print(tail) ;

    insertNode(tail,15,20) ;

    print(tail) ;

    insertNode(tail,10,12) ;

    print(tail) ;

    deleteNode(tail,5) ;
    print(tail) ;

    cout<<"Element at tail : "<<tail->data<<endl;
    return 0 ;
}