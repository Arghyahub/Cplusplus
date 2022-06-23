// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
        int ctoi(string &A, int n)
        {
            int x = A[n] - 'a' ;
            return x ;
        }
	public:
		string FirstNonRepeating(string A){
		    int arr[26]={0} ;
		    string ans ;
		    queue<char> q ;
		    for (int i=0; i<A.size(); i++)
		    {
		        arr[ctoi(A,i)]++ ;
		        q.push(A[i]) ;
		        
		        while(!q.empty() && arr[q.front()-'a']!=1)
		            q.pop() ;
		        
		        if (q.empty())
		            ans.push_back('#') ;
                else
                    ans.push_back(q.front()) ;
		    }
		    return ans ;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends