class Solution {
    bool slope(float s,vector<int> &a, vector<int> &b){
        float f1 = b[1]-a[1] , f2 = b[0] - a[0] ;
        return s==f1/f2 ;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()<=2) return points.size() ;
        int ans = 0, n=points.size();
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                float f1 = points[j][1]-points[i][1] , f2 = points[j][0] - points[i][0] ;
                float s=f1/f2 ;
                int tmp=2;

                for (int k=0; k<n; k++){
                    if (k==i || k==j) continue;
                    if (slope(s,points[j],points[k]))
                        tmp++;
                }
                ans=max(ans,tmp) ;
            }
        }
        return ans;
    }
};
