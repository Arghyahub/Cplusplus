/*
Step 1 :- We know total possible Subarrayof length n is (n*(n+1))/2.

Step 1 :- Now,Just think reverse of the problem, i.e find count of total subarray whose value is less than or equal to k. and then subtract this count from our total possible subarray.

Step 3 :- This count can be easily find by considering the total maximum length of subarray in which value is less then or equal to k.
*/

class Solution{
public:
	#define ll long long

	ll countSubarray(int arr[], ll n, int k) {
	    ll ans = n*(n+1)/2 ;
	    ll cnt = 0;
	    
	    for (int i=0; i<n; i++){
	        if (arr[i]<=k)
	            cnt++;
	        else{
	            ans-= (cnt*(cnt+1)/2) ;
	            cnt = 0;
	        }
	    }
	    ans-=(cnt*(cnt+1)/2) ;
	    return ans;
	}
};
