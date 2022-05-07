#include <bits/stdc++.h> 
using namespace std ;
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
    cout<<endl;
}

Node *findMiddle(Node *head) {  // find number of elements than traverse to the middle element
	int count = 0 ;
	Node* temp = head ;
    while (temp!=NULL)
	{
		count++ ;
		temp = temp->next ;
	}
	
	int n = count/2 ;
// 	cout<<n<<endl;
	
	temp = head ;
	while(n--)
	{
		temp=temp->next ;
	}
	return temp ;
}
int main()
{
    int n ;
    Node* head = NULL ;
    cout<<"Enter Number of elements : " ;
    cin>>n ;

    cout<<"Enter Elements : ";
    while (n--)
    {
        int d ;
        cin>>d ;
        insertAtHead(head,d) ;
    }
    print(head) ;

    Node* mid = findMiddle(head) ;
    cout<<"Middle element : "<<mid->data<<endl ;

    return 0 ;
}