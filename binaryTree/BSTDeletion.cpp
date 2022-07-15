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

node* minimumNode(node* root)
{
    while(root->left!=NULL)
        root= root->left ;
    return root ;
}

node* deletion(node* root, int x)
{
    if (root==NULL)
        return root ;
    if (root->data == x)
    {
        // 0 child nodes
        if (root->left==NULL && root->right == NULL){
            delete root ;         // EVEN IF WE REMOVE THE NODE, THERES NO PROBLEM WE CAN SIMPLY ATTACH NULL
            return NULL ;
        }

        // 1 child node

        // Left child             // IF THE NODE HAS A ONLY LEFT/RIGHT CHILD, THEN REMOVE THE NODE AND ATTACH IT TO THE LEFT/RIGHT CHILD
        if (root->left!=NULL && root->right==NULL)     
        {
            node* temp = root->left ;
            delete root ;
            return temp ;
        }

        // Right child 
        if (root->left==NULL && root->right!=NULL)
        {
            node* temp = root->right ;
            delete root ;
            return temp ;
        }

        // 2 child nodes

        if (root->left!=NULL && root->right!=NULL)
        {
            int mini = minimumNode(root->right)->data ;    // FIND THE PREDECESSOR OR SUCCESSOR AND PUT IT INTO THE PLACE OF NODE
            root->data = mini ;
            root->right = deletion(root->right,mini) ;      // NOW DELETE THE PREDECESSOR OR SUCCESOR
            return root ;
        }
    }
    else
    {
        if (x > root->data)
        {
            root->right = deletion(root->right,x) ;
            return root ;
        }
        else
        {
            root->left = deletion(root->left,x) ;
            return root ;
        }
    }
}

int main()
{

    node* root = NULL ;

    cout<<"Enter Data to create BST : "<<endl;
    takeinput(root) ;
    // 50 20 70 10 30 90 110 -1

    cout<<"\nPrinting using Level Order Traversal : "<<endl;
    levelOrderTraversal(root) ;


    cout<<"\nPrinting using InOrder Traversal : "<<endl;
    inOrderTraversal(root) ;


    cout<<"\nPrinting using PreOrder Traversal : "<<endl;
    preOrderTraversal(root) ;

    cout<<"\nPrinting using PostOrder Traversal : "<<endl;
    postOrderTraversal(root) ;
    

    deletion(root,90) ;

    cout<<"\nPrinting using Level Order Traversal : "<<endl;
    levelOrderTraversal(root) ;
    return 0 ;
}