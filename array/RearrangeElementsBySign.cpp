class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> v(n);
        queue<int> q;
        for (int i=0; i<n; i++)
            if (nums[i]<0)
                q.push(nums[i]) ;
        
        int i=0 , j=0 ;
        while (i<n && j<n){
            if (j&1){
                if (!q.empty()){
                    v[j++] = q.front() ;
                    q.pop() ;
                }
                else // only +ve numbers are left
                    break;
            }
            else{
                while (i<n && nums[i]<0) i++;
                if (i<n)
                    v[j++] = nums[i++] ;
                else    // only -ve numbers left
                    break;
            }
        }
        while (!q.empty())
        {
            v[j++] = q.front() ;
            q.pop() ;
        }
        while (i<n){
            if (nums[i]>=0)
                v[j++] = nums[i] ;
            i++;
        }
        
        return v;
    }
};