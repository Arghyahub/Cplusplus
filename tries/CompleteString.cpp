/**
 * Q. A string is called a complete string if all its prefixes exist in the array
 */

// If prefix doesn't exist then stop the loop
#include <bits/stdc++.h> 
using namespace std;
class Node{
    public:
    Node* links[26] ;
    int end;
    int prefix;

    Node(){
        for (int i=0; i<26; i++)
            links[i] = NULL;
        end=0;
        prefix=0;
    }

    bool has(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'] ;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        end++;
    }
    void setPrefix(){
        prefix++;
    }

    int noEnds(){
        return end;
    }
    int noPrefix(){
        return prefix;
    }
};

class Trie{
    public:
    Node* root = new Node() ;

    void insertWord(string &s){
        Node* node = root;
        for (char ch : s){
            if (!node->has(ch))
                node->put(ch,new Node()) ;
            node=node->get(ch) ;
            node->setPrefix() ;
        }
        node->setEnd() ;
    }

    string longest="";
    void strUtil(string &ans, Node* node){
        for (char ch='a'; ch<='z'; ch++){
            if (node->get(ch)!=NULL && (node->get(ch))->noEnds()!=0 ){
                ans.push_back(ch) ;
                if (ans.size()>longest.size())
                    longest=ans;
                strUtil(ans,node->get(ch)) ;
                ans.pop_back() ;
            }
        }
    }

    string ans(){
        string ret;
        strUtil(ret,root) ;
        if (longest=="") return "None";
        return longest;
    }
};




string completeString(int n, vector<string> &a){
    Trie* t = new Trie() ;
    for (string &str : a){
        t->insertWord(str) ;
    }

    return t->ans() ;
}
