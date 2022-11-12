#include <bits/stdc++.h>
using namespace std;
    // Q Find the sum of all the numbers between the range l and r
    // Here each number is represented by the sum of its distinct prime factors. 
    // each number like 6 has prime factors 2,3 => 2+3=5
class Solution {
  public:
    int sumOfAll(int l, int r){
        vector<int> sieve(r+1,0) ;
        for (int i=2; i<=r; i++){
            if (sieve[i]==0){
                sieve[i] = i;
                
                for (int k=2; i*k<=r; k++){
                    sieve[i*k] += i;
                }
                
            }
        }
        
        int ans=0;
        for (int i=l; i<=r; i++){
            ans+=sieve[i] ;
        }
        return ans;
    }
};