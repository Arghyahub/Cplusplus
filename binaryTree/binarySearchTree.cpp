#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left ;
    node* right ;

    node(int d)
    {
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};



void levelOrderTraversal(node* root)
{
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty())
    {
        node* temp = q.front() ; q.pop() ;

        if (temp==NULL)
        {
            cout<<endl;

            if (!q.empty())
                q.push(NULL) ;
        }
        else
        {
            cout<<temp->data<<" " ;

            if (temp->left)
                q.push(temp->left) ;
            
            if (temp->right)
                q.push(temp->right) ;
        }
    }
}

void inOrderTraversal(node* root) // L-N-R
{
    if (root==NULL)
        return ;
    
    inOrderTraversal( root->left ) ;
    cout<<root->data<<" " ;
    inOrderTraversal( root->right ) ;
}

void preOrderTraversal(node* root)  // NLR
{
    if (root==NULL)
        return ;
    
    cout<<root->data<<" " ;
    preOrderTraversal(root->left) ;
    preOrderTraversal(root->right) ;
}

void postOrderTraversal(node* root)  // LRN
{
    if (root==NULL)
        return ;
    
    postOrderTraversal(root->left) ;
    postOrderTraversal(root->right) ;
    cout<<root->data<<" " ;
}

node* insertBST(node* &root, int data)
{
    if (root==NULL)
    {
        root = new node(data) ;
        return root ;
    }

    if (data < root->data)
        root->left = insertBST(root->left,data) ;
    else
        root->right = insertBST(root->right,data) ;
    
    return root ;
}


void takeinput(node* &root)
{
    int data ;
    cin>>data ;
    while(data!=-1)
    {
        root = insertBST(root,data) ;
        cin>>data ;
    }
}

int main()
{

    node* root = NULL ;

    cout<<"Enter Data to create BST : "<<endl;
    takeinput(root) ;
    // 10 8 21 7 27 5 4 3 -1

    cout<<"\nPrinting using Level Order Traversal : "<<endl;
    levelOrderTraversal(root) ;


    cout<<"\nPrinting using InOrder Traversal : "<<endl;
    inOrderTraversal(root) ;


    cout<<"\nPrinting using PreOrder Traversal : "<<endl;
    preOrderTraversal(root) ;

    cout<<"\nPrinting using PostOrder Traversal : "<<endl;
    postOrderTraversal(root) ;
    
    return 0 ;
}