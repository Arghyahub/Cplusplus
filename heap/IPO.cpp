//	Select the pair with enouugh capital and get the maximum profit out of maxheap
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxh; // by profit
        int n = profits.size()  ;
        vector<pair<int,int>> zip;
        
        for (int i=0; i<n; i++)
            zip.push_back({capital[i],profits[i]}) ;
        
        sort(zip.begin(),zip.end()) ;
        
        int j=0;
        for (int i=0; i<k; i++){
            while (j<n && zip[j].first<=w)
                maxh.push(zip[j++].second) ;
            if (!maxh.empty()){
                w+=maxh.top() ;
                maxh.pop() ;
            }
        }

        return w;
    }
};
