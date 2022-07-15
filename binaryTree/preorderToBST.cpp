/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi , int &i)
{
    if (i >= preorder.size() )
        return NULL ;
    
    if ( preorder[i] < mini || preorder[i] > maxi)          // IF THE ELEMENT IS NOT SUITABLE FOR THE POSTION ATTACH NULL NODE
        return NULL ;
    
    BinaryTreeNode<int>* node = new BinaryTreeNode<int> (preorder[i++]) ;
    
    node->left = solve(preorder,mini,node->data ,i) ;                           // FIRST GO FOR THE LEFT CALL
    node->right = solve(preorder, node->data ,maxi,i) ;             // THEN CHECK IF IT SUITABLE FOR THE POSITION OR ELSE ATTACH NULL
    
    return node ;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i=0 ;
    int mini = INT_MIN ;
    int maxi = INT_MAX ;
    
    return solve(preorder,mini,maxi,i) ;
  
}