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

Node* reverse(Node* back, Node* curr )
{
    if (curr==NULL )
    {
        return back ;
    }

    Node* forward = curr->next ;
    curr->next = back ;
    curr->prev = forward ;
    reverse(curr,forward) ;

    /*
    Node* curr = head ;
    Node* back = NULL ;
    while(curr!=NULL)
    {
        Node* forward = curr->next ;
        
        curr->next = back ;
        back = curr ;
        curr->prev = forward ;
        curr = forward ;
    }
    return back ;
    */

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

    cout<<"\nBefore reversal : \n" ;
    head = reverse(NULL,head) ;
    cout<<"\nAfter reversal : \n" ;

    print(head) ;
    

    return 0 ;
}