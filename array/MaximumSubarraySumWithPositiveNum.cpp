//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    int s = -1 , e = -1 , tmps = -1 , tmpe = -1, ans1=0 , ans2=0;
	    
	    for (int i=0; i<=n; i++){
	        
	        if (i<n && a[i]>=0){
	            if (tmps==-1) tmps = i;
	            tmpe = i;
	            ans2 += a[i] ;
	        }
	        else {
	            if (ans2 > ans1){
	                ans1 = ans2 ;
	                s = tmps;
	                e = tmpe;
	            }
	            else if (ans2 == ans1 && (e-s < tmpe-tmps) ){
	                s = tmps;
	                e = tmpe;
	            }
	            tmps = i+1;
	            ans2 = 0;
	        }
	    }
	    
	    vector<int> ans ;
	    if (s==-1 || e==-1){
	        ans.push_back(-1) ;
	        return ans;
	    }
	    
	    for (int i=s; i<=e; i++)
	        ans.push_back(a[i]) ;
	        
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends