//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    void digitIN(vector<int> &v, long long n){
        while (n){
            int lastdig = n%10;
            v.push_back(lastdig);
            n/=10;
        }
    }
public:
    vector<int> factorial(int N){
        vector<int> v;
        digitIN(v,N);
        N--;
        
        while (N>=2){
            long long carry = 0;
            for (int i=0; i<v.size(); i++){
                int num=v[i];
                long long curr = num*N + carry;
                v[i] = (curr%10) ;
                carry = curr/10;
            }
            if (carry>0)
                digitIN(v,carry) ;
            N--;
        }
        reverse(v.begin(),v.end()) ;
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends