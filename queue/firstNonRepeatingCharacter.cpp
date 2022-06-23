// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
    int cint(char ch)
    {
        int x = ch - 'a' ;
        return x ;
    }
	public:
		string FirstNonRepeating(string A){
		    string ans ;
		    int alp[26]={0} ;
 		    int prev=0;
		    for (int i=0; i<A.size(); i++)
		    {
		        alp[cint(A[i])]++ ;
		        if ( alp[ cint(A[prev]) ] ==1){ // suitable condition
		            ans.push_back(A[prev]) ;
		        }
		            
		        else {
		            while ( alp[ cint(A[prev]) ] !=1 && prev<=i) // if not
		                prev++ ;                     //pull prev upto the limit
		            
		            if (alp[ cint(A[prev]) ] ==1)// either it has reached the required pos
		            ans.push_back(A[prev]) ; 
    		        else
    		            ans.push_back('#') ;    // or last poisiton is also worthless
		        }
		        
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