#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cout<<"Enter elements : " ;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}

class Solution
{
    private:
    Node* reverse(Node* head)
    {
        if (head==NULL || head->next==NULL)
            return head ;
        
        Node* chotaHead=reverse(head->next) ;
        head->next->next = head ;
        head->next = NULL ;
        
        return chotaHead ;
    }
    void insertHead(Node* &head , int x)
    {
        if (head==NULL)
        {
            head= new Node(x) ;
            return ;
        }
        Node* temp = new Node(x) ;
        temp->next = head ;
        head = temp ;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first) ;
        second = reverse(second) ;
        
        Node* ans = NULL ;
        int carry=0 ;
        while (first!=NULL && second!=NULL)
        {
            int num = first->data + second->data + carry ;
            carry=num/10 ;
            insertHead(ans,num%10) ;
            first=first->next ;
            second=second->next ;
        }
        while (first!=NULL)
        {
            int num = first->data+ carry ;
            carry=num/10 ;
            insertHead(ans,num%10) ;
            first=first->next ;
        }
        while (second!=NULL)
        {
            int num = second->data+ carry ;
            carry=num/10 ;
            insertHead(ans,num%10) ;
            second=second->next ;
        }
        if (carry!=0)
            insertHead(ans,carry) ;
        
        return ans ;
    }
};


int main()
{
    int t;
    cout<<"Enter Number of test Cases : " ;
    cin>>t;
    while(t--)
    {
        int n, m;
        cout<<"Enter Size of Linked List 1 : " ;
        cin>>n;
        Node* first = buildList(n);
        
        cout<<"Enter Size of Linked List 2 : " ;
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends