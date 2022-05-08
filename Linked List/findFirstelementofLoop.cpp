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

Node* check(Node* head)
{
    if (head==NULL)
        return head ;
    Node* fast = head ;
    Node* slow = head ;
    while (fast!=NULL)
    {
        fast = fast->next ;
        if (fast!=NULL)
        {
            fast = fast->next ;
        }
        
        slow = slow->next ;
        
        if (slow==fast)
            break ;
    }
    // now put slow to the head position again
    // but this time the speed of slow and fast will be equal = unity
    slow = head ;
    while (slow!=fast)
    {
        slow = slow->next ;
        fast = fast->next ;
    }
    return slow ;
}


int main(){
    Node* n1 = new Node(10) ;
    Node* head = n1 ;
    Node* n2 = new Node(5) ;
    n1->next = n2 ;
    Node* n3 = new Node(9) ;
    n2->next = n3 ;
    Node* n4 = new Node(2) ;
    n3->next = n4 ;
    Node* n5 = new Node(8) ;
    n4->next = n5 ;
    Node* n6 = new Node(3) ;
    n5->next = n6 ;
    n6->next = n3 ;

    /*
    10 -> 5 -> 9 -> 2 -> 8 -> 3
               ⬆⬅ ⬅ ⬅ ⬅ ⬅⬇
    */
    
    Node* ans = check(head) ;

    cout<<"Base element of loop is : "<<ans->data<<endl ;
    return 0 ;
}