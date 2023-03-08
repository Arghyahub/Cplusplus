// Put max freq characters at alternate positions
// if string is even, maxfreq shouldn't be greater than n/2 , If string is odd maxfreq shouldn't be greater than (n+1)/2

class Solution
{
    public:
    string rearrangeString(string &str)
    {
        int n = str.size() ;
        map<char,int> mp;
        int maxi = 0;
        for (auto ch : str){
            mp[ch]++;
            maxi=max(maxi,mp[ch]) ;
        }
        
        if (n&1 && maxi>(n+1)/2) return "-1" ;
        if (!(n&1) && maxi>n/2) return "-1" ;
        
        string tmp = str;
        multiset<pair<int,char>> maxc;
        for (auto it : mp)
            maxc.insert({it.second,it.first});
        
        int i=0;
        for (auto it=maxc.rbegin(); it!=maxc.rend(); it++ ){
            int frq = (*it).first;
            char ch = (*it).second;
            for (int k=0; k<frq; k++){
                tmp[i] = ch;
                i+=2;
                if (i>=n) i=1;
            }
        }
        
        return tmp;
    }
    
};
