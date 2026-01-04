/*
https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
Do bruteforce, cut the extra computation using heap
*/
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int N = a.size();
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());

        priority_queue<int,vector<int>,greater<int> > minh;

        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                int sum = a[i]+b[j] ;

                if (minh.size() < k) minh.push(sum);
                else {
                    int mini = minh.top();
                    if (mini >= sum) break;
                    else {
                        minh.pop();
                        minh.push(sum);
                    }
                }
            }
        }

        vector<int> ans(k);
        for (int i=k-1; i>=0; i--){
            ans[i] = minh.top() ;
            minh.pop();
        }

        return ans;
    }
};
