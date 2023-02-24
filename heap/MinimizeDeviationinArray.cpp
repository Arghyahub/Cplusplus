// Great Question, the question is simple but the problem is
// WE don't know the bound, how many times do we have to perform the operations

// We se that when we multiply odd number by2 we get a cycle of n->2n->n, better we push odd to 2n
// And then bring all big numbers lower

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX, diff=INT_MAX ;
        for (auto e : nums){
            int elem = (e&1)? e*2:e ;
            pq.push(elem) ;
            mini = min(mini,elem) ;
        }

        while (!(pq.top()&1)){
            int high = pq.top() ;
            pq.pop() ;
            diff = min(diff,high-mini) ;
            high/=2 ;
            mini = min(mini,high) ;
            pq.push(high) ;
        }

        return min(diff,pq.top()-mini) ;
    }
};

/*Just finding the minimum and subtracting it doesn't work
like for 3,5 => 6,10 => 6,5 of (5,6) before changing the top we should keep track of difference too
*/

