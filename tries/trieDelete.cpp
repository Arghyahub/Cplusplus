
/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/
bool isEmpty(TrieNode* root)
{
    for (int i=0; i<26; i++)
        if (root->children[i])
            return false ;
    return true ;
}

TrieNode* delUtil(TrieNode* root, string word, int depth)
{
    if (root==NULL) return NULL ;
    if (depth==word.length())
    {
        if (root->isEnd)
            root->isEnd = false ;
        
        if (isEmpty(root))
        {
//             delete(root) ;
            root=NULL ;
        }
        return root ;
    }
    
    int index = word[depth] - 'a' ;
    
    root->children[index] = delUtil(root->children[index],word,depth+1) ;
 
    if (root->isEnd==false && isEmpty(root))
    {
//         delete(root) ;
        root = NULL ;
    }
    return root ;
}


TrieNode* solution::deleteWord(TrieNode* root, string word) {
    int depth = 0 ;
    return delUtil(root,word,depth) ;
}

