class Solution {
    long long max(long long a, long long b){
        if (a>b) return a;
        return b;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size() ;
        vector<pair<int,int>> arr(n);
        for (int i=0; i<n; i++){
            arr[i] = {nums2[i],nums1[i]} ;
        }
        sort(arr.rbegin(),arr.rend()) ;
		// Sort array 1 with respect to array 2 in increasing order
		// Therefore the the last index we go, will be the minimum multiplier
        
        long long sum=0;
        long long ans=0;
		// Use minheap priority queue to store nums1 values so that when size increases above k, we can remove the smalles number
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i=0; i<n; i++){
            sum+=arr[i].second ;
            pq.push(arr[i].second) ;
            long long mini=arr[i].first;
            
            if (pq.size()>k){
                sum-=pq.top() ;
                pq.pop() ;
            }
            
            if (pq.size()==k)
                    ans=max(ans,sum*mini) ;
        }
        return ans;
    }
};
