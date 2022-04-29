#include<iostream>
using namespace std;

class Node
{
    public:
    int data ;
    Node *next ;

    Node(int data) // constructor
    {
        this->data=data ;
        this->next=NULL ;
    }
};

//Insertion


void inserAtHead(Node* &head,int d)
{
    // for new data create new node
    Node* temp = new Node(d) ;
    temp->next = head ;
    head = temp ;
}

void print(Node* &head)
{
    Node* temp=head ;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl ;
}

int main(){
    
    Node* node1 = new Node(10) ;

    Node* head=node1 ; // pointer to the address of the first element
    // head has nothing to do with the node, it is like a indicator
    print(head) ;

    inserAtHead(head,12) ;
    print(head) ;

    inserAtHead(head,20) ;
    print(head) ;
    return 0 ;
}