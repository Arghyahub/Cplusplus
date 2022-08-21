class TrieNode
{
    public:
        char data ;
        TrieNode* children[26] ;
        bool isTerminal ;
        int childCount;

    TrieNode(char ch)
    {
        data = ch ;
        for (int i=0; i<26; i++)
            children[i]=NULL ;
        
        childCount = 0 ;
        isTerminal=false ;
    }
};

class Trie{
    public:
    TrieNode* root ;

    Trie(){
        root = new TrieNode('\0') ;
    }

    void insertUtil(TrieNode* root,string word)
    {
        // base case
        if ( word.length() == 0 ){
            root->isTerminal = true ;
            return ;
        }

        // Asuming words in upper case
        int index = word[0]-'a' ;
        TrieNode* child ;           // To move to the next child

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index] ;
        }
        else
        {
            // absent
            child = new TrieNode(word[0]) ;
            root->childCount++ ;
            root->children[index] = child ;
        }
        
        // Recursion
        insertUtil(child,word.substr(1)) ;
    }

    void insertWord(string word)
    {
        insertUtil(root,word) ;
    }
    
    void lcp(string first , string &ans)
    {
        TrieNode* temp = root ;
        for (int i=0; i<first.size(); i++)
        {
            char ch = first[i] ;
            
            if (temp->childCount==1)
            {
                ans.push_back(ch) ;
                int index = ch - 'a' ;
                temp = temp->children[index] ;
            }
            else
                break ;
            if (temp->isTerminal)
                break ;
        }
    }
    
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie();
    for (int i=0; i<n; i++)
        t->insertWord(arr[i]) ;
    
    string first = arr[0] ;
    string ans = "" ;
    
    t->lcp(first,ans) ;
    return ans ;
}


