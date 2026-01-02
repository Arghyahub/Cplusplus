/*
https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
 */
class Solution {
    pair<int,int> solve(vector<vector<int>> &mat, int N, int M, int mid) {
        int lesser = 0, exists = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++){
                lesser += mat[i][j] < mid ? 1:0;
                exists += mat[i][j] == mid ? 1:0;
            }
        }
        return {lesser,exists};
    }
  public:
    int median(vector<vector<int>> &mat) {
        int s = 1, e = 2000;
        int N = mat.size(), M = mat[0].size();
        int half = ((N*M)-1)/2;
        while (s<=e){
            int mid = s + (e-s)/2;
            auto [count,exists] = solve(mat,N,M, mid);

            if (count == half){
                if (exists) return mid;
                else s = mid+1;
            }
            else if (count > half)
                e = mid-1;
            else {
                // count < half
                if (count+exists > half) return mid;
                else s = mid + 1;
            }
        }
        return -1;
    }
};
