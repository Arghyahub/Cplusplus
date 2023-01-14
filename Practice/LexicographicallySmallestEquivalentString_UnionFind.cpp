class UnionFind {
    public:
    char *parent;

    UnionFind(){
        parent = new char[26] ;
        for (int i=0; i<26; i++)
            parent[i] = (char)('a'+i) ;
    }

    void Union(char x, char y) {
        char c1 = Find(x) ;
        char c2 = Find(y) ;
        parent[c2-'a'] = c1;
    }

    char Find(char x){
        if (parent[x-'a']==x)
            return x;
        return parent[x-'a'] = Find(parent[x-'a']) ;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf;

        for (int i=0; i<s1.size(); i++){
            if ( uf.Find(s1[i]) <= uf.Find(s2[i]) )
                uf.Union(s1[i],s2[i]) ;
            else{
                uf.Union(s2[i],s1[i]) ;
            }
        }

        for (int i=0; i<baseStr.size(); i++)
            baseStr[i] = uf.Find(baseStr[i]) ;
        
        return baseStr;
    }
};
