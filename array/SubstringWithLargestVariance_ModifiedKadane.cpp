class Solution {
public:
    int largestVariance(string s) {
        vector<int>arr(26);
        for(auto x:s){
           arr[x-'a']++; 
        }
        int ans=0;
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                 if(j==i||arr[i-'a']==0||arr[j-'a']==0)
                            continue;
                for(int k=1;k<=2;k++){
                    int c1=0;
                    int c2=0;
                    for(auto x:s){
                        if(x==i)
                            c1++;
                        if(x==j)
                            c2++;
                        if(c2>c1){
                            c1=0;
                            c2=0;
                        }
                        if(c1>0&&c2>0)
                        ans=max(ans,c1-c2);
                    }
                    reverse(s.begin(),s.end());
                    /*
                    Say cnt1=a , cnt2=b and string is baaa
                    b=>cnt1,cnt2 = 0,1
                    ba=>cnt1,cnt2 = 1,1
                    baa=>.,. = 1,2 => negative , so make them 0
                    baaa=> .,. = 1,0 =>
                    highest we got is 1, but variance should be 2

                    Now if we reverse the string => aaab
                    a=>.,. = 1,0
                    aa=>.,. = 2,0
                    aaa=>.,. = 3,0
                    aaab=>.,. = 3,1 => variance 2, .:. we have to reverse the string
                    */
                }
            }
        }
        return ans;
    }
};
