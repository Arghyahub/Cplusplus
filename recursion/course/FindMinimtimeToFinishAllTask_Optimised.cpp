class Solution {
    void solve(vector<int>& jobs ,vector<int>& work, int k, int &ans, int i)
    {
        int sum = *max_element(work.begin(),work.end()) ;
        if (i==jobs.size() ){
            if (sum<ans) ans=sum;
            return ;
        }
        if (sum>=ans)
            return;

        for (int j=0; j<k; j++){
            if (j>0 && work[j]==work[j-1])
                continue;
            // Sum the current element in jth index
            work[j] += jobs[i] ;
            solve(jobs,work,k,ans,i+1) ;
            // Subtract
            work[j] -= jobs[i] ;
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if (k==jobs.size()) return *max_element(jobs.begin(),jobs.end()) ;
        if (k==1) return accumulate(jobs.begin(),jobs.end(),0) ;

        vector<int> work(k,0) ;
        int ans = INT_MAX ;
        solve(jobs,work,k,ans,0) ;
        return ans;
    }
};
