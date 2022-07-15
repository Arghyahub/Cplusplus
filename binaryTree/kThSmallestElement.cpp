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
int solve(BinaryTreeNode<int>* root, int k, int &i)
{
    if (root==NULL)
        return -1 ;
    
    // L
    int left = solve(root->left,k,i) ;
    if (left!=-1)                           // SAY WHILE GOING LEFT WE HAVEN'T REACHED THE LAST ELEMENT
        return left ;
     
    // N
    i++ ;                                   // KEEP INCREMENTING COUNTER WHILE GOING BACKWARDS
    if (i==k)
        return root->data ;
    
    return solve(root->right,k,i) ;         // WHILE RETURNING BACK IF YOU CAN GO ONE STEP RIGHT THEN GO AND THEN KEEP GOING LEFT
                                            // IN SEARCH OF THE SMALLEST ELEMENT ON THE RIGHT BRANCH
                                            // THEN WHEN YOU ACCESS THE ELEMENT KEEP INCREMENTING COUNTER WHILE GOING BACK
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i= 0 ;
    return solve(root,k,i) ;
}