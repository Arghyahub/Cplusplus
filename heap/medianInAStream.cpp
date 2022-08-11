#include<queue>
int signum(int a, int b)
{
    if (a==b) return 0 ;
    else if (a>b) return 1 ;
    else return -1 ;
}

void getMedian(int element, int &median, priority_queue<int> &maxi,
              priority_queue<int,vector<int>,greater<int>> &mini)
{
    switch( signum(maxi.size(),mini.size()) )
    {
        case 0 : // maxheap.size == minheap.size
            if (element > median)
            {
                // IT WILL GO TO min HEAP(left) .:. BOTH HEAPS HAVE SAME SIZE
                mini.push(element) ;
                median = mini.top() ;
            }
            else
            {
                // IT WILL GO TO maxHeap(right)
                maxi.push(element) ;
                median = maxi.top() ;
            }
            break;
            
        case 1 : // maxheap.size > minheap.size
            // IF SIZE OF MAXHEAP IS GREATER THAN SIZE OF MINHEAP
            // ITS OUR CHOICE TO MOVE ONE ELEMENT TO THE MINHEAP TO MAKE IT EVEN
            if (element > median) // THEN MOVE THE ELEMENT
            {
                mini.push(element) ;
                median =  (mini.top() + maxi.top() )/2 ;
            }
            else // SAY THE ELEMENT IS NOT BIGGER THAN THE MEDIAN,
            {    // ELEMENT'S RIGHT PLACE IS IN THE MAXHEAP THEN,
                // THEN TO MAKE IT EVEN ON BOTH SIDE WE NEED A GREATER ELEMENT
                // WHICH WE CAN FIND IN (TOP) OF THE MAX HEAP AND THEN ADD ELEMENT TO MINHEAP
                
                mini.push(maxi.top()) ;
                maxi.pop() ;
                maxi.push(element) ;
                
                median = (mini.top() + maxi.top() )/2 ;
            }
            break ;
         
        case -1 : //  maxheap.size < minheap.size
            // THIS TIME WE WOULD LIKE TO ADD ELEMENT TO MAXHEAP TO MAKE IT EVEN
            if (element > median) // ITS NOT SUITABLE TO BE ADDED TO MAXHEAP
            {
                // EXTRACT AN ELEMENT FRON TOP OF MINHEAP
                maxi.push(mini.top()) ;
                mini.pop() ;
                mini.push(element) ;
                median = (mini.top() + maxi.top() )/2 ;
            }
            else
            {
                maxi.push(element) ;
                median = (mini.top() + maxi.top() )/2 ;
            }
            break ;
    }
}


vector<int> findMedian(vector<int> &arr, int n){
    
    vector<int> ans ;
    int median = 0 ; // At first when there is no elements --suppose
    // then the median is 0 
    priority_queue<int> maxi ;
    priority_queue<int,vector<int>,greater<int>> mini ;
    
    for (int i=0; i<n; i++)
    {
        getMedian(arr[i],median,maxi,mini) ;
        ans.push_back(median) ;
    }
    return ans ;
}
