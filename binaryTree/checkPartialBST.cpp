/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool checkBoundary(BinaryTreeNode<int> *root,int mini, int maxi)
{
    if (root==NULL)
        return true ;
       
    if (root->data >= mini && root->data <=maxi)
    {
        bool left = checkBoundary(root->left,mini,root->data) ;
        bool right = checkBoundary(root->right,root->data,maxi) ;
        return left && right ;
    }
    else
        return false ;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return checkBoundary(root, INT_MIN , INT_MAX) ;
}