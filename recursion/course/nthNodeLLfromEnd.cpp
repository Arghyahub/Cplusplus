#include<iostream>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next ;

    Node(int d)
    {
        data = d ;
        next = NULL ;
    }
};

Node* getFromEnd(Node* n1,int &k) ;

int main(){
    
    Node *n1 = new Node(10) ;
    Node *n2 = new Node(20) ;  n1->next = n2 ;
    Node *n3 = new Node(30) ;  n2->next = n3 ;
    Node *n4 = new Node(40) ;  n3->next = n4 ;
    Node *n5 = new Node(50) ;  n4->next = n5 ;
    Node *n6 = new Node(60) ;  n5->next = n6 ;
    
    int k = 3 ;

    Node* ans = getFromEnd(n1,k) ;

    cout<<"Answer : "<<ans->data ;
    

    return 0 ;
}

Node* getFromEnd(Node* root, int &k)
{
    if (root==NULL)
        return NULL ;
    
    Node* product = getFromEnd(root->next,k) ;

    k-- ;
    if (k==0) return root ;

    return product ;
}