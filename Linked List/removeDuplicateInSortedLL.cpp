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

Node * uniqueSortedList(Node * head) {
	if (head==NULL)
		return head ;
    Node* temp = head ;
	while(temp->next!=NULL)
	{
		if (temp->next->data == temp->data)
		{
			temp->next = temp->next->next ;
			continue ;
		}
		temp = temp->next ;
	}
	return head ;
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

    cout<<"\nBefore removal : \n" ;
    cout<<"\nAfter removal : \n" ;

    head = uniqueSortedList(head) ;

    print(head) ;
    

    return 0 ;
}