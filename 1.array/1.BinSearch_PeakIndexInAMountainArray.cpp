/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int N = arr.size();
        if (N==3) return 1;

        int s = 1, e=N-2;
        while (s<=e){
            int mid = s+(e-s)/2;
            int before = arr[mid-1], middle=arr[mid], after=arr[mid+1];
            
            if (before < middle){
                if (middle > after) return mid;
                else s = mid+1;
            } else {
                if (middle > after) e = mid-1;
                else {
                    cout<<"Missed a case";
                    break;
                }
            }
        }

        return -1;
    }
};