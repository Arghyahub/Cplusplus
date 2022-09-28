struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution                          //  CLEANER APPROACH
{
    pair<int,bool> getAns(Node* root)
    {
        if (!root) return {0,true};
        if (!root->left && !root->right) return {root->data,true} ;
        
        auto left = getAns(root->left) ;
        auto right = getAns(root->right) ;
        
        bool ansb = left.second && right.second && (root->data == left.first + right.first) ;
        int ansi = 2*(root->data) ;
        
        return {ansi,ansb} ;
    }
    public:
    bool isSumTree(Node* root)
    {
        return getAns(root).second;
    }
};