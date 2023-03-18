// Make a Binary Trie of 32 bits
// Insert all numbers of array 1 into the trie
class Node{
    private:
    Node* links[2] ;
    public:
    Node(){
        for (int i=0; i<2; i++)
            links[i] = NULL;
    }

    bool has(int a){
        return (links[a]!=NULL);
    }
    Node* get(int a){
        return links[a] ;
    }
    void put(int a, Node *node){
        links[a] = node; 
    }
};

class Trie{
    private:
    Node* root = new Node() ;
    public:

    void insertNum(int n){
        Node* node = root;
        for (int i=31; i>=0; i--){ // Traverse for 32 bits
            int bit = (n>>i) & 1; // Shift Bits from high to low and & by 1 to get the mask
            if (!node->has(bit))
                node->put(bit, new Node() ) ;
            node = node->get(bit) ;
        }
    }

    int xorNum(int n){
        int ans = 0;	// Here we will directly calculate the Xor
        Node* node = root;
        for (int i=31; i>=0; i--){
            int sBit = (n>>i) & 1;	// The current bit we have is this
            int fBit = 1 - sBit ;	// What we need to find is the negation
            if (node->has(fBit)){
                ans = ans | (1<<i) ;	// If !bit exist then their Xor will yield 1, so create a mask for that and |(Add it) it to ans
                node = node->get(fBit) ;
            }
            else{
                node = node->get(sBit) ;
            }
        }
        return ans;
    }

};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie* root = new Trie() ;
    for (int i=0; i<n; i++){	// Add elements of first array to the Try
        root->insertNum(arr1[i]) ;
    }
    int ans = 0;

    for (int i=0; i<m; i++){
        ans = max( ans , root->xorNum(arr2[i]) ) ;	// Try all combination to find !bit in the elements of array1 using the trie
    }
    return ans;
}




