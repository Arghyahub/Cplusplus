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

Node* reverse(Node* head)
{
    if (head==NULL || head->next == NULL)
    {
        return head ;
    }
    
    Node* chotaHead = reverse(head->next) ;             // this is used only to traverse to the last node

    head->next->next = head ;   // say elements==2 , 1️⃣⮕3️⃣⮕.. => 1️⃣⮕ ⬅3️⃣
    head->next = NULL ;         // now point the first node to null  NULL⬅1️⃣⬅3️⃣

    return chotaHead ;                                  // here we return the address of the last node 
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
    head = reverse(head) ;
    cout<<"\nAfter reversal : \n" ;

    print(head) ;
    

    return 0 ;
}