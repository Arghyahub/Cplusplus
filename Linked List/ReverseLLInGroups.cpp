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

Node* kReverse(Node* head, int k) {
    if (head==NULL || head->next==NULL)
	{
		return head ;
	}
	// say only k=2
	int count = 0 ;
	Node* curr = head;
	Node* prev = NULL ;
	Node* forward = curr->next ;
	while (curr!=NULL && count<k)
	{
		forward=curr->next ;
		curr->next=prev;
		prev = curr ;
		curr=forward ;
		count++ ;
	}
	
	// now let recursion solve the rest 
	if (forward!=NULL)
		head->next = kReverse(forward,k) ;
	
	return prev ; // here we return the previous Node
}

int main(){
    Node *head = NULL ;
    int n , k;
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
    cout<<"Enter size of group :";
    cin>>k ;

    head = kReverse(head,k) ;
    cout<<"\nAfter reversal : \n" ;

    print(head) ;
    

    return 0 ;
}