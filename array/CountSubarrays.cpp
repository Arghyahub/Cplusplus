// Return number of subarrays with maxnum > k

class Solution{
public:
	#define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    
	    ll ans=0;
	    int prevBig = -1 ;	// WE DON'T NEED TO INCLUDE PREVIOUSLY MADE SUBARRAY
	    
	    for (int i=0; i<n; i++){
	        if (arr[i]>k){		// IF THE ELEMENTS IS GREATER THAN K , THEN ONLY IT CAN MAKE SUBARRAYS
	            int curr=1;	// INCLUDE CURRENT ELEMENTS SINGULARLY
	            int left = i - (prevBig+1) ;	// TAKE LEFT ELEMENTS
	            /* SAY i=4 AND prev=2, NUMBER OF ELEMENTS ON THE LEFT OF i IS 4-2-1 = 1, I.E 3RD ELEMENT
	            SO WE CAN START WITH PREV AS -1 */
	            int right = n-1-i ;
	            int combi = left*right ;	// CONBINATION OF ELEMENTS INCLUDING BOTH LEFT AND RIGHT
	            ans+= curr + left + right + combi ;
	            prevBig = i;
	        }
	    }
	    return ans;
	    
	}
};
