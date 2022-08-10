#include<queue>
class node
{
    public:
    int data ;
    int row ;
    int col ;
    node(int data, int row, int col)
    {
        this->data = data ;
        this->row = row ;
        this->col = col ;
    }
};
class compare
{
    public:
    bool operator()(node* a ,node* b)
    {
        return a->data > b->data ;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    priority_queue<node*,vector<node*>,compare> pq ;
    
    // step 1 : add all the 1st elements of arrays in pq
    for (int i=0; i<k; i++)
    {
        node* root = new node(arr[i][0],i,0) ;
        pq.push(root) ;
    }
    
    vector<int> ans ;
    // step 2 : now fetch all the nodes and push the next node
    while(!pq.empty())
    {
        node* root = pq.top() ; pq.pop() ;
        ans.push_back(root->data) ;
        
        int i = root->row, j = root->col;
        
        if (j+1 < arr[i].size())
        {
            node* temp = new node(arr[i][j+1],i,j+1) ;
            pq.push(temp) ;
        }
    }
    return ans ;
}
