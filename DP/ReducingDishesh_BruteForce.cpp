class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end()) ;
        int n = sat.size() , ans = 0;
        for (int i=0; i<n; i++){
            int temp = 0 ;
            for (int j=0; j<sat.size(); j++)
                temp+=sat[j]*(j+1) ;
            sat.erase(sat.begin()) ;
            ans=max(ans,temp) ;
        }
        return ans;
    }
};
