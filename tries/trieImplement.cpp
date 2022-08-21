#include<iostream>
using namespace std;

class TrieNode
{
    public:
        char data ;
        TrieNode* children[26] ;
        bool isTerminal ;

    TrieNode(char ch)
    {
        data = ch ;
        for (int i=0; i<26; i++)
            children[i]=NULL ;
        
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
        int index = word[0]-'A' ;
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
            root->children[index] = child ;
        }
        
        // Recursion
        insertUtil(child,word.substr(1)) ;
    }

    void insertWord(string word)
    {
        insertUtil(root,word) ;
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if ( word.length() == 0)
        {
            return root->isTerminal ;
        }

        int index = word[0] - 'A' ;

        TrieNode* child ;

        // present
        if ( root->children[index] != NULL)     // WE DON'T NEED TO COMPARE THE CHARACTERS, WE JUST NEED TO SEE IF 
        {                                       // A NODE EXISTS FOR THAT INDEX
            child = root->children[index] ;
        }
        else
        {
            // absent 
            return false ;
        }
        // recursion
        return searchUtil(child,word.substr(1)) ;
    }

    bool searchWord(string word)
    {
        return searchUtil(root,word) ;
    }

        bool prefixSearch(TrieNode* root, string word)
    {
        if (word.length()==0)
            return true;
        
        int index = word[0] - 'a' ;
        TrieNode* child ;
        
        if (root->children[index]==NULL)
        {
            return false ;
        }
        else
        {
            child = root->children[index] ;
        }
        return prefixSearch(child,word.substr(1)) ;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixSearch(root,prefix) ;
    }
};


int main(){

    Trie* t = new Trie() ;
    t->insertWord("ABCD") ;
    t->insertWord("TIME") ;
    t->insertWord("CAT") ;
    t->insertWord("CAP") ;

    cout<< "Present or Not "<< t->searchWord("ABCD") << endl;
    cout<< "Present or Not "<< t->searchWord("ABC") << endl;
    cout<< "Present or Not "<< t->searchWord("TIME") << endl;
    cout<< "Present or Not "<< t->searchWord("CA") << endl;
    cout<< "Present or Not "<< t->searchWord("CAP") << endl;

    return 0 ;
}