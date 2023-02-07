class Solution {
public:
	// SLIDE THROUGH THE WINDOW AND REMOVE IS SIZE EXCEEDS
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int left =0 , ans=0;
        for (int right = 0; right<fruits.size(); right++){
            mp[fruits[right]]++;
            if (mp.size()>2){
                while (mp.size()>2){
                    mp[fruits[left]]--;
                    if (mp[fruits[left]]==0)
                        mp.erase(fruits[left]) ;
                    left++;
                }
            }
            ans=max(ans,right-left+1) ;
        }
        return ans;
    }
};
