/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
1312. Minimum Insertion Steps to Make a String Palindrome

Always keep things simple, how you would check pallindrome is the way how you solve this
 */

 class Solution {
     vector<vector<int>> dp;
     int solve(string &s, int i, int j){
         if (i>=j) return 0;
         if (dp[i][j]!=-1) return dp[i][j];
         int ans = INT_MAX;
         if (s[i]==s[j])
             ans = min(ans,solve(s,i+1,j-1));
         else{
             int left = solve(s,i+1,j);
             int right = solve(s,i,j-1);
             ans = min(ans, left==INT_MAX ? left : left+1 );
             ans = min(ans, right==INT_MAX ? right : right + 1);
         }

         return dp[i][j] = ans;
     }
 public:
     int minInsertions(string s) {
         dp.resize(s.size(), vector<int> (s.size(),-1));
         return solve(s,0,s.size()-1);
     }
 };
