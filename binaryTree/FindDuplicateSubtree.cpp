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
    void preorder(TreeNode* root, string &s){
        if (!root){
            s.push_back('x') ;
            return;
        }
        s.push_back('n') ;
        string tmp = to_string(root->val) ;
        for (auto it : tmp)
            s.push_back(it) ;

        s.push_back('l') ;
        preorder(root->left,s) ;
        s.push_back('r') ;
        preorder(root->right,s) ;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) return {} ;
        unordered_map<string,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root) ;

        while (!q.empty()){
            auto front = q.front() ; q.pop() ;
            string tmp = "" ;
            preorder(front,tmp) ;

            if (!mp.count(tmp))
                mp[tmp] = NULL;
            else
                mp[tmp] = front;
            
            if (front->left) q.push(front->left) ;
            if (front->right) q.push(front->right) ;
        }

        vector<TreeNode*> ans;
        for (auto &[s,node] : mp){
            if (node){
                cout<<s<<" ";
                ans.push_back(node) ;
            }
        }
        return ans;
    }
};
