// Take account of all the same numbers appeared before and keep sum and count of them
// Then just solve for prefix and suffix and thats it
#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int N = nums.size() ;
        unordered_map<int,pair<ll,ll>> prevsum;
        unordered_map<int,pair<ll,ll>> nextsum;

        vector<ll> prev(N);
        vector<ll> next(N);

        for (int i=0; i<N; i++){
            if (prevsum.count(nums[i])){
                auto &[sum,frq] = prevsum[nums[i]] ;
                prev[i] = abs( sum - frq*i ) ;

                sum+=i ;
                frq++;
            }
            else{
                prevsum[nums[i]] = {i,1} ;
            }
        }

        for (int i=N-1; i>=0; i--){
            if (nextsum.count(nums[i])){
                auto &[sum,frq] = nextsum[nums[i]] ;
                next[i] = abs( sum - frq*i ) ;

                sum+=i ;
                frq++;
            }
            else{
                nextsum[nums[i]] = {i,1} ;
            }
        }

        for (int i=0; i<N; i++)
            prev[i] += next[i] ;

        return prev ;
    }
};
