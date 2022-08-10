/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inorder(vector<int> &v ,BinaryTreeNode* root)
{
    if (!root) return ;
    
    inorder(v,root->left) ;
    v.push_back(root->data) ;
    inorder(v,root->right) ;
}

void swapvalue(BinaryTreeNode* root,vector<int> &v, int &i )
{
    if (!root || i>=v.size()) return ;
    root->data = v[i++] ;
    swapvalue(root->left,v,i) ;
    swapvalue(root->right,v,i) ;
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> v ;
    inorder(v,root) ;
    
    int i=0 ;
    swapvalue(root,v,i) ;
    
    return root ;
    
}