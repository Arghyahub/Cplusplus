class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int N = obs.size() ;
        vector<int> ans(N) ;
        vector<int> sorted ;
        sorted.push_back(-1) ;

        for (int i=0; i<N; i++){
            if (obs[i]>=sorted.back()){
                sorted.push_back(obs[i]) ;
                ans[i] = sorted.size() - 1 ;
            }
            else{
                int ind = (upper_bound(sorted.begin(),sorted.end(),obs[i]) - sorted.begin() );
				// Basically put elements at their correct spot and that will be the longest
                sorted[ind] = obs[i] ;
                ans[i] = ind;
            }
        }
        return ans;
    }
};
