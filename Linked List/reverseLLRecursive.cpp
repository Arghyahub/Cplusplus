#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next ;

    Node(int d)
    {
        this->data = d;
        this->next = NULL ;
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

void reverse(Node* prev ,Node* curr, Node* &head)
{
    if (curr==NULL)
    {
        head = prev ;
        return ;
    }
    Node* forward = curr->next ;
    // curr->next = prev ;
    // prev = curr ;
    // curr = forward ;
    // reverse(prev,curr,head) ;
    curr->next = prev ;
    reverse(curr,forward,head) ;
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
    reverse(NULL,head,head) ;
    cout<<"\nAfter reversal : \n" ;

    print(head) ;
    

    return 0 ;
}