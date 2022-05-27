// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution{
private:
    Node* getmid(Node* slow)
    {
        Node* fast = slow ;
        while(fast!=NULL)
        {
            slow=slow->next ;
            fast=fast->next ;
            if (fast!=NULL)
                fast=fast->next ;
        }
        return slow ;
    }
    
    Node* reverse(Node *head)
    {
        if (head==NULL || head->next==NULL)
            return head ;
        
        Node* chotaHead=reverse(head->next) ;
        
        head->next->next = head ;
        head->next = NULL ;
        
        return chotaHead ;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head->next==NULL)
            return true ;
        Node* mid = getmid(head) ;
        Node* head1 = head ;
        Node* head2 = reverse(mid) ;
        
        while (head2!=NULL)
        {
            if (head1->data!=head2->data)
                return false ;
            head1=head1->next ;
            head2=head2->next ;
        }
        return true ;
    }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    struct Node* head = NULL ;
    int n ;
    cout<<"Enter Number of elements : " ;
    cin>>n ;
    
    for (int i=0 ; i<n; i++)
    {
        int x ;
        cin>>x ;
        struct Node* n1 = new Node(x) ;
        n1->next=head ;
        head=n1 ;
    }
    Solution obj;
    string ans=obj.isPalindrome(head)?"True":"False" ;
   	cout<<ans<<endl;
    return 0;
}

  // } Driver Code Ends