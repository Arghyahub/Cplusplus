class Solution {
    void merge(vector<int>& nums, int s, int mid, int e){
        int leftLen = mid-s+1, rightLen=e-mid;
        vector<int> left(leftLen), right(rightLen);
        int j=0,k=0;
        for (int i=s; i<=mid; i++) left[j++] = nums[i];
        for (int i=mid+1; i<=e; i++) right[k++] = nums[i];

        j=0;
        k=0;
        while (j<leftLen && k<rightLen){
            if (left[j]<=right[k])
                nums[s++] = left[j++];
            else
                nums[s++] = right[k++];
        }
        while (j<leftLen) 
                nums[s++] = left[j++];
        while (k<rightLen) 
                nums[s++] = right[k++];
    }

    int count(vector<int>& nums, int s, int mid, int e){
        int cnt=0, right=mid+1;
        for (int i=s; i<=mid; i++){
            while (right<=e && nums[i]>2*1LL*nums[right]) right++;
            cnt += right - (mid+1);
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int s, int e){
        if (s>=e) return 0;
        int cnt = 0, mid=s+(e-s)/2;
        cnt+= mergeSort(nums,s,mid);
        cnt+= mergeSort(nums,mid+1,e);
        cnt+= count(nums,s,mid,e);
        merge(nums,s,mid,e);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
