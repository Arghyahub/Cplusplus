class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int s = 0 , e = people.size()-1 , ans=0;
        sort(people.begin(),people.end()) ;
        while (s<=e){
            if (s==e){
                ans++;
                break;
            }
            if (people[s]+people[e] <= limit){
                ans++;
                s++;
                e--;
            }
            else{
                ans++;
                e--;
            }
        }
        return ans;
    }
};
