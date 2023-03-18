// Set unset prefixes
class Node{
    private:
    Node* links[26] ;
    int pre,end;
    public:
    Node(){
        for (int i=0; i<26; i++) links[i]=NULL;
        pre=0;
        end=0;
    }

    bool has(char ch){
        return ( links[ch-'a']!=NULL ) ;
    }
    Node* get(char ch){
        return links[ch-'a'] ;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setPrefix(){
        pre++;
    }
    void unsetPrefix(){
        pre--;
    }
    void setEnd(){
        end++;
    }
    void unsetEnd(){
        end--;
    }
    int getPrefix(){
        return pre;
    }
    int getEnd(){
        return end;
    }
    int ans(){
        return pre;
    }
};

class Trie{
    private:
    Node* root = new Node() ;
    public:
    void insertWord(string &s, int start, int end){
        Node* node = root;
        bool newWord=false;
        node->setPrefix();
        for (int i=start; i<=end; i++){
            char ch = s[i] ;
            if (!node->has(ch)){
                newWord=true;
                node->put(ch, new Node() );
            }
            node = node->get(ch) ;
            node->setPrefix();
        }
        node->setEnd();

        if (newWord==false){
            node=root;
            node->unsetPrefix();
            for (int i=start; i<=end; i++){
                char ch = s[i] ;
                node = node->get(ch);
                node->unsetPrefix();
            }
            node->unsetEnd();
        }
    }

    int getAns(){
        return root->ans() + 1 ;
    }

};


int countDistinctSubstrings(string &s)
{
    Trie* root = new Trie() ;
    int n = s.size();
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            root->insertWord(s,i,j) ;
        }
    }
    return root->getAns();
}








