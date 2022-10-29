//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){            // STORING THE ANS THEN SUBTRACTING TO GET NUM OF CHICKS BORN SIMPLY WON'T WORK
	    vector<long long> arr(n+1) ;
	    long long int sum=1;
	    arr[0] = 0;
	    arr[1] = 1;
	    
	    for (int i=2; i<=n; i++){
	        arr[i] = sum*2 ;
	        if (i>=7){
	            sum=sum-arr[i-6] ;
	            arr[i] = sum*2;
	        }
	        sum+=arr[i] ;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends