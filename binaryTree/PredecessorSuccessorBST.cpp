/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int succ = -1 , pred = -1 ;
    BinaryTreeNode<int>* temp = root ;
    while(temp->data!=key)
    {
        if (temp->data > key)
        {
            succ = temp->data ;
            temp=temp->left ;
        }
        else
        {
            pred = temp->data ;
            temp = temp->right ;
        }
    }
    
    BinaryTreeNode<int>* leftbig = temp->left ;
    while(leftbig!=NULL)
    {
        pred = leftbig->data ;
        leftbig=leftbig->right ;
    }
    
    BinaryTreeNode<int>* rightsmall = temp->right ;
    while(rightsmall!=NULL)
    {
        succ = rightsmall->data ;
        rightsmall = rightsmall->left ;
    }
    
    pair<int,int> ans = {pred,succ} ;
    return ans ;
   
}
