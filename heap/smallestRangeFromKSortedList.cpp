#include<queue>
#include<limits.h>
class node{
    public:
    int data;
    int row;
    int col;
    node(int d , int r, int c)
    {
        data = d ;
        row = r ;
        col = c ;
    }
};

class compare
{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data ;
    }
};

int kSorted(vector<vector<int>> &arr, int k, int n) {
    // BASICALLY STOP AT THE LARGEST ELEMENT AND KEEP MOVING THE OTHER POINTERS FORWARD
    // UNTILL AND UNLESS THE LIST ENDS OR YOU FIND THE MINIMUM VALUE, IF YOU GET A GREATER MAXM
    // UPDATE YOUR MAXIMUM
    priority_queue<node*,vector<node*>,compare> minheap ;
    
    int mini = INT_MAX ;
    int maxi = INT_MIN ;
    
    for (int i=0; i<k; i++)
    {
        mini = min(mini,arr[i][0]) ;
        maxi = max(maxi,arr[i][0]) ;
        node* n = new node(arr[i][0],i,0) ;
        minheap.push(n) ;
    }
    
    int itmin = mini , itmax = maxi ;
    while(!minheap.empty())
    {
        auto Node = minheap.top() ; minheap.pop() ;
        itmin = Node->data ;      // THE ELEMENT WE FETCHED, DO WE REALLY NEED TO STORE IT?
        
        if (itmax - itmin < maxi - mini)    // IF IT GIVES US THE SMALLEST RANGE THEN DO IT
        {
            maxi = itmax ;
            mini = itmin ;
        }
        
        if (Node->col + 1 < n)
        {
            int element = arr[Node->row][Node->col+1] ;
            itmax = max(itmax,element) ;            // WE ARE TRAVERSING IN A SORTED ARRAY, THE NEXT ELEMENTS
            // SHOULD BE LARGER THAN PREVIOUS, WE ARE SELECTIN AMONG THE EXISTING ELEMENTS IN MINHEAP
            // AND THE ELEMENT THAT IS GOING TO BE ADDED 
            node* N = new node(element,Node->row,Node->col+1) ;
            minheap.push(N) ;
        }
        else
            break ;
        
    }
    return (maxi - mini + 1) ;
}