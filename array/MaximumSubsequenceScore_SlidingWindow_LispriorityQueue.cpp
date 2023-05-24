#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int N = nums1.size() ;
        vector<pair<ll,ll> > maxi(N);
        for (int i=0; i<nums1.size(); i++)
            maxi[i] = {nums2[i],nums1[i]} ;
        
        sort(maxi.begin(),maxi.end(),greater< pair<ll,ll> >() ) ;

        ll ans = 0 , r = 0 , sum = 0;
        priority_queue<ll,vector<ll>,greater<ll> > minh;
        for (r=0; r<k; r++){
            sum+=maxi[r].second ;
            minh.push(maxi[r].second) ;
        }
        ans = sum*maxi[r-1].first ;

        while (r<maxi.size()){
            sum-=minh.top(); // Remove the smallest element from the sum
            minh.pop() ;	// The L will be judged by the minheap
            
            sum+=maxi[r].second ;
            minh.push(maxi[r].second) ;
            ans = max(ans,sum*maxi[r].first) ;
            r++;
        }
        return ans;
    }
};
