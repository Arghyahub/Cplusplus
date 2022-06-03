// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
void InsertAtHead(Node* &head,Node* &tail,int d)
{
    Node* temp = new Node(d) ;
    if (head==NULL){
        head=temp ;
        tail = head ;
    }
    else
    {
        tail->next = temp ;
        tail= temp ;
    }
}

Node* findIntersection(Node* head1, Node* head2)
{
    Node* newhead = NULL ;
    Node* newtail= NULL ;
    map<int,bool> mpp;
    Node* temp = head1 ;
    
    while(temp!=NULL)
    {
        mpp[temp->data]=1 ;
        temp=temp->next ;
    }
    
    temp = head2 ;
    while(temp!=NULL)
    {
        if(mpp[temp->data]==1)
        {
            mpp[temp->data]=0 ;
            InsertAtHead(newhead,newtail,temp->data) ;
        }
        
        temp=temp->next ;
    }
    return newhead ;
}