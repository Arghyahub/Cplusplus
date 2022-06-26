#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d ;
        this->left = NULL;
        this->right = NULL ;
    }
};

node* buildTree(node* root)
{
    int data ;
    cout<<"Enter Data : ";
    cin>>data ;

    root = new node(data) ;

    if (data==-1)
        return NULL ;
    
    cout<<"\nFor Left of "<<root->data;
    root->left = buildTree(root->left) ;

    cout<<"\nFor Right of "<<root->data;
    root->right = buildTree(root->right) ;

    return root ;
}

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


int main()
{
    node* root = NULL ;
    /*       1
         3       5
      7   11   17
    */

    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"\n\nThe Binary Tree"<<endl;
    levelOrderTraversal(root) ;

    cout<<"\n\nThe Binary Tree Using Inorder Traversal"<<endl;
    inOrderTraversal(root) ;

    cout<<"\n\nThe Binary Tree Using Preorder Traversal"<<endl;
    preOrderTraversal(root) ;

    cout<<"\n\nThe Binary Tree Using Postorder Traversal"<<endl;
    postOrderTraversal(root) ;

    return 0 ;
}