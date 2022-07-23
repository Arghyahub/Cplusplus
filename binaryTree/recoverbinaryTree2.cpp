/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;

    TreeNode* prevElement = NULL ;  // FOR THE FIRST CHECK, FIRST LEFTMOST ELEMENT
    
    public:
    void recoverTree(TreeNode* root) {
        
        // In order traversal to find the two elements
        traverse(root);
        
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
    
    private:
    void traverse(TreeNode* root) {
        
        if (root == NULL)
            return;
            
        traverse(root->left);
        
        
        // IN INORDER TRAVERSAL WE GO FROMT LEFT TO RIGHT, PREV IS THE LEFT MOST ELEMENT SO PREV SHOULD BE SMALLER THEN ROOT
        // IF NOT THAT IS THE FAULTY NODE

        if (firstElement == NULL && ( prevElement==NULL || prevElement->val >= root->val ) ) {
            firstElement = prevElement;
        }
    
        // If first element is found, assign the second element to the root (refer to 2 in the example above)
        if (firstElement != NULL && ( prevElement==NULL || prevElement->val >= root->val )) {
            secondElement = root;
        }        
        prevElement = root;

        // End of "do some business"

        traverse(root->right);
}
};