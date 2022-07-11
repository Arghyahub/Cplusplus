/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

void BSTtoinorder(TreeNode<int> *root, vector<int> &arr)
{
    if (root == NULL)
        return ;
    
    BSTtoinorder(root->left,arr) ;
    arr.push_back(root->data) ;
    BSTtoinorder(root->right,arr) ;
}

TreeNode<int>* inorderToBST(vector<int> &arr, int s , int e)
{
    if (s > e)
        return NULL ;
    
    int mid = s+(e-s)/2 ;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]) ;
    root->left = inorderToBST(arr,s,mid-1) ;
    root->right = inorderToBST(arr,mid+1,e) ;
    
    return root ;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> arr ;
    BSTtoinorder(root1,arr) ;
    BSTtoinorder(root2,arr) ;
    
    // arr has all the elements of BST1 and BST2
    
    sort(arr.begin(),arr.end()) ;
    
    
    TreeNode<int> *root = inorderToBST(arr,0,arr.size()-1) ;
    
    return root ;
}