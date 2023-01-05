class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end()) ;
        int l=p[0][1] , r=p[0][1] , mark=1, n=p.size();
        
        
        for (int i=1; i<n; i++){
            l = p[i][0] ;
            r=min(r,p[i][1]);
            if (l>r){
                mark++;
                l=p[i][1] , r = p[i][1] ;
            }
        }
        return mark;
    }
};
