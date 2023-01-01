class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0, i=0;
        while(i<s.size()){
            if (s[i]-'0' > k) return -1;
            long tmp=0;
            int j;
            for (j=i; j<s.size(); j++){
                if (s[j]-'0' > k) return -1;
                if (tmp*10 + (s[j]-'0') > k)
                    break;
                tmp = tmp*10 + (s[j]-'0') ;
            }
            ans++;
            i=j;
        }
        return ans;
    }
};
