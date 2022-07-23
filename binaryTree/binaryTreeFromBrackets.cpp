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
#include<stack>
int findIndex(string str , int s, int e)
{
    if (s>e)
        return -1 ;
    
    stack<char> st ;
    for (int i=s; i<=e; i++)
    {
        if (str[i]=='(')
            st.push('(') ;
        
        else if (str[i]==')')
            st.pop() ;
        
        if (st.empty())
            return i ;
    }
    return -1 ;
}
BinaryTreeNode<int>* solve(string str,int start, int end)
{
    if (start > end)
        return NULL ;
    
    int digit = str[start] - '0' ;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(digit) ;
    
    int index=-1 ;
    
    if (start + 1 <= end && str[start + 1] == '(')
        index = findIndex(str, start + 1, end);
    
    if (index!=-1)
    {
        root->left = solve(str,start+2,index-1) ;
        root->right = solve(str,index+2,end-1) ;
    }
    
    return root ;
}

// 4(1(2)(2))(5(6))

BinaryTreeNode<int>* treeFromBracket(string &str)
{
    BinaryTreeNode<int>* root = solve(str,0,str.size()-1) ;
    return root ;
}
