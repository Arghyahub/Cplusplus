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
        this->data = d;
        this->next = NULL ;
        this->prev = NULL ;
    }
};

void insertAtHead(Node* &head,int d)
{
    if (head == NULL)
    {
        Node* newnode = new Node(d) ;
        head = newnode ;
    }
    else
    {
        Node* newnode = new Node(d) ;
        newnode->next = head ;
        head->prev = newnode ;
        head = newnode ;
    }
}

void print(Node* head)
{
    cout<<"LL : " ;
    Node* temp = head ;
    while (temp != NULL)
    {
        cout<<temp->data<<" " ;
        temp=temp->next ;
    }
}

Node* reverse(Node* head )                      // I did it 😁
{
    if (head==NULL || head->next == NULL)
    {
        return head ;
    }

    Node* chotaNode = reverse(head->next) ;             // traverse to the last node

    head->next->next = head ;
    head->prev = head->next ;
    head->next = NULL ;


    return chotaNode ;                                  // return the last node

}

int main(){
    Node *head = NULL ;
    int n ;
    cout<<"Enter number of elements :";
    cin>>n ;
    cout<<"Enter elements :";

    while (n--)
    {
        int d ;
        cin>>d ;
        insertAtHead(head,d) ;
    }

    print(head) ;

    printf("\nBefore reversal : \n") ;
    head = reverse(head) ;
    printf("\nAfter reversal : \n") ;

    print(head) ;
    

    return 0 ;
}