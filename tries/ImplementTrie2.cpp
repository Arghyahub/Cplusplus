// Keep a track of prefix and ends to find the number of prefixes and words
// ending with a specific string
#include <bits/stdc++.h> 
class Node{
    public:
    Node* links[26];
    int prefix;
    int end;
    Node(){
        for (int i=0; i<26; i++)
            links[i]=NULL;
        prefix=0;
        end=0;
    }

    bool has(char ch){
        return !(links[ch-'a']==NULL) ;
    }

    Node* get(char ch){
        return links[ch-'a'] ;
    }
    Node* put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    int isEnd(){
        return end;
    }
    bool setEnd(){
        end++;
    }
    bool setPrefix(){
        prefix++;
    }
    int isPrefix(){
        return prefix;
    }

    void deletePrefix(){
        prefix--;
    }
    void deleteEnd(){
        end--;
    }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node() ;
    }

    void insert(string &word){
        Node* tmp = root;
        for (auto ch : word){
            if (tmp->has(ch)){
                tmp = tmp->get(ch) ;
            }
            else{
                tmp = tmp->put(ch,new Node() ) ;
                tmp = tmp->get(ch) ;
            }
            tmp->setPrefix() ;
        }
        tmp->setEnd();
    }

    int countWordsEqualTo(string &word){
        Node* tmp = root;
        for (auto ch : word){
            if (tmp->has(ch))
                tmp = tmp->get(ch) ;
            else
                return 0;
        }
        return tmp->isEnd();
    }

    int countWordsStartingWith(string &word){
        Node* tmp = root;
        for (auto ch : word){
            if (tmp->has(ch))
                tmp = tmp->get(ch) ;
            else
                return 0;
        }
        return tmp->isPrefix() ;
    }

    void erase(string &word){
        Node* tmp = root;
        for (auto ch : word){
            if (!tmp->has(ch)) return;
            tmp = tmp->get(ch) ;
            tmp->deletePrefix();
        }
        tmp->deleteEnd() ;
    }
};
