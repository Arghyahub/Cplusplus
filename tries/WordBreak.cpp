class Node{
    public:
    Node* links[26] ;
    bool end;
    Node(){
        for (int i=0; i<26; i++)
            links[i] = NULL;
        end = false;
    }
    bool has(char ch){
        return (links[ch-'a']!=NULL) ;
    }
    Node* get(char ch){
        return links[ch-'a'] ;
    }
    void put(char ch, Node* tmp){
        links[ch-'a'] = tmp;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node() ;
    }
    
    void insertWord(string &s){
        Node* node = root ;
        for (auto ch : s){
            if (!node->has(ch))
                node->put(ch,new Node()) ;
            node = node->get(ch) ;
        }
        node->end = true;
    }
    
    bool search(string &word, int i){
        if (i==word.size()) return true;
        Node* node = root;
        
        bool flag = false;
        for (int j=i; j<word.size(); j++){
            if (!node->has(word[j])) return false;
            node = node->get(word[j]) ;
            if (node->end){
                flag = search(word,j+1) ;
                if (flag) return true;
            }
        }
        return flag;
    }
};

class Solution{
    public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie* t = new Trie() ;
        for (auto &str : B)
            t->insertWord(str) ;
        return t->search(A,0) ;
    }
};
