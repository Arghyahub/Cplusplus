// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node* reverse(Node* head)
    {
        if (head==NULL || head->next==NULL)
            return head ;
        
        Node* newhead= reverse(head->next) ;
        
        head->next->next = head ;
        head->next = NULL ;
        
        return newhead ;
    }
    public:
    Node *compute(Node *head)
    {
        if (head==NULL || head->next==NULL)
            return head ;
        
        head = reverse(head) ;
        Node* curr = head ;
        
        while(curr->next!=NULL)
        {
            if (curr->data > curr->next->data)
            {
                Node* temp = curr->next ;
                curr->next=temp->next ;
                free(temp) ;
            }
            else
                curr= curr->next ;
        }
        
        head = reverse(head) ;
        return head ;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends