// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
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
            
        Node* chotahead = reverse(head->next) ;
        
        head->next->next = head ;
        head->next = NULL ;
        
        return chotahead ;
    }
    public:
    Node* addOne(Node *head) 
    {
        head = reverse(head) ;
        head->data = head->data+1 ;
        int carry = 0 ;
        Node* temp = head ;
        Node* prev =NULL ;
        while(temp!=NULL)
        {
            int n = temp->data + carry ;
            int x = n%10 ;
            carry = n/10 ;
            
            temp->data = x ;
            prev=temp ;
            temp = temp->next ;
        }
        
        if (carry>0)
        {
            Node* n1 = new Node(carry) ;
            prev->next = n1 ;
        }
        
        head = reverse(head) ;
        
        return head ;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends