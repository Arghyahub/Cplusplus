class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> time(edges.size(),0) ;
        int ans = -1;
        int tm = 1; 	// Specify seperate time for every node, if you start from 0, a confusion arises, if the node is visited now or before
        
        for (int i=0; i<edges.size(); i++){
            if (time[i]) continue;
            int startTime=tm;
            int start=i;
            while (start!=-1 && !time[start]){
                time[start]=tm++ ;
                start = edges[start] ;
            }
            if (start!=-1 && time[start]>=startTime ){	// If curr time is greater than startTime, that is if its visited now, not before
                ans = max(ans, tm - time[start] ) ; 	// Then store the difference between curr time and visited before time
            }
        }
        return ans;
    }
};
