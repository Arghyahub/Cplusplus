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
        cout << node->data <<" "; 
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
class Solution{
private:
    void insertAtTail(Node* &tail, Node* temp)
    {
        tail->next = temp ;
        tail = temp ;
    }
public:
    Node* divide(int N, Node *head){
        if (head==NULL || head->next==NULL)
            return head ;
        
        Node* tail = head ;
        while(tail->next!=NULL) tail=tail->next ;
        
        Node* dummy = new Node(-1) ;
        dummy->next = head ;
        head = dummy ;
        
        
        while(N--)
        {
            if (head->next->data %2 != 0)
            {
                if (head->next->next==NULL)
                    break ;
                Node* temp = head->next ;
                head->next = head->next->next ;
                temp->next = NULL ;
                insertAtTail(tail,temp) ;
            }
            else
                head=head->next ;
        }
        
        return dummy->next ;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends