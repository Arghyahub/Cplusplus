// when you partion, you are essentially storing the sum of adjacent elements to that of the partion point
// There are better ways of doing this, but this seems more easy to understand
#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int N = weights.size();
        ll mini = weights[0] + weights[N-1] ;
        ll maxi = mini;

        vector< pair<int ,int> > sumInd; // <sum,i> remember to mark i+1

        for (int i=0; i<N-1; i++) {
            sumInd.push_back({ weights[i]+weights[i+1] , i }) ;
        }

        sort(sumInd.begin(),sumInd.end()) ;

        vector<bool> vis(N) ;
        int turn = 0;
        
        for (int i=0; i<sumInd.size() && turn<k-1; i++) {
            auto [sum,ind] = sumInd[i] ;
            // if (vis[ind] || vis[ind+1]) continue;

            mini+= (ll)sum;
            vis[ind] = true;
            vis[ind+1] = true;
            turn++;
        }

        fill(vis.begin(),vis.end(),false) ;
        turn = 0;
        for (int i=sumInd.size()-1; i>=0 && turn<k-1; i--) {
            auto [sum,ind] = sumInd[i] ;
            // if (vis[ind] || vis[ind+1]) continue;

            maxi+= (ll)sum;
            vis[ind] = true;
            vis[ind+1] = true;
            turn++;
        }

        return maxi - mini;
    }
};
