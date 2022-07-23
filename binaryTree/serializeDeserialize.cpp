/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "" ;
        if (root==NULL)
            return s ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty())           // KEEP ADDING ELEMENTS IN A STRING IN INORDER TRAVERSAL
        {
            TreeNode* front = q.front() ; q.pop() ;
            if (front==NULL)
                s.append("#,") ;
            
            else
                s.append(to_string(front->val)+",") ;
            
            if (front!=NULL)
            {
                q.push(front->left) ;
                q.push(front->right) ;
            }
        }
        s.pop_back() ;
        cout<<s<<endl ;
        return s ;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL ;
        
        stringstream ss(data) ;
        string temp ;
        
        getline(ss,temp,',') ;      // FETCH THE FIRST ELEMENT AND MAKE NODE
        
        TreeNode* root = new TreeNode(stoi(temp)) ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while(!q.empty())
        {
            TreeNode* node = q.front() ; q.pop() ;
            
            getline(ss,temp,',') ;      // FETCH SECOND ELEMENT AND PUT TO LEFT
            if (temp=="#")
                node->left = NULL ;
            
            else{
                node->left = new TreeNode(stoi(temp)) ;
                q.push(node->left) ;                        // PUSH TO QUEUE TO FURTHER IDENTIFY ITS LEFT AND RIGHT
            }
            
            
            getline(ss,temp,',') ;
            if (temp=="#")
                node->right = NULL ;
            
            else{
                node->right = new TreeNode(stoi(temp)) ;
                q.push(node->right) ;
            }
            
        }
        return root ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));